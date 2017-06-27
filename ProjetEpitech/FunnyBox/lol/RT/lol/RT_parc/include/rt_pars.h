/*
** rt_pars.h for rt in /home/daniel_d/rendu/RT/RT_parseur/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon May 12 13:22:08 2014 daniel_d
** Last update Mon Jun  2 16:17:53 2014 daniel_d
*/

#ifndef RT_PARS_H_
# define RT_PARS_H_

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

/*---balise item end---*/
#define BE_SPOT "</spot*>"
#define BE_PLAN "</plan*>"
#define BE_SPHERE "</sphere*>"
#define BE_CONE "</cone*>"
#define BE_CYLINDRE "</cylindre*>"

typedef struct s_eye
{
  float x;
  float y;
  float z;
} t_eye;

typedef struct s_coord
{
  float x;
  float y;
  float z;
} t_coord;

typedef struct s_color
{
  int r;
  int v;
  int b;
} t_color;

typedef struct s_obj
{
  char  type;
  t_coord       coord;
  t_coord       angle;
  t_color       color;
  float	brill;
} t_obj;

int     parsing(char *map);
int     remp_list(char **tab);
int     remp_item(char **tab, t_obj *obj, int nb_item);
int     check_tab(char **tab);
int     my_strcmpv2(char *s1, char *s2);
char    *get_info(char *src, char s, char e);
int     remp_eye(char **tab, t_eye *eye, int i);
int     remp_coord(char **tab, t_obj *item, int i);
int     remp_angle(char **tab, t_obj *item, int i);
int     remp_color(char **tab, t_obj *item, int i);
int     remp_brill(char **tab, t_obj *item, int i);

#endif
