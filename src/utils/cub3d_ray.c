/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:58:15 by eewu              #+#    #+#             */
/*   Updated: 2024/02/16 17:32:53 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

void	ft_perpwalldist(t_vars *vars)
{
	t_ray	r;

	r = vars->ray;
	if (r.side == 0)
		r.perpwalldist = (r.mapx - r.posx + (1 - r.stepx) / 2) / r.raydirx;
	else
		r.perpwalldist = (r.mapy - r.posy + (1 - r.stepy) / 2) / r.raydiry;
	r.lineheight = vars->sizey / r.perpwalldist;
	r.drawstart = -r.lineheight / 2 + vars->sizey / 2;
	r.drawend = r.lineheight / 2 + vars->sizey / 2;
	if (r.drawstart < 0)
		r.drawstart = 0;
	if (r.drawend >= vars->sizey || r.drawend < 0)
		r.drawend = vars->sizey - 1;
	vars->ray = r;
}


int	ft_curr_map_square(t_vars *vars, int x, int y)
{
	int		i;
	t_list	*map;

	i = 0;
	map = vars->cub.map->start_map;
	while (map && i++ != y)
		map = map->next;
	if (map && ft_strlen(map->content) >= (size_t)x)
	{
		if ((map->content[x] - 48) == 0 || (map->content[x] - 48) == 1)
			return (map->content[x] - 48);
		return (0);
	}
	else
		return (1);
}

// {
// 	int		i;
// 	t_list	*map;

// 	i = 0;
// 	map = vars->cub.map->start_map;
// 	while (map && i++ != y)
// 		map = map->next;
// 	if (map && ft_strlen(map->content) >= (size_t)x)
// 		return (map->content[x]);
// 	else
// 		return (-1);

// }

void	ft_find_wall(t_vars *vars)
{
	t_ray	r;

	r = vars->ray;
	while (r.hit == 0)
	{
		if (r.sidedistx < r.sidedisty)
		{
			r.sidedistx += r.deltadistx;
			r.mapx += r.stepx;
			r.side = 0;
		}
		else
		{
			r.sidedisty += r.deltadisty;
			r.mapy += r.stepy;
			r.side = 1;
		}
		r.hit = ft_curr_map_square(vars, r.mapx, r.mapy);
	}
	vars->ray = r;
}

void	ft_sidestep(t_vars *vars)
{
	t_ray	r;

	r = vars->ray;
	if (r.raydirx < 0)
	{
		r.stepx = -1;
		r.sidedistx = (r.posx - (double)r.mapx) * r.deltadistx;
	}
	else
	{
		r.stepx = 1;
		r.sidedistx = (r.mapx + 1.0 - r.posx) * r.deltadistx;
	}
	if (r.raydiry < 0)
	{
		r.stepy = -1;
		r.sidedisty = (r.posy - (double)r.mapy) * r.deltadisty;
	}
	else
	{
		r.stepy = 1;
		r.sidedisty = (r.mapy + 1.0 - r.posy) * r.deltadisty;
	}
	vars->ray = r;
	ft_find_wall(vars);
}


void	ft_raycasting(t_vars *vars)
{
	int		x;
	int		y;

	x = 0;
	vars->ray.x = 0;
	while (vars->ray.x < vars->sizex)
	{
		ft_ray_loopinit(vars);
		ft_sidestep(vars);
		ft_perpwalldist(vars);
		y = 0;
		while (y < vars->sizey)
		{
			ft_draw(vars, x, y);
			y++;
		}
		vars->ray.x++;
		x++;
	}
}


			// if (y < vars->ray.drawstart || y > vars->ray.drawend)
			// {
			// 	if (y < (vars->sizey / 2))
			// 		img_pix_put(&vars->img, x, y, BLUE_C);
			// 	else
			// 		img_pix_put(&vars->img, x, y, GREEN_C);
			// }