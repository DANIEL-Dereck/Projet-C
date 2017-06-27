/*
** ray.h for raytracer in /home/grasla_r/rendu/MUL_2013_rtracer
** 
** Made by grasla_r
** Login   <grasla_r@epitech.net>
** 
** Started on  Fri Apr 25 16:08:36 2014 grasla_r
** Last update Sun Jun  8 23:14:54 2014 daniel_d
*/

#ifndef RAY_H_
# define RAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include "mlx.h"
#include "my.h"

#define WIN_X 1280
#define WIN_Y 720
#define NAME "rtraceur"
#define FILE "*.xml"

# define DEBUG_MODE     1
# define CLEAN          "\e[0;0H\e[2J"

/*---balise start---*/
#define BS_RACINE "<racine>"
#define BS_EYE "<eye>"
#define BS_OBJ "<item>"
#define BS_ROTATE "<rotation>"
#define BS_POSITION "<position>"
#define BS_COLOR "<color>"

/*---balise xyz | rvb---*/
#define POS_X "<x>*</x>"
#define POS_Y "<y>*</y>"
#define POS_Z "<z>*</z>"
#define COLOR_RED "<red>*</red>"
#define COLOR_GREEN "<green>*</green>"
#define COLOR_BLUE "<blue>*</blue>"
#define BRILL "<brill>*</brill>"
#define RAYON "<rayon>*</rayon>"

/*---balise end---*/
#define BE_RACINE "</racine>"
#define BE_EYE "</eye>"
#define BE_OBJ "</item>"
#define BE_ROTATE "</rotation>"
#define BE_POSITION "</position>"
#define BE_COLOR "</color>"

/*---balise item start---*/
#define BS_SPOT "<spot*>"
#define BS_PLAN "<plan*>"
#define BS_SPHERE "<sphere*>"
#define BS_CONE "<cone*>"
#define BS_CYLINDRE "<cylindre*>"
#define BS_PARA "<parabole>"

/*---balise item end---*/
#define BE_SPOT "</spot*>"
#define BE_PLAN "</plan*>"
#define BE_SPHERE "</sphere*>"
#define BE_CONE "</cone*>"
#define BE_CYLINDRE "</cylindre*>"
#define BE_PARA "</parabole>"

/* all */
typedef struct s_coord
{
  float x;
  float y;
  float z;
} t_coord;

typedef struct s_color
{
  float r;
  float v;
  float b;
} t_color;

/* parsing */
typedef struct s_eyep
{
  t_coord coord;
  t_coord angle;
} t_eyep;

typedef struct s_obj
{
  int   nb_obj;
  char  type;
  t_coord       coord;
  t_coord       angle;
  t_color       color;
  float brill;
  float rayon;
} t_obj;

typedef struct s_lumos
{
  int   nb_spot;
  t_coord       coord;
  t_color       color;
} t_lumos;

/* calc */
typedef struct s_object
{
  int is_inter;
  float k;
  t_coord p;
  float brill;
  t_coord pos;
  t_coord N;
  int	red;
  int	green;
  int	blue;
  t_coord	angle;
  char type;
  t_color color;
  int	nb_obj;
  int	num;
  float rayon;
} t_object;

typedef struct s_lum
{
  t_coord pos;
  t_coord L;
  int   red;
  int   green;
  int   blue;
  t_color color;
  float NL;
  float alpha;
  int	nb_spot;
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

/* parsing */
int     parsing(char *map);
int     remp_list(char **tab);
int     remp_item(char **tab, t_obj *obj, int nb_item);
char    **init_tab_start(char **start);
char    **init_tab_end(char **end);
int     check_tab(char **tab);
int     my_strcmpv2(char *s1, char *s2);
char    *get_info(char *src, char s, char e);
t_eyep  remp_eye(char **tab, t_eyep eye);
int     remp_coord(char **tab, t_obj *item, int i);
int     remp_angle(char **tab, t_obj *item, int i);
int     remp_color(char **tab, t_obj *item, int i);
int     remp_brill(char **tab, t_obj *item, int i);
t_lumos *remp_spot(char **tab, t_lumos *lum);
int     remp_rayon(char **tab, t_obj *item, int i);
t_obj   *remp_plan(char **tab, t_obj *item, int i, int *c);
t_obj   *remp_sphere(char **tab, t_obj *item, int i, int *c);
t_obj   *remp_cone(char **tab, t_obj *item, int i, int *c);
t_obj   *remp_cylindre(char **tab, t_obj *item, int i, int *c);
t_obj   *remp_parabole(char **tab, t_obj *item, int i, int *c);
void    display_loading(char *);
void    display_time(int, int, int);

/* all */
int     rt_main(t_eyep eyep, t_lumos *lumos, t_obj *item);
int	remplir_image(t_window *libx, t_eyep eyep, t_lumos *lumos, t_obj *item);
int     init_rt(t_rt *rt, t_eyep eyep, t_lumos *lumos, t_obj *item);
t_coord *init_eye(t_eyep eyep);
t_lum   *init_lum(t_lumos *lumos);
t_object	*init_obj(t_obj *item);

/* calc */
void	my_pixel_put_to_image(int x, int y, t_color *color, t_window *libx);
t_color	my_color(t_color color, int r, int v, int b);
int	my_tri_k(t_object *obj, int nb_obj);
t_color my_brillance(t_color color, t_object obj, t_rt *rt, int i);
t_color my_final_color(t_color f_color, t_color color);
t_color my_final_final_color(t_color f_color, t_rt *rt);
t_color *my_color_brillance(t_rt *rt, t_color *color, t_object obj);
void    luminosite(t_color *color, t_object obj, t_coord *V, t_rt *rt);
t_coord my_calc_p(t_object obj, t_rt *rt, t_coord *V);
t_lum   my_calc_l(t_lum lum, t_object obj);
t_coord	pos_simple(t_coord *eye, t_coord *V, t_object *obj, t_coord *pos);
t_coord	pos_reel(t_coord *eye, t_coord *V, t_object *obj, t_coord *pos);
int	my_triobject_k(t_object *obj);
t_coord	rotate(t_coord obj, float angle_x, float angle_y, float angle_z);
float	ombr_plan(t_object obj, t_coord L);
float   ombr_sphere(t_object obj, t_coord L);
float   ombr_cyl(t_object obj, t_coord L);
float   ombr_cone(t_object obj, t_coord L);
int     my_ombre(t_color *color, t_object obj, t_coord *V, t_rt *rt);
t_lum   my_calc_l(t_lum lum, t_object obj);
t_object	calcul_normale(t_object obj, t_coord *pos);
t_object	inter_plan(t_object obj, t_coord *V, t_rt *rt);
t_object	inter_sphere(t_object obj, t_coord *V, t_rt *rt);
t_object	inter_cyl(t_object obj, t_coord *V, t_rt *rt);
t_object	inter_cone(t_object obj, t_coord *V, t_rt *rt);
t_object	my_object(t_object obj, t_coord *V, t_rt *rt);
t_object	tri_k(float a, float b, float delta, t_object obj);
t_object	inter_ph(t_object obj, t_coord *V, t_rt *rt);
t_object        my_n_sphere(t_object obj, t_coord *pos);
t_object        my_n_plan(t_object obj, t_coord *pos);
t_object        my_n_cylindre(t_object obj, t_coord *pos);
t_object	my_n_cone(t_object obj, t_coord *pos);
t_object	my_n_ph(t_object obj, t_coord *pos);

#endif
