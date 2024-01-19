/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:19:14 by eewu              #+#    #+#             */
/*   Updated: 2024/01/15 13:24:57 by eewu             ###   ########.fr       */
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
	if (cub->F != NULL)
		free(cub->F);
	if (cub->C != NULL)
		free(cub->C);
}

void	free_cub(t_cub *cub)
{
	if (cub->EA != NULL)
		free(cub->EA);
	if (cub->NO != NULL)
		free(cub->NO);
	if (cub->SO != NULL)
		free(cub->SO);
	if (cub->WE != NULL)
		free(cub->WE);
	free_rgb(cub);
	cub->map->map_lst = cub->map->start_map;
	free_map(cub->map->map_lst);
	free(cub->map);
}
