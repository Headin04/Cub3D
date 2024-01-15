/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:51:11 by eewu              #+#    #+#             */
/*   Updated: 2024/01/15 12:51:11 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3d.h"

void	ft_init_mlx(t_struct *cube, t_vars *vars)
{
	int		sizex;
	int		sizey;
	int		m;

	sizex = 0;
	sizey = 0;

	vars->img = NULL;
	m = mlx_get_screen_size(vars->mlx, &sizex, &sizey);
	if ((cube->map_x * 64) > sizex || (cube->map_y * 64) + 64 > sizey)
		ft_free_mlx(cube, vars, m, 2);
	vars->win = mlx_new_window(vars->mlx, x, y, "So Long");
	if (vars->win == NULL)
		ft_free_mlx(cube, vars, errno, 0);
	ft_init_path(cube);
}
