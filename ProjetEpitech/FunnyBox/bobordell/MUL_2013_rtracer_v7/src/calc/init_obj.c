/*
** init_obj.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V2)/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Fri May  9 18:47:12 2014 jouana_j
** Last update Tue Jun  3 09:03:49 2014 daniel_d
*/

#include "ray.h"

static int m;

t_coord	*init_eye()
{
  t_coord *eye;

  if ((eye = malloc(sizeof(*eye))) == NULL)
    return (NULL);
  eye->x = -300;
  eye->y = 0;
  eye->z = 100;
  return (eye);
}

t_lum	*init_lum()
{
  t_lum *lum;
  int	nb_lum;

  nb_lum = 2;
  if ((lum = malloc(sizeof(*lum) * (nb_lum))) == NULL)
    return (NULL);
  lum[0].pos.x = -150.0;
  lum[0].pos.y = 0.0;
  lum[0].pos.z = 100;
  /*  lum[1].pos.x = -150.0;
  lum[1].pos.y = 100;
  lum[1].pos.z = 100;*/
  return (lum);
}

t_object    *init_obj()
{
  t_object *obj;
  int	nb_obj;

  nb_obj = 4;
  if ((obj = malloc(sizeof(*obj) * (nb_obj))) == NULL)
    return (NULL);
  obj[0].type = 'y';
  obj[0].pos.x = 100.0;
  obj[0].pos.y = 0.0;
  obj[0].pos.z = -100.0;
  obj[0].angle.x = 0.0;
  obj[0].angle.y = 80000.0;
  obj[0].angle.z = 0.0;
  obj[0].brill = 0.1;
  obj[0].color = my_color(obj[0].color, 0, 0, 255);
  obj[1].type = 'y';
  obj[1].pos.x = 0.0;
  obj[1].pos.y = 0.0;
  obj[1].pos.z = 0.0;
  obj[1].angle.x = 0.0;
  obj[1].angle.y = 90.0;
  obj[1].angle.z = 0.0;
  obj[1].brill = 0.1;
  obj[1].color = my_color(obj[1].color, 255, 0, 0);
  obj[2].type = 'y';
  obj[2].pos.x = 0.0;
  obj[2].pos.y = -200.0;
  obj[2].pos.z = 0.0;
  obj[2].angle.x = -90.0;
  obj[2].angle.y = 0.0;
  obj[2].angle.z = 0.0;
  obj[2].brill = 0.1;
  obj[2].color = my_color(obj[2].color, 0, 255, 0);
  obj[3].type = 'y';
  obj[3].pos.x = 0.0;
  obj[3].pos.y = 200.0;
  obj[3].pos.z = 0.0;
  obj[3].angle.x = 90.0;
  obj[3].angle.y = 0.0;
  obj[3].angle.z = 0.0;
  obj[3].brill = 0.1;
  obj[3].color = my_color(obj[3].color, 255, 255, 0);
  return (obj);
}

t_coord	*init_V()
{
  t_coord *V;

  if ((V = malloc(sizeof(*V))) == NULL)
    return (NULL);
  return (V);
}

int	init_rt(t_rt *rt)
{
      rt->obj = init_obj();
      rt->eye = init_eye();
      rt->lum = init_lum();
      rt->V = init_V();
      m = 1;
      return (0);
}
