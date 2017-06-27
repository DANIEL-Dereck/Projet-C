/*
** init.c for rt in /home/daniel_d/rendu/MUL_2013_rtv1/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Mar 13 15:55:36 2014 daniel_d
** Last update Thu Mar 20 16:01:32 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "mlx.h"
#include "mlx_int.h"
#include "rt.h"

t_k     *k_init(t_k *k)
{
  k->ks1 = 0;
  k->ks2 = 0;
  k->ksf = 0;
  k->kp = 0;
  k->kf = 0;
  return (k);
}

t_prime *eye_init(t_prime *all)
{
  all->ey->xe = EYE;
  all->ey->ye = 0;
  all->ey->ze = ZED;
  return (all);
}

t_prime	*init_struct(t_prime *all)
{
  if ((all->wd = malloc(sizeof(*all->wd))) == NULL)
    return (NULL);
  if ((all->im = malloc(sizeof(*all->im))) == NULL)
    return (NULL);
  if ((all->lum = malloc(sizeof(*all->lum))) == NULL)
    return (NULL);
  if ((all->color = malloc(sizeof(*all->color))) == NULL)
    return (NULL);
  if ((all->xyz = malloc(sizeof(*all->xyz))) == NULL)
    return (NULL);
  if ((all->ey = malloc(sizeof(*all->ey))) == NULL)
    return (NULL);
  if ((all->k = malloc(sizeof(*all->k))) == NULL)
    return (NULL);
  return (all);
}
