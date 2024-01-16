/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:17:57 by eewu              #+#    #+#             */
/*   Updated: 2024/01/15 13:23:51 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

# define DEFAULT 0
# define WRONG_ARGS 1
# define WRONG_NAME 2
# define PATH_FALSE 3

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_map
{
}				t_map;

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

typedef struct s_cub
{
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	t_map		map;
}				t_cub;

void			print_error_msg(int key, t_cub *cub);

/*PARSING*/
void			check_file(int argc, char **argv, t_cub *cub);
void			check_arg(int argc, t_cub *cub);
void			check_name(char **argv, t_cub *cub);
void			check_must(char *str, t_cub *cub);
void			free_cub(t_cub *cub);
// ************************************Cub3D********************************* //

// ************************************Init********************************** //

// ************************************Free********************************** //

// ***********************************Errors********************************* //
void			ft_free_split(char **split);

// ************************************STR*********************************** //
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_backsn(char *buf);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*get_next_line(int fd);
char			*ft_strdup(char *);
char			*ft_gnljoin(char *stash, char *buf, int backsn_index, int size);
// ***********************************Split********************************** //
char			*ft_strlcat(char *dst, const char *src, int size);
char			*ft_strcpy(char *dest, const char *src);
char			**ft_tab(int nb_word, char *s, char c, char **split);
char			**ft_split(char *s, char c);
char			*ft_join(char *s1, char const *s2);
// ************************************LST*********************************** //
t_lst			*ft_lstnew(char *str);
void			ft_lstadd_back(t_struct *sl, t_lst **head, t_lst *new);
t_lst			*ft_lstcopy(t_struct *sl, t_lst *old_lst);
t_lst			*ft_lstlast(t_lst *lst);
int				ft_lstsize(t_lst *lst);

#endif