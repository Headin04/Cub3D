/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:42:23 by eewu              #+#    #+#             */
/*   Updated: 2024/02/05 12:34:20 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3d.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	initialize(&vars.cub);
	check_file(argc, argv, &vars.cub);
	vars.cub.map->map_cloned = vars.cub.map->start_map_cloned;
	ft_mlx_start(&vars);
	free_cub(&vars.cub);
	return (0);
}
