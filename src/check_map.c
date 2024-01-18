#include "../include/Cub3d.h"

void	check_for_map(char *str, t_cub *cub)
{
	int i;
	t_list *tmp;
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
	if (cub->map == NULL)
	{
		cub->map = ft_lstnew(str);
		cub->start_map = cub->map;
	}
	else
	{
		tmp = ft_lstnew(str);
		ft_lstadd_back(&cub->map, tmp);
	}
}