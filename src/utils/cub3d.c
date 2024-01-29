/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:00:58 by eewu              #+#    #+#             */
/*   Updated: 2024/01/29 16:33:08 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

void	ft_mlx_start(t_cub *cub)
{
	t_vars	vars;

	(void)cub;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		ft_free_exit(printf("Erreur xpm\n"), &vars);
	ft_init_mlx(&vars, *cub);

	mlx_loop_hook(vars.mlx, &ft_display, &vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_keycode, &vars);
	mlx_hook(vars.win, 17, 1L << 2, mlx_loop_end, vars.mlx);
	mlx_loop(vars.mlx);
	ft_free_mlx(&vars);
}
