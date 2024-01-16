#include "../include/Cub3d.h"

void	print_error_msg(int key, t_cub *cub)
{
	if (key == DEFAULT)
		perror("ERROR");
	if (key == WRONG_ARGS)
		printf("ERROR: Not enough or too much arguments\n");
	if (key == WRONG_NAME)
		printf("ERROR: Wrong name of file\n");
	if (key == PATH_FALSE)
		printf("ERROR: One of the texture's path is false\n");
	if (key == COLOR_FALSE)
		printf("ERROR: One of the Color is false\n");
	free_cub(cub);
	exit(1);
}

void	check_name(char **argv, t_cub *cub)
{
	char	*str;

	str = ft_strrchr(argv[1], '.');
	if (str == NULL)
		print_error_msg(WRONG_NAME, cub);
	else if (ft_strncmp(str, ".cub", 4) != 0)
		print_error_msg(WRONG_NAME, cub);
}

void	check_arg(int argc, t_cub *cub)
{
	if (argc != 2)
		print_error_msg(WRONG_ARGS, cub);
}

void	check_file(int argc, char **argv, t_cub *cub)
{
	check_arg(argc, cub);
	check_name(argv, cub);
	check_must(argv[1], cub);
}

void	initialize(t_cub *cub)
{
	cub->EA = NULL;
	cub->NO = NULL;
	cub->SO = NULL;
	cub->WE = NULL;
	cub->F = NULL;
	cub->C = NULL;
}

// void	free_rgb(t_cub *cub)
// {
// 	if (cub->F != NULL)
// 	{
// 		free(cub->F->r);
// 		free(cub->F->g);
// 		free(cub->F->b);
// 	}
// 	if (cub->C != NULL)
// 	{
// 		free(cub->C.r);
// 		free(cub->C.g);
// 		free(cub->C.b);
// 	}
// }

void	free_cub(t_cub *cub)
{
	if (cub->EA != NULL)
		free(cub->EA);
	if (cub->NO != NULL)
		free(cub->NO);
	if (cub->SO != NULL)
		free(cub->SO);
	if (cub->WE != NULL)
		free(cub->WE);
	free_rgb(cub);
}

int	main(int argc, char **argv)
{
	t_cub cub;
	initialize(&cub);
	check_file(argc, argv, &cub);
	free_cub(&cub);
	return (0);
}