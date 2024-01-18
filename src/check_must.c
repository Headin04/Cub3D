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
		else if (check_for_color(str, cub, n) == true)
			n++;
		else if (n == 6)
			check_for_map(str, cub);
		free(str);
		str = get_next_line_map(fd);
	}
	close(fd);
}