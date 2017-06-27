/*
** lumos.c for lumos in /home/daniel_d/rendu/MUL_2013_rtv1/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Mar 12 16:37:11 2014 daniel_d
** Last update Sun Mar 16 19:04:39 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "rt.h"
#include "my.h"

t_prime	*lumos_color(t_prime *all)
{
  if (all->lum->alpha < 0.000001)
    all->color->couleur = COLORF;
  else
    all->color->couleur = all->color->couleur * all->lum->alpha;
  return (all);
}

t_prime *lumos(t_prime *all, float nx, float ny, float nz)
{
  float nl;

  all->lum->px = all->ey->xe + (all->k->kf * all->im->x);
  all->lum->py = all->ey->ye + (all->k->kf * all->im->y);
  all->lum->pz = all->ey->ze + (all->k->kf * all->im->z);
  all->lum->lx = 200 - all->lum->px;
  all->lum->ly = 200 - all->lum->py;
  all->lum->lz = 200 - all->lum->pz;
  all->lum->lumos = sqrt((pow(all->lum->lx, 2))
			 + (pow(all->lum->ly, 2)) + (pow(all->lum->lz, 2)));
  all->lum->norm = sqrt((pow(nx, 2)) + (pow(ny, 2)) + (pow(nz, 2)));
  nl = all->lum->lumos * all->lum->norm;
  all->lum->alpha = ((all->lum->lx * nx)
		     + (all->lum->ly * ny) + (all->lum->lz * nz));
  all->lum->alpha = all->lum->alpha / nl;
  all = lumos_color(all);
  return (all);
}
