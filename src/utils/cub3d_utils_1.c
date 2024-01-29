/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:59:49 by eewu              #+#    #+#             */
/*   Updated: 2024/01/29 16:04:05 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	tab = malloc(size * nmemb);
	ft_bzero(tab, size * nmemb);
	return (tab);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str && i < n)
	{
		str[i] = '\0';
		i++;
	}
}

int	ft_backsn(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	char	*s3;
	size_t	lens1;
	size_t	lens2;

	lens1 = 0;
	lens2 = 0;
	if (s1 != NULL)
		lens1 = ft_strlen(s1);
	if (s2 != NULL)
		lens2 = size;
	s3 = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	else
	{
		if (s1 != NULL)
			ft_strlcpy(s3, s1, lens1 + 1);
		if (s2 != NULL)
			ft_strlcpy((s3 + lens1), s2, (lens2 + 1));
	}
	if (s1 != NULL)
		free(s1);
	return (s3);
}
