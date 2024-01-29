#include "../include/Cub3d.h"

void	backtracking(t_list *alias, int x, t_cub *cub)
{
	printf("ici\n");
	if (alias->content[x] == '1')
		return ;
	else if (alias->content[x] == '2')
		return ;
	else if (alias->content[x] == cub->map->dir_player)
		alias->content[x] = '2';
	else if (alias->content[x] == '0')
		alias->content[x] = '2';
	else if (alias->content[x] == ' ')
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
		// printf("ici\n");
		x = 0;
		while (alias->content[x] != '\0')
		{
			printf("content == %c\n", alias->content[x]);
			if (alias->content[x] == '0')
				backtracking(alias, x, cub);
			x++;
		}
		alias = alias->next;
	}
}
