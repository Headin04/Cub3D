#include "../include/Cub3d.h"

// void	char_to_int(t_rgb *rgb, char *str)
// {
// 	if (rgb)
// }

void	rgb_to_int(char *rgb, t_cub *cub, char c)
{
	int		i;
	char	*dest;
	int		n;

	n = 0;
	dest = NULL;
	if (c == 'F')
		cub->F = malloc(sizeof(t_rgb));
	else if (c == 'C')
		cub->C = malloc(sizeof(t_rgb));
	while (n != 3)
	{
		i = 0;
		while (rgb[i] >= '0' && rgb[i] <= '9')
			i++;
		dest = ft_strnjoin(NULL, rgb, i);
		rgb = rgb + (i + 2);
		n++;
		if (c == 'F')
			char_to_int(cub->F, dest);
		if (c == 'C')
			char_to_int(cub->C, dest);
		printf("dest = %s\n", dest);
		free(dest);
	}
}

void	check_format_rgb(char *rgb, t_cub *cub)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (rgb[i] != '\0' && n < 3)
	{
		n++;
		while (rgb[i] >= '0' && rgb[i] <= '9')
			i++;
		if (rgb[i] == ',' && rgb[i + 1] == ' ')
			i = i + 2;
		else if (rgb[i] == '\0')
			return ;
		else
		{
			free(rgb);
			print_error_msg(COLOR_FALSE, cub);
		}
	}
	if (n >= 3)
		print_error_msg(COLOR_FALSE, cub);
}

bool	Check_rgb(char *str, t_cub *cub, char c)
{
	int		i;
	char	*rgb;

	(void)c;
	i = 1;
	rgb = NULL;
	if (str[i] != ' ')
	{
		free(str);
		print_error_msg(COLOR_FALSE, cub);
	}
	while (str[i] == ' ')
		i++;
	if (i != 1)
	{
		rgb = ft_strdup(str + i);
		check_format_rgb(rgb, cub);
		rgb_to_int(rgb, cub, c);
	}
	free(rgb);
	return (false);
}

bool	check_for_color(char *str, t_cub *cub)
{
	size_t len;

	len = ft_strlen(str);
	printf("ici\n");
	if (cub->F == NULL && ft_strncmp(str, "F", 1) == 0)
	{
		printf("oi\n");
		if (Check_rgb(str, cub, 'F') == true)
			return (true);
	}
	else if (cub->C == NULL && ft_strncmp(str, "C", 1) == 0)
	{
		printf("ppi\n");
		if (Check_rgb(str, cub, 'C') == true)
			return (true);
	}
	return (false);
}