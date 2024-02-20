/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:54:14 by eewu              #+#    #+#             */
/*   Updated: 2024/02/19 11:41:58 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3d.h"

void	check_letters(t_list *alias, int i, t_cub *cub)
{
	if (alias->content[i] == 'N' && cub->map->dir_player == 0)
		cub->map->dir_player = 'N';
	else if (alias->content[i] == 'S' && cub->map->dir_player == 0)
		cub->map->dir_player = 'S';
	else if (alias->content[i] == 'E' && cub->map->dir_player == 0)
		cub->map->dir_player = 'E';
	else if (alias->content[i] == 'W' && cub->map->dir_player == 0)
		cub->map->dir_player = 'W';
	if (cub->playerx == -1 && cub->playery == -1 && cub->map->dir_player != 0)
	{
		cub->playerx = i;
		cub->playery = get_current_node_index(cub->map->start_map, alias);
	}
	else if (alias->content[i] != '1' && alias->content[i] != '0'
		&& alias->content[i] != ' ')
		print_error_msg(WRONG_LETTERS, cub);
}

void	check_characters(t_cub *cub)
{
	int		i;
	t_list	*alias;

	i = 0;
	cub->map->map_lst = cub->map->start_map;
	alias = cub->map->map_lst;
	while (alias != NULL)
	{
		i = 0;
		while (alias->content[i] == ' ')
			i++;
		while (alias->content[i] != '\0')
		{
			check_letters(alias, i, cub);
			while (alias->content[i] == ' ')
				i++;
			if (alias->content[i] != '\0')
				i++;
		}
		alias = alias->next;
	}
	cub->map->map_line = i;
	cub->map->map_lst = cub->map->start_map;
}

void	check_map(t_cub *cub)
{
	check_characters(cub);
	if (cub->map->dir_player == 0)
		print_error_msg(WRONG_LETTERS, cub);
	check_walls(cub);
	ft_backtracking(cub);
}

bool	skip_space_in_map(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0' && cub->map->map_lst == NULL)
			return (false);
		else if (str[i] == '\0' && cub->map->map_lst != NULL)
		{
			free(str);
			print_error_msg(LEAK_IN_WALL, cub);
		}
	}
	return (true);
}

void	check_for_map(char *str, t_cub *cub)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = NULL;
	if (str[i] == '\0' && cub->map->map_lst != NULL)
	{
		free(str);
		print_error_msg(DOUBLE_MAP, cub);
	}
	else if (str[i] == '\0')
		return ;
	if (skip_space_in_map(str, cub) == false)
		return ;
	if (cub->map->map_lst == NULL)
	{
		cub->map->map_lst = ft_lstnew(ft_strnjoin(NULL, str, ft_strlen(str)));
		cub->map->start_map = cub->map->map_lst;
	}
	else
	{
		tmp = ft_lstnew(ft_strnjoin(NULL, str, ft_strlen(str)));
		ft_lstadd_back(&cub->map->map_lst, tmp);
	}
}
