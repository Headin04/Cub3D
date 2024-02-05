/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:42:23 by eewu              #+#    #+#             */
/*   Updated: 2024/01/29 15:44:03 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	initialize(&cub);
	check_file(argc, argv, &cub);
	cub.map->map_cloned = cub.map->start_map_cloned;
	ft_mlx_start(&cub);
	free_cub(&cub);
	return (0);
}
