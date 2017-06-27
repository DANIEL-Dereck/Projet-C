/*
** raytracer.c for raytracer in /home/grasla_r/rendu/MUL_2013_rtracer
** 
** Made by grasla_r
** Login   <grasla_r@epitech.net>
** 
** Started on  Fri Apr 25 16:05:09 2014 grasla_r
** Last update Fri May  9 21:21:50 2014 jouana_j
*/

#include "ray.h"

t_object	my_object(t_object obj, coord *V, coord *eye)
{
  if (obj.type == 'p')
    obj = inter_plan(V, obj, eye);
  else if (obj.type == 's')
    obj = inter_sphere(V, obj, eye);
  else if (obj.type == 'y')
    obj = inter_cyl(V, obj, eye);
  else if (obj.type == 'c')
    obj = inter_cone(V, obj, eye);
  return (obj);
}

void	my_inter_obj(t_object *obj, coord *eye, coord *V, int nb_obj)
{
  int	i;

  init_eye(eye);
  init_obj(obj);
  i = 0;
  while (i <= nb_obj)
    {
     obj[i] = my_object(obj[i], V, eye);
     i = i + 1;
   }
}

int	calc(int x, int y, t_window *libx, coord *V)
{
 t_color *color;
 coord	*eye;
 t_object *obj;
 int	i;
 int	nb_obj;

 nb_obj = 3;
 if ((color = malloc(sizeof(*color))) == NULL)
   return (0);
 if ((eye = malloc(sizeof(*eye))) == NULL)
   return (0);
 if ((obj = malloc(sizeof(*obj) * (nb_obj + 1))) == NULL)
   return (0);
 my_inter_obj(obj, eye, V, nb_obj);
 i = my_triobject_k(obj, nb_obj);
 *color = obj[i].color;
 if (i == -1)
   my_color(color, 0, 0, 0);
 else
   luminosite(color, obj[i], V, eye);
 my_pixel_put_to_image(x, y, color, libx);
 free(eye);
 free(color);
 free(obj);
 return (0);
}

int    remplir_image(t_window *libx)
{
  int X;
  int Y;
  coord *V;

  if ((V = malloc(sizeof(V))) == NULL)
    return (0);
  X = 0;
  while (X != WIN_X)
    {
      Y = 0;
      while (Y != WIN_Y)
        {
          V->x = 100;
          V->y = (WIN_X/2) - X;
          V->z = (WIN_Y/2) - Y;
	  calc(X, Y, libx, V);
          Y = Y + 1;
        }
      X = X + 1;
    }
  free(V);
  return (0);
}
