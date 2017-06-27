/*
** struct.h for rt in /home/daniel_d/rendu/RT/RT_parseur/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue May 27 08:53:40 2014 daniel_d
** Last update Sat May 31 15:28:40 2014 daniel_d
*/

typedef struct s_coord
{
  float x;
  float y;
  float z;
} coord;

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
  int   red;
  int   green;
  int   blue;
  coord angle;
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

typedef struct s_eye
{
  float	x;
  float	y;
  float	z;
} t_eye;

/*
** p = plan
** s = sphére
** y = cylindre
** c = cone
*/

typedef struct s_eye
{
  float	x;
  float	y;
  float	z;
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
  char	type;
  t_coord	coord;
  t_coord	angle;
  t_color	color;
  float	brill;
} t_obj;
