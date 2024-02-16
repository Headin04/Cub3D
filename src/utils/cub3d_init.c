/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:51:11 by eewu              #+#    #+#             */
/*   Updated: 2024/02/16 16:54:52 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

static void	ft_init_texture(t_vars *vars, t_cub *cub)
{
	int		i;
	t_img	wall[4];

	i = 0;
	ft_memset(vars->wall, 0, sizeof(t_img) * 4);
	vars->wall[0].path = cub->no;
	vars->wall[1].path = cub->so;
	vars->wall[2].path = cub->ea;
	vars->wall[3].path = cub->we;
	while (i < 4)
	{
		wall[i] = vars->wall[i];
		wall[i].img = mlx_xpm_file_to_image \
			(vars->mlx, wall[i].path, &wall[i].h, &wall[i].w);
		vars->wall[i] = wall[i];
		if (!wall[i].img)
			ft_free_mlx(0, vars);
		i++;
	}
}

static void	ft_keyinit(t_vars *vars)
{
	vars->up = 0;
	vars->down = 0;
	vars->right = 0;
	vars->left = 0;
	vars->rotate_r = 0;
	vars->rotate_l = 0;
}

void	ft_init_mlx(t_vars *vars, t_cub *cub)
{
	t_img	img;

	mlx_get_screen_size(vars->mlx, &vars->sizex, &vars->sizey);
	vars->sizey -= 69;
	vars->win = mlx_new_window(vars->mlx, vars->sizex, vars->sizey, "Cub3D");
	if (vars->win == NULL)
		ft_free_mlx(0, vars);
	img.mlx_img = mlx_new_image(vars->mlx, vars->sizex, vars->sizey);
	if (img.mlx_img == NULL)
		ft_free_mlx(0, vars);
	img.addr = (int *)mlx_get_data_addr(img.mlx_img, &img.bpp, &img.llen,
			&img.endian);
	if (img.addr == NULL)
		ft_free_mlx(0, vars);
	vars->img = img;
	vars->dir = cub->map->dir_player;
	vars->rx = 0;
	ft_init_texture(vars, cub);
	ft_keyinit(vars);
}
