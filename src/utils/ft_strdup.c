/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:23:56 by ode-cleb          #+#    #+#             */
/*   Updated: 2024/01/29 16:02:50 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*dest;

	dest = NULL;
	len = ft_strlen(s);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest != NULL)
		ft_strlcpy(dest, s, len + 1);
	return (dest);
}
