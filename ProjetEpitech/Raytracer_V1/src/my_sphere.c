/*
** my_sphere.c for rt in /home/daniel_d/TP/TP_RT/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Feb 13 10:31:05 2014 daniel_d
** Last update Sun Mar 16 19:11:53 2014 daniel_d
*/

#include <math.h>
#include "mlx.h"
#include "mlx_int.h"
#include "my.h"
#include "rt.h"

int	rtspherek2(t_prime *all)
{
  if ((all->xyz->d = ((pow(all->xyz->b, 2) - (4 * all->xyz->a * all->xyz->c))))
      < 0.00001)
    return (0);
  else
    {
      all->k->ks1 = (-all->xyz->b + sqrt(all->xyz->d)) / (2 * all->xyz->a);
      all->k->ks2 = (-all->xyz->b - sqrt(all->xyz->d)) / (2 * all->xyz->a);
      if (all->k->ks1 < all->k->ks2)
	all->k->ksf = all->k->ks1;
      else
	all->k->ksf = all->k->ks2;
      return (1);
    }
  return (0);
}

int     rtspherek(t_prime *all, int x, int y)
{
  int	tmp;

  all->im->x = 100;
  all->im->y = (WSX / 2) - x;
  all->im->z = (WSY / 2) - y;
  all->xyz->r = 250;
  all->xyz->a = (pow(all->im->x, 2) + pow(all->im->y, 2) + pow(all->im->z, 2));
  all->xyz->b = (2 * ((all->ey->xe * all->im->x) + (all->ey->ye * all->im->y)
		      + (all->ey->ze * all->im->z)));
  all->xyz->c = (pow(all->ey->xe, 2) + pow(all->ey->ye, 2)
		 + pow(all->ey->ze, 2) - pow(all->xyz->r, 2));
  tmp = rtspherek2(all);
  return (tmp);
}
