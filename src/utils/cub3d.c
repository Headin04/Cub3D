/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:00:58 by eewu              #+#    #+#             */
/*   Updated: 2024/02/20 15:52:48 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

unsigned long	ft_convert_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	ft_keyinit(t_vars *vars)
{
	vars->up = 0;
	vars->down = 0;
	vars->right = 0;
	vars->left = 0;
	vars->rotate_r = 0;
	vars->rotate_l = 0;
}

void	ft_mlx_start(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_free_mlx(1, vars);
	ft_init_mlx(vars, &vars->cub);
	ft_rayinit(vars);
	mlx_hook(vars->win, 2, 1L << 0, ft_keycode, vars);
	mlx_loop_hook(vars->mlx, &ft_display, vars);
	mlx_hook(vars->win, 3, 1L << 1, ft_keycode_r, vars);
	mlx_hook(vars->win, 17, 1L << 2, mlx_loop_end, vars->mlx);
	mlx_loop(vars->mlx);
	ft_free_mlx(-1, vars);
}
