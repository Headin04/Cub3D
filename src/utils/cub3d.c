/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:00:58 by eewu              #+#    #+#             */
/*   Updated: 2024/01/29 15:32:34 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

static char	**ft_map(void)
{
	char	**map;

	map = ft_split("1111111111111111 \
					1000000000000001 \
					1000111111000001 \
					1000100000000001 \
					1000100000000001 \
					1000100000000001 \
					1000000000000001 \
					1111111111111111", ' ');
	return (map);
}


static void	img_pix_put(t_img *img, int x, int y, int color)
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

static	int	ft_background(t_vars *vars)
{
	int		x;
	int		y;
	int		red_color;
	int		green_color;

	x = 0;
	red_color = 0x0000FF;
	green_color = 0xFF00;
	while (x < vars->sizex)
	{
		y = 0;
		while (y < vars->sizey)
		{
			if (y < (vars->sizey / 2))
				img_pix_put(&vars->img, x, y, red_color);
			else
				img_pix_put(&vars->img, x, y, green_color);
			y++;
		}
		x++;
	}
	return (0);
}

static	int	ft_texture(t_vars *vars, int i, int x, int y)
{
	t_img	wall[4];

	while (i < 4)
	{
		if (vars->wall[i].img)
		{
			wall[i] = vars->wall[i];
			wall[i].addr = (int *)mlx_get_data_addr(wall[i].img,
					&wall[i].bpp, &wall[i].llen, &wall[i].endian);
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

static	void	ft_walls(t_vars *vars)
{
	ft_raycasting(vars);
	ft_free_split(ft_map());
}

static	int	ft_display(t_vars *vars)
{
	if (vars->win == NULL || (!vars->sizey || !vars->sizey))
		return (1);
	ft_background(vars);
	ft_walls(vars);
	ft_texture(vars, 0, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.mlx_img, 0, 0);
	return (0);
}

void	ft_mlx_start(t_cub *cub)
{
	t_vars	vars;

	(void)cub;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		ft_free_exit(printf("Erreur xpm\n"), &vars);
	ft_init_mlx(&vars);

	mlx_loop_hook(vars.mlx, &ft_display, &vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_keycode, &vars);
	mlx_hook(vars.win, 17, 1L << 2, mlx_loop_end, vars.mlx);
	mlx_loop(vars.mlx);
	ft_free_mlx(&vars);
}
