/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:35:50 by eewu              #+#    #+#             */
/*   Updated: 2024/01/29 15:14:24 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (key == WRONG_LETTERS)
		printf("ERROR: The map contain wrong caracters\n");
	if (key == LEAK_IN_WALL)
		printf("ERROR: There is a leak\n");
	if (key == DOUBLE_MAP)
		printf("ERROR: The file contain two maps \n");
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
	cub->map = malloc(sizeof(t_map));
	cub->map->map_lst = NULL;
	cub->map->map_cloned = NULL;
	cub->map->dir_player = 0;
}

 int	main(int argc, char **argv)
{
	t_cub cub;
	initialize(&cub);
	check_file(argc, argv, &cub);
	cub.map->map_cloned = cub.map->start_map_cloned;
	// ft_init (&cub, ac, av);
	ft_mlx_start(&cub);
	// while (cub.map->map_cloned != NULL)
	// {
	// 	printf("map == %s\n", cub.map->map_cloned->content);
	// 	cub.map->map_cloned = cub.map->map_cloned->next;
	// }
	free_cub(&cub);
	return (0);
}
