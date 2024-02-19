/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:54:27 by eewu              #+#    #+#             */
/*   Updated: 2024/02/05 12:38:29 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3d.h"

void	initialize_f_c(t_cub *cub, char c)
{
	if (c == 'F')
		cub->f = malloc(sizeof(t_rgb));
	else if (c == 'C')
		cub->c = malloc(sizeof(t_rgb));
}

void	backtracking(t_list *alias, size_t x, t_cub *cub)
{
	// printf("y = %s\n", alias->content);
	// printf("x= %zu\n", x);
	if (x > ft_strlen(alias->content) - 1)
		x = ft_strlen(alias->content);
	if (alias->content[x] == '1')
		return ;
	else if (alias->content[x] == '2')
		return ;
	else if (alias->content[x] == cub->map->dir_player)
		alias->content[x] = '2';
	else if (alias->content[x] == '0')
		alias->content[x] = '2';
	else if (alias->content[x] == ' ' || alias->content[x] == '\0')
		print_error_msg(LEAK_IN_WALL, cub);
	backtracking(alias, x + 1, cub);
	backtracking(alias, x - 1, cub);
	backtracking(alias->next, x, cub);
	backtracking(get_previous(cub->map->start_map_cloned, alias), x, cub);
}

void	ft_backtracking(t_cub *cub)
{
	int		x;
	t_list	*alias;

	x = 0;
	cub->map->map_cloned = cub->map->start_map_cloned;
	alias = cub->map->map_cloned;
	while (alias != NULL)
	{
		x = 0;
		while (alias->content[x] != '\0')
		{
			if (alias->content[x] == '0')
				backtracking(alias, x, cub);
			x++;
		}
		alias = alias->next;
	}
}

void	free_check_format_rgb(char *rgb, char *str, t_cub *cub)
{
	free(rgb);
	free(str);
	print_error_msg(COLOR_FALSE, cub);
}
