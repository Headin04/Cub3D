/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:20:11 by eewu              #+#    #+#             */
/*   Updated: 2024/02/16 17:54:47 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = (char *)img->addr + (y * img->llen + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_draw(t_vars *vars, int x, int y)
{
	int	color;

	color = BLACK_C;
	if (y < vars->ray.drawstart || y > vars->ray.drawend)
	{
		if (y < (vars->sizey / 2))
			img_pix_put(&vars->img, x, y, BLUE_C);
		else
			img_pix_put(&vars->img, x, y, GREEN_C);
	}
	else
	{
		if (vars->ray.stepx == -1 && vars->ray.side == 0)
			color = YELLOW_C;
		else if (vars->ray.stepx == 1 && vars->ray.side == 0)
			color = BLUEGRAY_C;
		else if (vars->ray.stepy == -1 && vars->ray.side == 1)
			color = ORANGE_C;
		else if (vars->ray.stepy == 1 && vars->ray.side == 1)
			color = RED_C;
		img_pix_put(&vars->img, x, y, color);
	}
}

int	ft_texture(t_vars *vars, int i, int x, int y)
{
	t_img	wall[4];

	while (i < 4)
	{
		if (vars->wall[i].img)
		{
			wall[i] = vars->wall[i];
			wall[i].addr = (int *)mlx_get_data_addr
				(wall[i].img, &wall[i].bpp, &wall[i].llen, &wall[i].endian);
			while (x < wall[i].w)
			{
				y = 0;
				while (y < wall[i].h)
				{
					vars->img.addr[y * vars->img.llen / 4 + x] = \
						wall[i].addr[y * wall[i].llen / 4 + x];
					y++;
				}
				x++;
			}
			vars->wall[i] = wall[i];
			i++;
		}
	}
	return (0);
}

int	ft_display(t_vars *vars)
{
	if (vars->win == NULL || (!vars->sizey || !vars->sizex))
		return (1);
	ft_raycasting(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.mlx_img, 0, 0);
	ft_dir_updown(vars);
	ft_dir_rightleft(vars);
	ft_rotate(vars);
	return (0);
}
