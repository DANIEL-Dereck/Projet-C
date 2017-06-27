/*
** gere_all.c for gere all in /home/daniel_d/TP/TP_RT/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Feb  6 09:42:47 2014 daniel_d
** Last update Sun Mar 16 19:27:43 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "mlx.h"
#include "mlx_int.h"
#include "rt.h"

int     gere_key(int keycode, t_prime *all)
{
  if (keycode == 65307)
    exit(1);
  else if (keycode == 65362)
    all->ey->ze = all->ey->ze + 10;
  else if (keycode == 65364)
    all->ey->ze = all->ey->ze - 10;
  else if (keycode == 65361)
    all->ey->ze = all->ey->ye + 10;
  else if (keycode == 65363)
    all->ey->ze = all->ey->ye - 10;
  all = affcolor(all);
  if ((mlx_put_image_to_window
       (all->wd->mlx, all->wd->win, all->wd->img2_ptr, 0, 0)) == 0)
    return (0);
  return (0);
}

int     gere_expose(t_window *wd)
{
  if ((mlx_put_image_to_window
       (wd->mlx, wd->win, wd->img2_ptr, 0, 0)) == 0)
    return (0);
  return (0);
}

t_prime	*colorpower(t_prime *all)
{
  all->color->red = all->color->couleur % 255;
  all->color->couleur = all->color->couleur / 255;
  all->color->green = all->color->couleur %255;
  all->color->couleur = all->color->couleur / 255;
  all->color->blue = all->color->couleur %255;
  all->color->couleur = all->color->couleur / 255;
  return (all);
}
