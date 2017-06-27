/*
** intersection.h for raytracer in /home/jouana_j/rendu/tp_raytracer/source
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Wed Feb 19 13:48:06 2014 jouana_j
** Last update Fri May  9 21:01:57 2014 jouana_j
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
  coord p;
  float brill;
  coord pos;
  coord N;
  int	red;
  int	green;
  int	blue;
  coord	angle;
  char type;
  t_color color;
} t_object;

typedef struct s_lum
{
  coord pos;
  coord L;
  int   red;
  int   green;
  int   blue;
  float NL;
  float alpha;
} t_lum;

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
