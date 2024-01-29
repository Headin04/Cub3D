/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:19:14 by eewu              #+#    #+#             */
/*   Updated: 2024/01/23 12:04:10 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
	return ;
}

void	ft_free_exit(int i, t_vars *vars)
{
	ft_free_mlx(vars);
	if (i == 0)
		exit (EXIT_FAILURE);
	else
		exit (EXIT_SUCCESS);
}

void	ft_free_mlx(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (vars->wall[i].img)
			mlx_destroy_image(vars->mlx, vars->wall[i].img);
		i++;
	}
	if (vars->img.mlx_img)
		mlx_destroy_image(vars->mlx, vars->img.mlx_img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}
