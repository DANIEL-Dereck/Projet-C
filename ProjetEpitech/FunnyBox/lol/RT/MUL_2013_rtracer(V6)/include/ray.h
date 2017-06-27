/*
** ray.h for raytracer in /home/grasla_r/rendu/MUL_2013_rtracer
** 
** Made by grasla_r
** Login   <grasla_r@epitech.net>
** 
** Started on  Fri Apr 25 16:08:36 2014 grasla_r
** Last update Tue May 27 10:23:24 2014 daniel_d
*/

#ifndef RAY_H_
# define RAY_H_

#define WIN_X 1280
#define WIN_Y 720

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "vecteur.h"
#include "object.h"
#include "mlx.h"

void    my_pixel_put_to_image(int x, int y, t_color *color, t_window *libx);
void    my_color(t_color *color, int r, int v, int b);
int    remplir_image(t_window *libx);
t_object     inter_plan(coord *V, t_object obj, coord *eye);
t_object     inter_sphere(coord *V, t_object obj, coord *eye);
t_object     inter_cyl(coord *V, t_object obj, coord *eye);
t_object     inter_cone(coord *V, t_object obj, coord *eye);
int     my_tri_k(t_object *obj, int nb_obj);
t_object  my_object(t_object obj, coord *V, coord *eye);
void	my_putchar(char c);
void    my_brillance(float alpha, t_color *color, t_object obj);
void    luminosite(t_color *color, t_object obj, coord *V, coord *eye);
coord   pos_simple(coord V, t_object obj);
coord   pos_reel(coord V, t_object obj);
t_object        tri_k(float a, float b, float delta, t_object obj);
int     my_triobject_k(t_object *obj, int nb_obj);
void    init_eye(coord *eye);
void    init_obj(t_object *obj);
coord rotate(coord obj, float angle_x, float angle_y, float angle_z);

#endif
