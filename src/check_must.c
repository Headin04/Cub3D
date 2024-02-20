/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_must.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:59 by eewu              #+#    #+#             */
/*   Updated: 2024/02/19 11:49:05 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3d.h"

char	*get_next_line_map(int fd)
{
	char	*str;
	size_t	len;

	str = get_next_line(fd);
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

t_list	*cpy_lst(t_list *lst)
{
	t_list	*current;

	current = NULL;
	while (lst != NULL)
	{
		ft_lstadd_back(&current, ft_lstnew(ft_strnjoin(NULL, lst->content,
					ft_strlen(lst->content))));
		lst = lst->next;
	}
	return (current);
}

void	check_must(char *str, t_cub *cub)
{
	int	fd;
	int	n;

	n = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		print_error_msg(DEFAULT, cub);
	str = get_next_line_map(fd);
	if (!str)
		exit(1);
	while (str != NULL)
	{
		if (check_for_textures(str, cub) == true)
			n++;
		else if (check_for_color(str, cub, n) == true)
			n++;
		else if (n == 6)
			check_for_map(str, cub);
		free(str);
		str = get_next_line_map(fd);
	}
	close(fd);
	cub->map->map_cloned = cpy_lst(cub->map->map_lst);
	cub->map->start_map_cloned = cub->map->map_cloned;
	check_map(cub);
}
