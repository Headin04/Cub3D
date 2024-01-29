/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:17:57 by eewu              #+#    #+#             */
/*   Updated: 2024/01/29 12:54:55 by eewu             ###   ########.fr       */
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
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

# define WRONG_ARGS 1
# define WRONG_NAME 2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
	char		**av;
	int			ac;
	int			move;
	int			map_x;
	int			map_y;
}				t_struct;

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
	int			rx;
	int			ry;
	int			sizex;
	int			sizey;
	t_struct	cub;
	t_img		wall[4];
	t_img		img;
	t_ray		ray;
}				t_vars;

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
void		ft_free_split(char **split);

// ************************************STR*********************************** //
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_backsn(char *buf);
char		*ft_gnljoin(char *stash, char *buf, int backsn_index, int size);
// ***********************************Utils2********************************* //
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
void		*ft_memset(void *s, int c, size_t n);
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
// *********************************Keypress********************************* //
int			ft_keycode(int keycode, t_vars *vars);
// ********************************Raycasting******************************** //
void		ft_rayinit(t_vars *vars);
void		ft_ray_loopinit(t_vars *vars);
void		ft_raycasting(t_vars *vars);


#endif