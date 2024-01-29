#include "../include/Cub3d.h"

void	my_open(char *str, t_cub *cub)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free(str);
		print_error_msg(PATH_FALSE, cub);
	}
	close(fd);
}

bool	check_for_dir(char *str, char *dir, t_cub *cub)
{
	int	i;

	i = 2;
	if (cub->EA != NULL && cub->NO != NULL && cub->SO != NULL
		&& cub->WE != NULL)
	{
		free(str);
		print_error_msg(PATH_FALSE, cub);
	}
	if (ft_strncmp(str, dir, 2) == 0)
	{
		if (str[i] != ' ')
		{
			free(str);
			print_error_msg(PATH_FALSE, cub);
		}
		while (str[i] == ' ')
			i++;
		if (i != 2 && ft_strncmp(str + i, "./", 2))
			my_open(str + 3, cub);
		return (true);
	}
	return (false);
}

bool	check_for_textures(char *str, t_cub *cub)
{
	if (cub->NO == NULL && check_for_dir(str, "NO", cub) == true)
		return (cub->NO = ft_strdup(str + 3), true);
	else if (cub->SO == NULL && check_for_dir(str, "SO", cub) == true)
		return (cub->SO = ft_strdup(str + 3), true);
	else if (cub->WE == NULL && check_for_dir(str, "WE", cub) == true)
		return (cub->WE = ft_strdup(str + 3), true);
	else if (cub->EA == NULL && check_for_dir(str, "EA", cub) == true)
		return (cub->EA = ft_strdup(str + 3), true);
	return (false);
}