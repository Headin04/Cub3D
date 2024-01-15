/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:38:55 by eewu              #+#    #+#             */
/*   Updated: 2024/01/15 13:09:36 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

char	*ft_clear_buf(char *buf, char *bsn_i, int after)
{
	int	i;

	i = 0;
	if (after == -1)
	{
		while (bsn_i[i])
		{
			buf[i] = bsn_i[i];
			i++;
		}
		while (buf[i])
			buf[i++] = 0;
	}
	else
	{
		while (buf[after])
			buf[after++] = 0;
	}
	return (buf);
}

char	*ft_read(int start, char *stash, int fd, char *buf)
{
	int	r;

	r = 1;
	while (start == -1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (0);
		if (r == 0)
			break ;
		if (r != BUFFER_SIZE)
			buf = ft_clear_buf(buf, &buf[r], r);
		start = ft_backsn(buf);
		stash = ft_gnljoin(stash, buf, start, r);
	}
	if ((!stash) && r == 0)
		return (0);
	return (stash);
}

char	*ft_start(int fd, char *buf)
{
	int			start;
	int			end;
	char		*stash;

	start = ft_backsn(buf);
	stash = NULL;
	if (start != -1)
	{
		if (buf[start])
		{
			end = ft_backsn(&buf[start]);
			stash = ft_gnljoin(NULL, &buf[start], end, (BUFFER_SIZE - start));
			buf = ft_clear_buf(buf, &buf[start], -1);
			start = end;
		}
		else
			start = -1;
	}
	return (ft_read(start, stash, fd, buf));
}

char	*ft_gnljoin(char *stash, char *buf, int backsn_index, int size)
{
	int		i;
	int		j;
	int		len_stash;
	char	*join;

	i = 0;
	j = 0;
	len_stash = 0;
	if (stash)
		len_stash = ft_strlen(stash);
	if (backsn_index != -1)
		join = ft_calloc(sizeof(char), (len_stash + backsn_index + 1));
	else
		join = ft_calloc(sizeof(char), (len_stash + ft_strlen(buf) + 1));
	while (stash && stash[i])
	{
		join[i] = stash[i];
		i++;
	}
	while (j < size && buf[j] && (j < backsn_index || backsn_index == -1))
		join[i++] = buf[j++];
	free (stash);
	return (join);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_start(fd, buf);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open("./out", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		i = printf("%s", line);
// 		if (line == NULL)
// 			break ;
// 		free(line);
// 	}
// 	return (0);
// }
