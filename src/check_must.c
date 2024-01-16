#include "../include/Cub3d.h"

char	*get_next_line_map(int fd)
{
	char	*str;
	int		i;
	size_t	len;

	i = 0;
	str = get_next_line(fd);
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}

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
	size_t	len;

	len = ft_strlen(str);
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

void	check_must(char *str, t_cub *cub)
{
	int fd;
	int n;

	n = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		print_error_msg(DEFAULT, cub);
	str = get_next_line_map(fd);
	while (str != NULL)
	{
		if (check_for_textures(str, cub) == true)
			n++;
		else if (check_for_color(str, cub) == true)
			n++;
		// else if (n == 5)
		// 	check_for_map(str, cub);
		free(str);
		str = get_next_line_map(fd);
	}
	close(fd);
}