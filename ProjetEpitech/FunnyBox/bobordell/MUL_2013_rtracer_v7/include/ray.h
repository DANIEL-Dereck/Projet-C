/*
** ray.h for raytracer in /home/grasla_r/rendu/MUL_2013_rtracer
** 
** Made by grasla_r
** Login   <grasla_r@epitech.net>
** 
** Started on  Fri Apr 25 16:08:36 2014 grasla_r
** Last update Thu Jun  5 17:48:46 2014 daniel_d
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
#include "my.h"

void my_pixel_put_to_image(int x, int y, t_color *color, t_window *libx);
t_color my_color(t_color color, int r, int v, int b);
int remplir_image(t_window *libx, t_eye eye, t_lumos lumos, t_obj *obj);
t_object inter_plan(t_object obj, t_coord *V, t_coord *eye);
t_object inter_sphere(t_object obj, t_coord *V, t_coord *eye);
t_object inter_cyl(t_object obj, t_coord *V, t_coord *eye);
t_object inter_cone(t_object obj, t_coord *V, t_coord *eye);
int my_tri_k(t_object *obj, int nb_obj);
t_object my_object(t_object obj, t_coord *V, t_coord *eye);
void my_putchar(char c);
t_color my_brillance(float alpha, t_color color, t_object obj);
void luminosite(t_color *color, t_object obj, t_coord *V, t_rt rt);
t_coord pos_simple(t_coord V, t_object obj);
t_coord pos_reel(t_coord V, t_object obj);
t_object tri_k(float a, float b, float delta, t_object obj);
int my_triobject_k(t_object *obj, int nb_obj);
t_coord *init_eye();
t_object *init_obj();
t_lum   *init_lum();
int    init_rt(t_rt *rt);
t_coord rotate(t_coord obj, float angle_x, float angle_y, float angle_z);
t_object calcul_normale(t_object obj);

#endif
