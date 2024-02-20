/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:20:11 by eewu              #+#    #+#             */
/*   Updated: 2024/02/20 15:34:04 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

static	int	ft_texx(t_vars *vars, int texx, int texn)
{
	if (vars->ray.side == 0 && vars->ray.raydirx < 0)
		texx = vars->wall[texn].w - texx - 1;
	if (vars->ray.side == 0 && vars->ray.raydirx >= 0)
		texx = texx - vars->wall[texn].w - 1;
	if (vars->ray.side == 1 && vars->ray.raydiry >= 0)
		texx = vars->wall[texn].w - texx - 1;
	return (texx);
}

void	ft_test_texture(t_vars *vars, int texn, int y)
{
	int		texx;
	int		texy;
	double	step;

	if (vars->ray.side == 0)
		vars->wlx = vars->ray.posy + vars->ray.perpwalldist * vars->ray.raydiry;
	else
		vars->wlx = vars->ray.posx + vars->ray.perpwalldist * vars->ray.raydirx;
	vars->wlx -= floor((vars->wlx));
	step = 1.0 * vars->wall[0].h / vars->ray.lineheight;
	texx = (int)(vars->wlx * (double)vars->wall[texn].w);
	texx = ft_texx(vars, texx, texn);
	vars->texpos = \
	(vars->ray.drawstart - vars->sizey / 2 + vars->ray.lineheight / 2) * step;
	while (++y <= vars->ray.drawend)
	{
		texy = (int)vars->texpos & (vars->wall[texn].h - 1);
		vars->texpos += step;
		if (y < (vars->sizey - 1) && vars->ray.x < (vars->sizex - 1))
			vars->img.addr[y * vars->img.llen / 4 + vars->ray.x] = \
			vars->wall[texn].addr[texy * vars->wall[texn].llen / 4 + texx];
	}
}

void	ft_put_in_buff(t_vars *vars, int y)
{
	while (++y < vars->sizey)
	{
		if (y < vars->ray.drawstart || y > vars->ray.drawend)
		{
			if (y < (vars->sizey / 2))
				vars->img.addr[y * vars->img.llen / 4 + vars->ray.x] = \
					vars->ceiling;
			else
				vars->img.addr[y * vars->img.llen / 4 + vars->ray.x] = \
					vars->floor;
		}
		else
		{
			if (vars->ray.side == 0 && vars->ray.raydirx < 0)
				ft_test_texture(vars, 0, vars->ray.drawstart - 1);
			if (vars->ray.side == 0 && vars->ray.raydirx >= 0)
				ft_test_texture(vars, 1, vars->ray.drawstart - 1);
			if (vars->ray.side == 1 && vars->ray.raydiry < 0)
				ft_test_texture(vars, 2, vars->ray.drawstart - 1);
			if (vars->ray.side == 1 && vars->ray.raydiry >= 0)
				ft_test_texture(vars, 3, vars->ray.drawstart - 1);
		}
	}
}

int	ft_display(t_vars *vars)
{
	int	i;

	i = -1;
	if (vars->win == NULL || (!vars->sizey || !vars->sizex))
		return (1);
	ft_raycasting(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.mlx_img, 0, 0);
	ft_dir_updown(vars);
	ft_dir_rightleft(vars);
	ft_rotate(vars);
	return (0);
}
