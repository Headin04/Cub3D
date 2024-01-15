#include "../include/Cub3d.h"

bool	print_error_msg(int key)
{
	if (key == DEFAULT)
		perror("ERROR");
	if (key == WRONG_ARGS)
		printf("ERROR: Not enough or too much arguments\n");
	if (key == WRONG_NAME)
		printf("ERROR: Wrong name of file\n");
	if (key == PATH_FALSE)
		printf("ERROR: One of the texture's path is false\n");
	return (false);
}
bool	check_name(char **argv)
{
	char	*str;

	str = ft_strrchr(argv[1], '.');
	if (str == NULL)
		return (print_error_msg(2));
	else if (ft_strncmp(str, ".cub", 4) != 0)
		return (print_error_msg(WRONG_NAME));
	return (true);
}

bool	check_arg(int argc)
{
	if (argc != 2)
		return (print_error_msg(WRONG_ARGS));
	return (true);
}

bool	check_file(int argc, char **argv, t_cub *cub)
{
	if (check_arg(argc) == false)
		return (false);
	if (check_name(argv) == false)
		return (false);
	if (check_must(argv[1], cub) == false)
		return (false);
	return (true);
}

int	main(void)
{
	t_cub cub;
	check_file(argc, argv, &cub);
	return (0);
}