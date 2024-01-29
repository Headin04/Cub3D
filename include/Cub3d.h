/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:17:57 by eewu              #+#    #+#             */
/*   Updated: 2024/01/29 15:08:32 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <errno.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
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
# define COLOR_FALSE 4
# define WRONG_LETTERS 5
# define LEAK_IN_WALL 6
# define DOUBLE_MAP 7

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// typedef struct lst
// {
// 	char		*str;
// 	int			i;
// 	struct lst	*next;
// 	struct lst	*back;
// }				t_lst;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_map
{
	t_list			*map_lst;
	t_list			*map_cloned;
	t_list			*start_map_cloned;
	t_list			*start_map;
	char			dir_player;
	int				len_max;
	int				map_line;

}					t_map;

// typedef struct s_ray
// {
// 	double		posx; //position x du joueur
// 	double		posy; //position y du joueur
// 	double		dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
// 	double		diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
// 	double		planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
// 	double		plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
// 	double		raydirx; //calcul de direction x du rayon
// 	double		raydiry; //calcul de direction y du rayon
// 	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
// 	int			mapx; // coordonée x du carré dans lequel est pos
// 	int			mapy; // coordonnée y du carré dans lequel est pos
// 	double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
// 	double		sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
// 	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
// 	double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
// 	int			stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
// 	int			stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
// 	int			hit; // 1 si un mur a ete touche, 0 sinon
// 	int			side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
// 	double		perpwalldist; // distance du joueur au mur
// 	int			lineheight; //hauteur de la ligne a dessiner
// 	int			drawstart; //position de debut ou il faut dessiner
// 	int			drawend; //position de fin ou il faut dessiner
// }			t_ray;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			x;
	int			texture;
}				t_ray;


typedef struct s_lst
{
	char		*str;
	int			i;
	struct lst	*next;
	struct lst	*back;
}				t_lst;

typedef struct s_cub
{
	char			**av;
	int				ac;
	int				move;
	int				map_x;
	int				map_y;
}					t_struct;

typedef struct s_img
{
	void		*mlx_img;
	void		*img;
	int			*addr;
	int			h;
	int			w;
	int			bpp;
	int			llen;
	int			endian;
	char		*path;
}				t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	int			rx;
	int			ry;
	int			sizex;
	int			sizey;
	t_struct	cub;
	t_img		wall[4];
	t_img		img;
	t_ray		ray;
	t_struct	*cub;
}				t_vars;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_cub
{
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	t_rgb			*F;
	t_rgb			*C;
	t_map			*map;
}					t_cub;

void				print_error_msg(int key, t_cub *cub);

/*PARSING*/
void				check_file(int argc, char **argv, t_cub *cub);
void				check_arg(int argc, t_cub *cub);
void				check_name(char **argv, t_cub *cub);
void				check_must(char *str, t_cub *cub);
bool				check_for_textures(char *str, t_cub *cub);
bool				check_for_color(char *str, t_cub *cub, int n);
void				check_for_map(char *str, t_cub *cub);
void				check_map(t_cub *cub);
void				check_walls(t_cub *cub);
void				ft_backtracking(t_cub *cub);
void				free_map(t_list *lst);
void				free_cub(t_cub *cub);
// ************************************Cub3D********************************* //
void		ft_mlx_start(t_struct *cub);

// ************************************Init********************************** //
void		ft_init(t_struct *cub, int ac, char **av);
void		ft_init_mlx(t_vars *vars);

// ************************************Free********************************** //
void		ft_free_split(char **split);
void		ft_free_exit(int i, t_vars *vars);
void		ft_free_mlx(t_vars *vars);
// ***********************************Errors********************************* //
void				ft_free_split(char **split);

// ************************************STR*********************************** //
size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
int					ft_backsn(char *buf);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*get_next_line(int fd);
char				*ft_strdup(char *);
int					ft_atoi(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strnjoin(char *s1, char *s2, size_t size);
char				*ft_gnljoin(char *stash, char *buf, int backsn_index,
						int size);
// ***********************************Utils2********************************* //
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
void		*ft_memset(void *s, int c, size_t n);
// ***********************************Split********************************** //
char				*ft_strlcat(char *dst, const char *src, int size);
char				*ft_strcpy(char *dest, const char *src);
char				**ft_tab(int nb_word, char *s, char c, char **split);
char				**ft_split(char *s, char c);
char				*ft_join(char *s1, char const *s2);
// ************************************LST*********************************** //
t_list				*ft_lstnew(void *content);
// void			ft_lstadd_back(t_struct *sl, t_lst **head, t_lst *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstcopy(t_struct *sl, t_list *old_lst);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
// *********************************Keypress********************************* //
int			ft_keycode(int keycode, t_vars *vars);
// ********************************Raycasting******************************** //
void		ft_rayinit(t_vars *vars);
void		ft_ray_loopinit(t_vars *vars);
void		ft_raycasting(t_vars *vars);

t_list				*get_previous(t_list *list, t_list *current);

#endif