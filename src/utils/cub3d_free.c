/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:19:14 by eewu              #+#    #+#             */
/*   Updated: 2024/02/05 12:38:03 by eewu             ###   ########.fr       */
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

void	free_map(t_list *lst)
{
	t_list	*list;

	list = NULL;
	while (lst != NULL)
	{
		list = lst->next;
		free(lst->content);
		free(lst);
		lst = list;
	}
	free(lst);
}

void	free_rgb(t_cub *cub)
{
	if (cub->f != NULL)
		free(cub->f);
	if (cub->c != NULL)
		free(cub->c);
}

void	free_cub(t_cub *cub)
{
	if (cub->fd)
		close(cub->fd);
	if (cub->ea != NULL)
		free(cub->ea);
	if (cub->no != NULL)
		free(cub->no);
	if (cub->so != NULL)
		free(cub->so);
	if (cub->we != NULL)
		free(cub->we);
	free_rgb(cub);
	if (cub->map->map_lst != NULL)
		cub->map->map_lst = cub->map->start_map;
	free_map(cub->map->map_lst);
	if (cub->map->map_cloned != NULL)
		cub->map->map_cloned = cub->map->start_map_cloned;
	free_map(cub->map->map_cloned);
	free(cub->map);
}

void	ft_free_mlx(int error, t_vars *vars)
{
	int	i;

	i = 0;
	if (error > 0)
	{
		free_cub(&vars->cub);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (i < 4)
		{
			if (vars->wall[i].img)
				mlx_destroy_image(vars->mlx, vars->wall[i].img);
			i++;
		}
	}
	if (vars->img.mlx_img)
		mlx_destroy_image(vars->mlx, vars->img.mlx_img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_cub(&vars->cub);
	exit(EXIT_FAILURE);
}
