#include "Cub3d.h"

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

bool	check_for_dir(char *str, t_cub *cub, char *dir)
{
	int	fd;

	if (ft_strncmp(str, dir, 5) == 0)
	{
		fd = open(str + 3, O_RDWR);
		if (fd == -1)
			return (print_error_msg(PATH_FALSE));
	}
}

bool	check_for_textures(char *str.t_cub *cub)
{
	size_t	len;

	len = ft_strlen(str);
	if (check_for_dir(char *str, t_cub *cub, "NO ./") == true)
		return (true);
	if (check_for_dir(char *str, t_cub *cub, "SO ./") == true)
}

bool	check_must(char *str, t_cub *cub)
{
	int fd;

	fd = open(str, O_RDWR);
	if (fd == -1)
		return (print_error_msg(DEFAULT));
	while (str = get_next_line_map(fd) != NULL)
	{
		check_for_textures(str, cub);
	}
	close(fd);
	return (true);
}