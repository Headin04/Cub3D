/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:35:50 by eewu              #+#    #+#             */
/*   Updated: 2024/01/22 13:27:08 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3d.h"

// bool	print_error_msg(int key)
// {
// 	if (key == WRONG_ARGS)
// 		printf("Error\nNot enough or too much arguments\n");
// 	if (key == WRONG_NAME)
// 		printf("Error\nWrong name of file\n");
// 	return (false);
// }
// bool	check_name(char **argv)
// {
// 	char	*str;

// 	str = ft_strrchr(argv[1], '.');
// 	if (str == NULL)
// 		return (print_error_msg(2));
// 	else if (ft_strncmp(str, ".cub", 4) != 0)
// 		return (print_error_msg(2));
// 	return (true);
// }

// bool	check_arg(int argc)
// {
// 	if (argc != 2)
// 		return (print_error_msg(WRONG_ARGS));
// 	return (true);
// }

// bool	check_file(int argc, char **argv, t_win *win)
// {
// 	if (check_arg(argc) == false)
// 		return (false);
// 	if (check_name(argv) == false)
// 		return (false);
// 	if (check_must(argv[1]) == false)
// 		return (false);
// }

// int	main()
// {
// 	// t_win win;
// 	// check_file(argc, argv, &win);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_struct	cub;

	ft_init (&cub, ac, av);
	ft_mlx_start(&cub);
	return (0);
}
