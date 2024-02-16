/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:42:06 by eewu              #+#    #+#             */
/*   Updated: 2024/02/16 17:57:25 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

int	ft_keycode(int keycode, t_vars *vars)
{
	if (keycode == XK_d)
		vars->right = 1;
	else if (keycode == XK_a)
		vars->left = 1;
	else if (keycode == XK_Right)
		vars->rotate_r = 1;
	else if (keycode == XK_Left)
		vars->rotate_l = 1;
	else if (keycode == XK_Up || keycode == XK_w)
		vars->up = 1;
	else if (keycode == XK_Down || keycode == XK_s)
		vars->down = 1;
	else if (keycode == XK_Escape)
		mlx_loop_end(vars->mlx);
	return (0);
}

int	ft_keycode_r(int keycode, t_vars *vars)
{
	if (keycode == XK_d)
		vars->right = 0;
	else if (keycode == XK_a)
		vars->left = 0;
	else if (keycode == XK_Right)
		vars->rotate_r = 0;
	else if (keycode == XK_Left)
		vars->rotate_l = 0;
	else if (keycode == XK_Up || keycode == XK_w)
		vars->up = 0;
	else if (keycode == XK_Down || keycode == XK_s)
		vars->down = 0;
	return (0);
}


void	ft_dir_updown(t_vars *vars)
{
	t_ray	r;

	r = vars->ray;
	if (vars->up == 1)
	{
		if (ft_curr_map_square(vars, r.posx + r.dirx * 0.1, r.posy) != 1)
			r.posx += r.dirx * 0.1;
		if (ft_curr_map_square(vars, r.posx, r.posy + r.diry * 0.1) != 1)
			r.posy += r.diry * 0.1;
	}
	else if (vars->down == 1)
	{
		if (ft_curr_map_square(vars, r.posx - r.dirx * 0.1, r.posy) != 1)
			r.posx -= r.dirx * 0.1;
		if (ft_curr_map_square(vars, r.posx, r.posy - r.diry * 0.1) != 1)
			r.posy -= r.diry * 0.1;
	}
	vars->ray = r;
}

void	ft_dir_rightleft(t_vars *vars)
{
	t_ray	r;

	r = vars->ray;
	if (vars->left == 1)
	{
		if (ft_curr_map_square(vars, r.posx + r.diry * 0.1, r.posy) != 1)
			r.posx += r.diry * 0.1;
		if (ft_curr_map_square(vars, r.posx, r.posy - r.dirx * 0.1) != 1)
			r.posy -= r.dirx * 0.1;
	}
	else if (vars->right == 1)
	{
		if (ft_curr_map_square(vars, r.posx - r.diry * 0.1, r.posy) != 1)
			r.posx -= r.diry * 0.1;
		if (ft_curr_map_square(vars, r.posx, r.posy + r.dirx * 0.1) != 1)
			r.posy += r.dirx * 0.1;
	}
	vars->ray = r;
}

void	ft_rotate(t_vars *vars)
{
	t_ray	r;
	double	planx_tmp;
	double	dirx_tmp;

	r = vars->ray;
	planx_tmp = r.planx;
	dirx_tmp = r.dirx;
	if (vars->rotate_l == 1)
	{
		r.dirx = r.dirx * cos(-0.1 / 2) - r.diry * sin(-0.1 / 2);
		r.diry = dirx_tmp * sin(-0.1 / 2) + r.diry * cos(-0.1 / 2);
		r.planx = r.planx * cos(-0.1 / 2) - r.plany * sin(-0.1 / 2);
		r.plany = planx_tmp * sin(-0.1 / 2) + r.plany * cos(-0.1 / 2);
	}
	else if (vars->rotate_r == 1)
	{
		r.dirx = r.dirx * cos(0.1 / 2) - r.diry * sin(0.1 / 2);
		r.diry = dirx_tmp * sin(0.1 / 2) + r.diry * cos(0.1 / 2);
		r.planx = r.planx * cos(0.1 / 2) - r.plany * sin(0.1 / 2);
		r.plany = planx_tmp * sin(0.1 / 2) + r.plany * cos(0.1 / 2);
	}
	vars->ray = r;
}
