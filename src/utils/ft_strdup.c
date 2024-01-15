/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:23:56 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/09 12:11:41 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (size != '\0')
	{
		while (i + 1 < size && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		i++;
	}
	while (src[a] != '\0')
		a++;
	return (a);
}

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
