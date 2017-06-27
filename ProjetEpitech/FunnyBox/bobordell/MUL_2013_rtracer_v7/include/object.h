/*
** intersection.h for raytracer in /home/jouana_j/rendu/tp_raytracer/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Wed Feb 19 13:48:06 2014 jouana_j
** Last update Thu Jun  5 17:36:50 2014 daniel_d
*/

#ifndef INTER_H_
# define INTER_H_

typedef struct s_color
{
  float r;
  float v;
  float b;
} t_color;

typedef struct s_object
{
  int is_inter;
  float k;
  t_coord p;
  t_coord pos;
  t_coord N;
  int	red;
  int	green;
  int	blue;
  char type;
  float brill;
  t_coord	angle;
  t_color color;
} t_object;

typedef struct s_lum
{
  t_coord pos;
  t_coord L;
  int   red;
  int   green;
  int   blue;
  float NL;
  float alpha;
} t_lum;

typedef struct s_rt
{
  t_object *obj;
  t_coord *eye;
  t_coord *V;
  t_lum *lum;
}t_rt;

typedef struct s_window
{
  void *mlx_ptr;
  void *win_ptr;
  void *img_ptr;
  int   bpp;
  int   sizeline;
  int   endian;
  char  *data;
} t_window;

#endif
