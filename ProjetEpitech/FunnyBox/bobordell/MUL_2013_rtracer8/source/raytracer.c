/*
** raytracer.c for raytracer in /home/grasla_r/rendu/MUL_2013_rtracer
** 
** Made by grasla_r
** Login   <grasla_r@epitech.net>
** 
** Started on  Fri Apr 25 16:05:09 2014 grasla_r
** Last update Wed Jun  4 16:56:20 2014 jouana_j
*/

#include "ray.h"

t_object	my_object(t_object obj, t_coord *V, t_rt *rt)
{
  int	i;
  t_object (*p_object[4])(t_object, t_coord*, t_rt*);
  char	symbol[4];

  symbol[0] = 'p';
  symbol[1] = 's';
  symbol[2] = 'y';
  symbol[3] = 'c';
  symbol[4] = '\0';
  p_object[0] = &inter_plan;
  p_object[1] = &inter_sphere;
  p_object[2] = &inter_cyl;
  p_object[3] = &inter_cone;
  p_object[4] = NULL;
  i = 0;
  while (p_object[i] != NULL)
    {
      if (symbol[i] == obj.type)
  	obj = p_object[i](obj, V, rt);
      i++;
    }
  return (obj);
}

void	my_inter_obj(t_object *obj, t_rt *rt, t_coord *V, int nb_obj)
{
  int	i;

  i = 0;
  while (i < nb_obj)
    {
      obj[i] = my_object(obj[i], V, rt);
     i = i + 1;
   }
}

int	calc(t_coord img, t_window *libx, t_coord *V, t_rt *rt)
{
  int	i;
  int	nb_obj;
  t_color color;
  
  nb_obj = 4;
  my_inter_obj(rt->obj, rt, V, nb_obj);
  i = my_triobject_k(rt->obj, nb_obj);
  if (i != - 1)
   {
     color = rt->obj[i].color;
     luminosite(&color, rt->obj[i], V, rt);
   }
 else
   color = my_color(color, 0, 0, 0);
  my_pixel_put_to_image(img.x, img.y, &color, libx);
  return (0);
}

int    remplir_image(t_window *libx)
{
  t_coord img;
  t_rt *rt;

  rt = malloc(sizeof(*rt));
  init_rt(rt);
  img.x = 0;
  while (img.x != WIN_X)
    {
      img.y = 0;
      while (img.y != WIN_Y)
        {
          rt->V->x = 100;
          rt->V->y = (WIN_X/2) - img.x;
          rt->V->z = (WIN_Y/2) - img.y;
	  calc(img, libx, rt->V, rt);
          img.y = img.y + 1;
        }
      img.x = img.x + 1;
    }
  free(rt->V);
  free(rt->obj);
  free(rt->eye);
  free(rt->lum);
  free(rt);
  return (0);
}
