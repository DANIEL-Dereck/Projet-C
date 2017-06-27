/*
** init_obj.c for rt in /home/jouana_j/rendu/MUL_2013_rtracer(V2)/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Fri May  9 18:47:12 2014 jouana_j
** Last update Sun Jun  8 19:17:41 2014 daniel_d
*/

#include "ray.h"

static int m;

t_coord	*init_eye(t_eyep eyep)
{
  t_coord *eye;

  if ((eye = malloc(sizeof(*eye))) == NULL)
    return (NULL);
  eye->x = eyep.coord.x;
  eye->y = eyep.coord.y;
  eye->z = eyep.coord.z;
  return (eye);
}

t_lum	*init_lum(t_lumos *lumos)
{
  int	i;
  t_lum *lum;

  i = 0;
  if ((lum = malloc(sizeof(*lum) * (lumos->nb_spot))) == NULL)
    return (NULL);
  lum->nb_spot = lumos->nb_spot;
  while (i < lumos->nb_spot)
    {
      lum[i].pos.x = lumos[i].coord.x;
      lum[i].pos.y = lumos[i].coord.y;
      lum[i].pos.z = lumos[i].coord.z;
      lum[i].color = my_color(lum[i].color, lumos[i].color.r,
			      lumos[i].color.v, lumos[i].color.b);
      i++;
    }
  return (lum);
}

t_object    *init_obj(t_obj *item)
{
  int	i;
  t_object *obj;

  i = 0;
  if ((obj = malloc(sizeof(*obj) * (item->nb_obj))) == NULL)
    return (NULL);
  obj->nb_obj = item->nb_obj;
  while (i < item->nb_obj)
    {
      obj[i].type = item[i].type;
      obj[i].damier = item[i].damier;
      obj[i].pos.x = item[i].coord.x;
      obj[i].pos.y = item[i].coord.y;
      obj[i].pos.z = item[i].coord.z;
      obj[i].angle.x = item[i].angle.x;
      obj[i].angle.y = item[i].angle.y;
      obj[i].angle.z = item[i].angle.z;
      obj[i].brill = item[i].brill;
      obj[i].rayon = item[i].rayon;
      obj[i].num = i;
      obj[i].color = my_color(obj[i].color, item[i].color.r,
			      item[i].color.v, item[i].color.b);
      i++;
    }
  return (obj);
}

t_coord	*init_V()
{
  t_coord *V;

  if ((V = malloc(sizeof(*V))) == NULL)
    return (NULL);
  return (V);
}

int	init_rt(t_rt *rt, t_eyep eyep, t_lumos *lumos, t_obj *item)
{
      rt->obj = init_obj(item);
      rt->eye = init_eye(eyep);
      rt->lum = init_lum(lumos);
      rt->V = init_V();
      m = 1;
      return (0);
}
