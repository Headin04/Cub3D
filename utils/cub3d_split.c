/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:00:34 by eewu              #+#    #+#             */
/*   Updated: 2024/01/15 12:33:55 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3d.h"

char	*ft_strlcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strlcat(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[size + i] = src[i];
		i++;
	}
	return (dest);
}

char	**ft_tab(int nb_word, char *s, char c, char **split)
{
	int		j;
	int		i;
	int		k;
	int		size_word;

	k = 0;
	i = 0;
	while (s[i] && k < nb_word)
	{
		j = 0;
		size_word = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i + size_word] && (s[i + size_word] != c))
			size_word++;
		split[k] = ft_calloc(sizeof(char), (size_t)(size_word + 1));
		if (!split[k])
			return (ft_free_split(split), NULL);
		while (s[i] && s[i] != c)
			split[k][j++] = s[i++];
		k++;
	}
	return (split);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && !(s[i] == c))
			i++;
		nb += 1;
	}
	if (s == NULL)
		return (0);
	split = ft_calloc(sizeof(char *), (nb + 1));
	if (!split)
		return (ft_free_split(split), NULL);
	if (ft_tab(nb, (char *)s, c, split))
		return (split);
	return (0);
}

char	*ft_join(char *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join;

	len_s1 = 0;
	len_s2 = 0;
	if (s1)
		len_s1 = ft_strlen(s1);
	if (s2)
		len_s2 = ft_strlen(s2);
	join = ft_calloc(sizeof(char), (len_s1 + len_s2 + 1));
	if (s1)
		ft_strlcpy(join, s1);
	if (s2)
		ft_strlcat(join, s2, (int)len_s1);
	return (join);
}
