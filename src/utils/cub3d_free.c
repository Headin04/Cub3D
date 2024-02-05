/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:19:14 by eewu              #+#    #+#             */
/*   Updated: 2024/02/05 11:35:41 by eewu             ###   ########.fr       */
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

void	ft_free_mlx(int error, t_vars *vars)
{
	int	i;

	i = 0;
	if (error > 0)
	{
		free_cub(&vars->cub);
		exit (EXIT_FAILURE);
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
}
