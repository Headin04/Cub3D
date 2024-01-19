#include "../include/Cub3d.h"

void	check_first_last_line(t_cub *cub)
{
	t_list	*alias;
	int		i;

	alias = cub->map->map_lst;
	i = 0;
	while (alias->content[i] != '\0')
	{
		if (alias->content[i] != ' ' && alias->content[i] != '1')
			print_error_msg(LEAK_IN_WALL, cub);
		i++;
	}
	cub->map->len_max = i;
	while (alias->next != NULL)
		alias = alias->next;
	i = 0;
	while (alias->content[i] != '\0')
	{
		if (alias->content[i] != ' ' && alias->content[i] != '1')
			print_error_msg(LEAK_IN_WALL, cub);
		i++;
	}
	cub->map->map_lst = cub->map->start_map;
}
void	check_left(t_cub *cub)
{
	t_list	*alias;

	alias = cub->map->map_lst;
	while (alias != NULL)
	{
		if (alias->content[0] != ' ' && alias->content[0] != '1')
			print_error_msg(LEAK_IN_WALL, cub);
		alias = alias->next;
	}
	cub->map->map_lst = cub->map->start_map;
}
void	check_right(t_cub *cub)
{
	int		len;
	t_list	*alias;

	alias = cub->map->map_lst;
	while (alias != NULL)
	{
		len = ft_strlen(alias->content);
		if (alias->content[len - 1] != ' ' && alias->content[len - 1] != '1')
			print_error_msg(LEAK_IN_WALL, cub);
		alias = alias->next;
	}
	cub->map->map_lst = cub->map->start_map;
}

void	check_walls(t_cub *cub)
{
	check_first_last_line(cub);
	check_left(cub);
	check_right(cub);
}