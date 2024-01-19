#include "../include/Cub3d.h"

void	backtracking(t_cub *cub, int x)
{
	t_list	*alias;

	alias = cub->map->map_lst;
	if (alias->content[x] == '1')
		return ;
	else if (alias->content[x] == '2')
		return ;
	else if (alias->content[x] == cub->map->dir_player)
		alias->content[x] == '2';
	else if (alias->content[x] == '0')
		alias->content == '2';
	else if (alias->content[x] == ' ')
		print_error_msg(LEAK_IN_WALL, cub);
	// backtracking()
}

void	ft_backtracking(cub)
{
	int y;
	int x;
	n = 0;
	i = 0;
	t_list *alias = cub->map->map_lst;
	while (alias != NULL)
	{
		while (alias->content != '\0')
		{
			if (alias->content == '0')
				backtracking(cub, x);
		}
	}
}