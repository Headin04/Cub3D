/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_rayinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:10:19 by eewu              #+#    #+#             */
/*   Updated: 2024/02/17 11:47:54 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

double	ft_dir(char dir, int n, int x)
{
	if (n == 0)
	{
		if ((dir == 'N' && x == 0) || (dir == 'W' && x == 1))
			return (-1.00);
		else if ((dir == 'S' && x == 0) || (dir == 'E' && x == 1))
			return (1.00);
	}
	else
	{
		if ((dir == 'E' && x == 0) || (dir == 'N' && x == 1))
			return (0.66);
		else if ((dir == 'W' && x == 0) || (dir == 'S' && x == 1))
			return (-0.66);
	}
	return (0.00);
}

void	ft_rayinit(t_vars *vars)
{
	vars->ray.posx = vars->cub.playerx + 0.2;
	vars->ray.posy = vars->cub.playery + 0.2;
	vars->ray.dirx = ft_dir(vars->dir, 0, 1);
	vars->ray.diry = ft_dir(vars->dir, 0, 0);
	vars->ray.planx = ft_dir(vars->dir, 1, 1);
	vars->ray.plany = ft_dir(vars->dir, 1, 0);
}

void	ft_ray_loopinit(t_vars *vars)
{
	t_ray	r;

	r = vars->ray;
	r.hit = 0;
	r.perpwalldist = 0;
	r.camerax = 2 * r.x / (double)vars->sizex - 1;
	r.raydirx = r.dirx + r.planx * r.camerax;
	r.raydiry = r.diry + r.plany * r.camerax;
	if (r.raydiry == 0)
		r.deltadistx = 0;
	else if (r.raydirx == 0)
		r.deltadistx = 1;
	else
		r.deltadistx = sqrt(1 + (pow(r.raydiry, 2) / pow(r.raydirx, 2)));
	if (r.raydirx == 0)
		r.deltadisty = 0;
	else if (r.raydiry == 0)
		r.deltadisty = 1;
	else
		r.deltadisty = sqrt(1 + (pow(r.raydirx, 2) / pow(r.raydiry, 2)));
	r.mapx = r.posx;
	r.mapy = r.posy;
	vars->ray = r;
}
