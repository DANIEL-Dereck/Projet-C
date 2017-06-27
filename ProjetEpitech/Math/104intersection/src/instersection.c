/*
** instersection.c for 104 in /home/daniel_d/rendu/104intersection/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Jan  7 14:12:42 2014 daniel_d
** Last update Wed Jan  8 17:35:58 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Lib/include/my.h"
#include "../Lib/include/intersection.h"

int	cylindre(char **av)
{
  int   xo;
  int   yo;
  int   zo;
  int   vx;
  int   vy;
  int   vz;
  int   a;
  int   b;
  int   c;
  int   delta;
  int   inter;
  int   r;
  float resx;
  float resy;
  float x;
  float y;
  float z;

  xo = atoi(av[2]);
  yo = atoi(av[3]);
  zo = atoi(av[4]);
  vx = atoi(av[5]);
  vy = atoi(av[6]);
  vz = atoi(av[7]);
  r = atoi(av[8]);
  a = (vx * vx) + (vy * vy);
  b = (2 * vx * xo) + (2 * vy * yo);
  c = (xo * xo) + (yo * yo) - (r * r);
  delta = (b * b) - (4 * a * c);
  if (delta < 0)
    inter = 0;
  if (delta == 0)
    inter = 1;
  if (delta > 0)
    inter = 2;
  printf("cylindre de rayon %d\ndroite passant par le point (%d,%d,%d), de vecteur directeur (%d,%d,%d)\nnombre de points d'intersection : %d\n", r, xo, yo, zo, vx, vy, vz, inter);
  if (inter == 1)
    {
      if (a == 0)
	{
          printf("ERROR : Division par zero");
          return (0);
        }
      resx = -b / (2 * a);
      x = vx * resx + xo;
      y = vy * resx + yo;
      z = vz * resx + zo;
      printf("point 1 :  (%.3f,  %.3f,  %.3f)\n", x, y, z);
    }
  if (inter == 2)
    {
      if (a == 0)
	{
          printf("ERROR : Division par zero");
          return (0);
        }
      resx = (-b -(sqrt(delta))) / (2 * a);
      resy = (-b + sqrt(delta)) / (2 * a);
      x = vx * resx + xo;
      y = vy * resx + yo;
      z = vz * resx + zo;
      printf("point 1 :  (%.3f,  %.3f,  %.3f)\n", x, y, z);
      x = vx * resy + xo;
      y = vy * resy + yo;
      z = vz * resy + zo;
      printf("point 2 :  (%.3f,  %.3f,  %.3f)\n", x, y, z);
    }
  return (0);
}

int	sphere(char **av)
{
  int   xo;
  int   yo;
  int   zo;
  int   vx;
  int   vy;
  int   vz;
  int   a;
  int   b;
  int   c;
  int   delta;
  int   inter;
  int   r;
  float resx;
  float resy;
  float x;
  float y;
  float z;

  xo = atoi(av[2]);
  yo = atoi(av[3]);
  zo = atoi(av[4]);
  vx = atoi(av[5]);
  vy = atoi(av[6]);
  vz = atoi(av[7]);
  r = atoi(av[8]);
  a = (vx * vx) + (vy * vy) + (vz * vz);
  b = (2 * vx * xo) + (2 * vy * yo) + (2 * vz * zo);
  c = (xo * xo) + (yo * yo) + (zo * zo) - (r * r);
  delta = (b * b) - (4 * a * c);
  if (delta < 0)
    inter = 0;
  if (delta == 0)
    inter = 1;
  if (delta > 0)
    inter = 2;
  printf("sphère de rayon %d\ndroite passant par le point (%d,%d,%d), de vecteur directeur (%d,%d,%d)\nnombre de points d'intersection : %d\n", r, xo, yo, zo, vx, vy, vz, inter);
  if (inter == 1)
    {
      if (a == 0)
	{
          printf("ERROR : Division par zero");
          return (0);
        }
      resx = -b / (2 * a);
      x = vx * resx + xo;
      y = vy * resx + yo;
      z = vz * resx + zo;
      printf("point 1 :  (%.3f,  %.3f,  %.3f)\n", x, y, z);
    }
  if (inter == 2)
    {
      if (a == 0)
	{
          printf("ERROR : Division par zero");
          return (0);
        }
      resx = (-b -(sqrt(delta))) / (2 * a);
      resy = (-b + sqrt(delta)) / (2 * a);
      x = vx * resx + xo;
      y = vy * resx + yo;
      z = vz * resx + zo;
      printf("point 1 :  (%.3f,  %.3f,  %.3f)\n", x, y, z);
      x = vx * resy + xo;
      y = vy * resy + yo;
      z = vz * resy + zo;
      printf("point 2 :  (%.3f,  %.3f,  %.3f)\n", x, y, z);
    }
  return (0);
}

int	cone(char **av)
{
  int   xo;
  int   yo;
  int   zo;
  int   vx;
  int   vy;
  int   vz;
  int   a;
  int   b;
  int   c;
  int   delta;
  int   inter;
  int   r;
  float resx;
  float resy;
  float x;
  float y;
  float z;

  xo = atoi(av[2]);
  yo = atoi(av[3]);
  zo = atoi(av[4]);
  vx = atoi(av[5]);
  vy = atoi(av[6]);
  vz = atoi(av[7]);
  r = atoi(av[8]);
  if ((tan(M_PI * r)) == 0)
    {
      printf("ERROR : Division par zero");
      return (0);
    }
  a = (vx * vx) + (vy * vy) - ((vz * vz) / ((tan((M_PI * r) / 90) * (tan((M_PI * r) / 90)))));
  b = (2 * vx * xo) + (2 * vy * yo) - ((2 * vz * zo) / ((tan((M_PI * r) / 90) * (tan((M_PI * r) / 90)))));
  c = (xo * xo) + (yo * yo) - ((zo * zo) / ((tan((M_PI * r) / 90) * (tan((M_PI * r) / 90)))));
  delta = (b * b) - (4 * a * c);
  if (delta < 0)
    inter = 0;
  if (delta == 0)
    inter = 1;
  if (delta > 0)
    inter = 2;
  printf("cône d'angle %d degrés\ndroite passant par le point (%d,%d,%d), de vecteur directeur (%d,%d,%d)\nnombre de points d'intersection : %d\n", r, xo, yo, zo, vx, vy, vz, inter);
  if (inter == 1)
    {
      if (a == 0)
	{
          printf("ERROR : Division par zero");
          return (0);
        }
      resx = -b / (2 * a);
      x = vx * resx + xo;
      y = vy * resx + yo;
      z = vz * resx + zo;
      printf("point 1 :  (%.3f,  %.3f,  %.3f)\n", x, y, z);
    }
  if (inter == 2)
    {
      if (a == 0)
	{
	  printf("ERROR : Division par zero");
	  return (0);
	}
      resx = (-b -(sqrt(delta))) / (2 * a);
      resy = (-b + sqrt(delta)) / (2 * a);
      x = vx * resx + xo;
      y = vy * resx + yo;
      z = vz * resx + zo;
      printf("point 1 :  (%.3f,  %.3f,  %.3f)\n", x, y, z);
      x = vx * resy + xo;
      y = vy * resy + yo;
      z = vz * resy + zo;
      printf("point 2 :  (%.3f,  %.3f,  %.3f)\n", x, y, z);
    }
  return (0);
}

int	my_inter(char **av)
{
  if (av[1][0] == '1' && av[1][1] == '\0')
      sphere(av);
  else if (av[1][0] == '2' && av[1][1] == '\0')
      cylindre(av);
  else if (av[1][0] == '3'&& av[1][1] == '\0')
      cone(av);
  else
    {
      my_printf("ERROR : av[1] != 1 ou 2 ou 3\n");
      return (0);
    }
  return (0);
}
