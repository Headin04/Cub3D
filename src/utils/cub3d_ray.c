/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:58:15 by eewu              #+#    #+#             */
/*   Updated: 2024/01/29 14:38:01 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

void	ft_rayinit(t_vars *vars)
{
	vars->ray.x = 0;
	vars->ray.posx = 10;
	vars->ray.posy = 2;
	vars->ray.dirx = -1;
	vars->ray.dirx = 0;
	vars->ray.planx = 0;
	vars->ray.plany = 0.66;
}

	// vars->ray.dirx = vars->n + vars->s;
	// vars->ray.dirx = vars->w + vars->e;
	// vars->ray.planx = vars->e + vars->w;
	// vars->ray.plany = vars->n + vars->s;

// 	dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
// 	diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
// 	planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
// 	plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)

void	ft_ray_loopinit(t_vars *vars)
{
	t_ray	r;

	r = vars->ray;
	r.hit = 0;
	r.perpwalldist = 0;
	r.camerax = 2 * r.x / (double)vars->sizex - 1;
	r.raydirx = r.dirx + r.planx * r.camerax;
	r.raydiry = r.diry + r.plany * r.camerax;
	r.mapx = r.posx;
	r.mapy = r.posy;
	vars->ray = r;
}


void	ft_raycasting(t_vars *vars)
{
	ft_rayinit(vars);
	while (vars->ray.x < vars->sizex)
	{
		ft_ray_loopinit(vars);
		vars->ray.x++;
		printf("coucou\n");
	}

}
