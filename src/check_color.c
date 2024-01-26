#include "../include/Cub3d.h"

bool	char_to_int(t_rgb *rgb, char *str, int n)
{
	if (n == 1)
	{
		rgb->r = ft_atoi(str);
		if (rgb->r < 0 || rgb->r > 255)
			return (false);
	}
	else if (n == 2)
	{
		rgb->g = ft_atoi(str);
		if (rgb->g < 0 || rgb->g > 255)
			return (false);
	}
	else if (n == 3)
	{
		rgb->b = ft_atoi(str);
		if (rgb->b < 0 || rgb->b > 255)
			return (false);
	}
	return (true);
}

void	initialize_F_C(t_cub *cub, char c)
{
	if (c == 'F')
		cub->F = malloc(sizeof(t_rgb));
	else if (c == 'C')
		cub->C = malloc(sizeof(t_rgb));
}

bool	rgb_to_int(char *rgb, t_cub *cub, char c)
{
	int		i;
	char	*dest;
	int		n;

	n = 0;
	dest = NULL;
	initialize_F_C(cub, c);
	while (n++ != 3)
	{
		i = 0;
		while (rgb[i] >= '0' && rgb[i] <= '9')
			i++;
		dest = ft_strnjoin(NULL, rgb, i);
		rgb = rgb + (i + 2);
		if (c == 'F' && (char_to_int(cub->F, dest, n) == false))
			return (free(dest), false);
		else if (c == 'C' && (char_to_int(cub->C, dest, n) == false))
			return (free(dest), false);
		free(dest);
	}
	return (true);
}

void	check_format_rgb(char *rgb, t_cub *cub, char *str)
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
			free(str);
			print_error_msg(COLOR_FALSE, cub);
		}
	}
	if (n >= 3)
	{
		free(rgb);
		free(str);
		print_error_msg(COLOR_FALSE, cub);
	}
}

bool	Check_rgb(char *str, t_cub *cub, char c)
{
	int		i;
	char	*rgb;

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
		check_format_rgb(rgb, cub, str);
		if (rgb_to_int(rgb, cub, c) == false)
		{
			free(rgb);
			free(str);
			print_error_msg(COLOR_FALSE, cub);
		}
		return (free(rgb), true);
	}
	return (free(rgb), false);
}

bool	check_for_color(char *str, t_cub *cub, int n)
{
	if (cub->F == NULL && ft_strncmp(str, "F", 1) == 0)
	{
		if (n == 6)
		{
			free(str);
			print_error_msg(COLOR_FALSE, cub);
		}
		if (Check_rgb(str, cub, 'F') == true)
			return (true);
	}
	else if (cub->C == NULL && ft_strncmp(str, "C", 1) == 0)
	{
		if (n == 6)
		{
			free(str);
			print_error_msg(COLOR_FALSE, cub);
		}
		if (Check_rgb(str, cub, 'C') == true)
			return (true);
	}
	return (false);
}
