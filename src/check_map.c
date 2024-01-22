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
	else if (alias->content[i] != '1' && alias->content[i] != '0'
		&& alias->content[i] != ' ')
	{
		printf("ici\n");
		print_error_msg(WRONG_LETTERS, cub);
	}
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

void	check_for_map(char *str, t_cub *cub)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = NULL;
	if (str[i] == '\0')
		return ;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			return ;
	}
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
