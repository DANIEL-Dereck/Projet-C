/*
** rt_pars.h for rt in /home/daniel_d/rendu/RT/RT_parseur/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon May 12 13:22:08 2014 daniel_d
** Last update Sat May 31 16:07:54 2014 daniel_d
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
#define BS_X "<x>"
#define BS_Y "<y>"
#define BS_Z "<z>"
#define BS_RED "<red>"
#define BS_GREEN "<green>"
#define BS_BLUE "<blue>"

/*---balise end---*/
#define BE_RACINE "</racine>"
#define BE_EYE "</eye>"
#define BE_OBJ "</item>"
#define BE_ROTATE "</rotation>"
#define BE_POSITION "</position>"
#define BE_COLOR "</color>"
#define BE_X "</x>"
#define BE_Y "</y>"
#define BE_Z "</z>"
#define BE_RED "</red>"
#define BE_GREEN "</green>"
#define BE_BLUE "</blue>"

/*---balise item start---*/
#define BS_SPOT "<spot*>"
#define BS_PLAN "<plan*>"
#define BS_SPHERE "<sphere*>"
#define BS_CONE "<cone*>"
#define BS_CYLINDRE "<cylindre**>"

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
  float r;
  float v;
  float b;
} t_color;

typedef struct s_obj
{
  char  type;
  t_coord       coord;
  t_coord       angle;
  t_color       color;
  float brill;
} t_obj;

int     parsing(char *map);
int     remp_list(char **tab);

#endif
