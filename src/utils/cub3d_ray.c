/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:58:15 by eewu              #+#    #+#             */
/*   Updated: 2024/01/29 15:57:06 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

void	ft_rayinit(t_vars *vars)
{
	vars->ray.x = 0;
	vars->ray.posx = 10;
	vars->ray.posy = 2;
	vars->ray.dirx = -1;
	vars->ray.dirx = 0;
	vars->ray.planx = 0;
	vars->ray.plany = 0.66;
}

	// vars->ray.dirx = vars->n + vars->s;
	// vars->ray.dirx = vars->w + vars->e;
	// vars->ray.planx = vars->e + vars->w;
	// vars->ray.plany = vars->n + vars->s;

// 	dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
// 	diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
// 	planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
// 	plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)

void	ft_ray_loopinit(t_vars *vars)
{
	t_ray	r;

	r = vars->ray;
	r.hit = 0;
	r.perpwalldist = 0;
	r.camerax = 2 * r.x / (double)vars->sizex - 1;
	r.raydirx = r.dirx + r.planx * r.camerax;
	r.raydiry = r.diry + r.plany * r.camerax;
	r.mapx = r.posx;
	r.mapy = r.posy;
	vars->ray = r;
}


void	ft_raycasting(t_vars *vars)
{
	ft_rayinit(vars);
	while (vars->ray.x < vars->sizex)
	{
		ft_ray_loopinit(vars);
		vars->ray.x++;
	}

}

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