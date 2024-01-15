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

bool	check_for_dir(char *str, char *dir)
{
	int			fd;
	static int	i;

	i = 0;
	if (ft_strncmp(str, dir, 5) == 0)
	{
		fd = open(str + 3, O_RDONLY);
		if (fd == -1)
		{
			printf("ici %i\n", i);
			return (print_error_msg(PATH_FALSE));
		}
		close(fd);
		return (true);
	}
	return (false);
}

bool	check_for_textures(char *str, t_cub *cub)
{
	size_t	len;

	len = ft_strlen(str);
	if (check_for_dir(str, "NO ./") == true)
		return (cub->NO = ft_strdup(str + 3), true);
	else if (check_for_dir(str, "SO ./") == true)
		return (cub->SO = ft_strdup(str + 3), true);
	else if (check_for_dir(str, "WE ./") == true)
		return (cub->WE = ft_strdup(str + 3), true);
	else if (check_for_dir(str, "EA ./") == true)
		return (cub->EA = ft_strdup(str + 3), true);
	return (false);
}

bool	check_must(char *str, t_cub *cub)
{
	int fd;
	int n;

	n = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (print_error_msg(DEFAULT));
	str = get_next_line_map(fd);
	while (str != NULL)
	{
		if (check_for_textures(str, cub) == true)
			n++;
		// else if (check_for_color(str, cub) == true)
		// 	n++;
		// else if (n == 5)
		// 	check_for_map(str, cub);
		free(str);
		str = get_next_line_map(fd);
	}
	close(fd);
	return (true);
}