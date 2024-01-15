#ifndef CUB3D_H
# define CUB3D_H

# include "../Ft_printf/ft_printf.h"
# include "../Ft_printf/libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define DEFAULT 0
# define WRONG_ARGS 1
# define WRONG_NAME 2
# define PATH_FALSE 3

typedef struct s_map
{
}			t_map;

typedef struct s_cub
{
	t_map	map;
}			t_cub;

bool		print_error_msg(int key);

/*PARSING*/
bool		check_file(int argc, char **argv, t_win *win);
bool		check_arg(int argc);
bool		check_name(char **argv);
bool		check_must(char *str);

#endif