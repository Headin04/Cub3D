/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:01:28 by eewu              #+#    #+#             */
/*   Updated: 2024/02/16 10:40:44 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

// static void	ft_minibackground(t_vars *vars, int color)
// {
// 	int		x;
// 	int		y;

// 	x = 0;
// 	while (x < 50)
// 	{
// 		y = 0;
// 		while (y < 30)
// 		{
// 			img_pix_put(&vars->img, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// static void	ft_minisquare(t_vars *vars, int color)
// {
// 	int		x;
// 	int		y;
// 	int		i;
// 	int		j;

// 	x = 0;
// 	i = 0;
// 	j = 0;
// 	while (x < 4)
// 	{
// 		y = 0;
// 		while (y < 4)
// 		{
// 			img_pix_put(&vars->img, x + i, y + j, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	ft_minimap(t_vars *vars)
// {
// 	int		x;
// 	int		y;
// 	int		lenx;

// 	x = 0;
// 	ft_minibackground(vars, WHITE_C);
// 	lenx = (int)ft_lstsize(vars->cub.map->start_map);
// 	while (x <= lenx)
// 	{
// 		y = 0;
// 		img_pix_put(&vars->img, x, y, WHITE_C);
// 		while (y <= (int)ft_strlen(vars->cub.map->start_map->content))
// 		{
// 			if (ft_curr_map_square(vars, x, y) == 1)
// 				ft_minisquare(vars, BLACK_C);
// 			// else if (ft_curr_map_square(vars, x, y) > 1)
// 			// 	ft_minisquare(vars, green_color, i);
// 			y++;
// 		}
// 		x++;
// 	}
// }
