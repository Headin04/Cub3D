/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:17:57 by eewu              #+#    #+#             */
/*   Updated: 2024/01/15 12:43:25 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <stdbool.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <limits.h>
# include <unistd.h>
# include <errno.h>

# define WRONG_ARGS 1
# define WRONG_NAME 2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_map
{
}			t_map;

typedef struct lst
{
	char		*str;
	int			i;
	struct lst	*next;
	struct lst	*back;
}				t_lst;

typedef struct main
{
	char		**av;
	int			ac;
	int			move;
	int			map_x;
	int			map_y;
}				t_struct;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	t_struct	*cub;
}				t_vars;

typedef struct s_win
{
	t_map	map;
}			t_win;


// ************************************Cub3D********************************* //

// ************************************Init********************************** //

// ************************************Free********************************** //

// ***********************************Errors********************************* //

// ************************************STR*********************************** //
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_backsn(char *buf);
char		*ft_gnljoin(char *stash, char *buf, int backsn_index, int size);
// ***********************************Split********************************** //
char		*ft_strlcat(char *dst, const char *src, int size);
char		*ft_strlcpy(char *dest, const char *src);
char		**ft_tab(int nb_word, char *s, char c, char **split);
char		**ft_split(char *s, char c);
char		*ft_join(char *s1, char const *s2);
// ************************************LST*********************************** //
t_lst		*ft_lstnew(char *str);
void		ft_lstadd_back(t_struct *sl, t_lst **head, t_lst *new);
t_lst		*ft_lstcopy(t_struct *sl, t_lst *old_lst);
t_lst		*ft_lstlast(t_lst *lst);
int			ft_lstsize(t_lst *lst);

#endif