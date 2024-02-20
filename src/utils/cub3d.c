/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:00:58 by eewu              #+#    #+#             */
/*   Updated: 2024/02/20 15:57:11 by eewu             ###   ########.fr       */
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

int	ft_mouse_event(int x, int y, t_vars *vars)
{
	t_ray		r;
	double		planx_tmp;
	double		dirx_tmp;
	static int	prev_x;

	(void)y;
	r = vars->ray;
	planx_tmp = r.planx;
	dirx_tmp = r.dirx;
	double delta = (x - prev_x) * 0.003; // calcule delta souris
	r.dirx = r.dirx * cos(delta) - r.diry * sin(delta);
	r.diry = dirx_tmp * sin(delta) + r.diry * cos(delta);
	r.planx = r.planx * cos(delta) - r.plany * sin(delta);
	r.plany = planx_tmp * sin(delta) + r.plany * cos(delta);
	vars->ray = r;
	prev_x = x;
	return (0);
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
	mlx_hook(vars->win, 06, 1L << 6, ft_mouse_event, vars);
	mlx_hook(vars->win, 17, 1L << 2, mlx_loop_end, vars->mlx);
	mlx_loop(vars->mlx);
	ft_free_mlx(-1, vars);
}
