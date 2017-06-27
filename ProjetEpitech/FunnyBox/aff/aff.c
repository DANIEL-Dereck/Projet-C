/*
** aff.c for aff in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun  2 17:03:36 2014 daniel_d
** Last update Sat Jun  7 10:54:31 2014 daniel_d
*/

#include "ray.h"

void	aff_all(t_obj *obj, t_eyep eye, t_lumos *lum)
{
  int	i;

  i = 0;
  printf("eye pos =\n\tx : %3.3f\n\ty : %3.3f\n\tz : %3.3f\n",
	 eye.coord.x, eye.coord.y, eye.coord.z);
  printf("eye angle =\n\tx : %3.3f\n\ty : %3.3f\n\tz : %3.3f\n",
	 eye.angle.x, eye.angle.y, eye.angle.z);
  while (i < obj[i].nb_obj)
    {
      printf("\n-----item : %d-----\n", (i + 1));
      if (obj[i].type == 'p')
	printf("type =\tplan\n");
      else if (obj[i].type == 's')
	printf("type =\tsphere\n");
      else if (obj[i].type == 'c')
	printf("type =\tcone\n");
      else if (obj[i].type == 'y')
	printf("type =\tcylindre\n");
      else
	printf("truc inconue\n");
      printf("pos =\n\tx : %3.3f\n\ty : %3.3f\n\tz : %3.3f\n",
	     obj[i].coord.x, obj[i].coord.y, obj[i].coord.z);
      printf("angle =\n\tx : %3.3f\n\ty : %3.3f\n\tz : %3.3f\n",
	     obj[i].angle.x, obj[i].angle.y, obj[i].angle.z);
      printf("color =\n\tred : %3.3f\n\tgreen : %3.3f\n\tblue : %3.3f\n",
		obj[i].color.r, obj[i].color.v, obj[i].color.b);
      printf("\tbrill %3.3f\n", obj[i].brill);
      i++;
    }
  i = 0;
  printf("%d\n", lum[i].nb_spot);
  while (i < lum[i].nb_spot)
    {
      printf("\n-----spot : %d-----\n", (i + 1));
      printf("pos =\n\tx : %3.3f\n\ty : %3.3f\n\tz : %3.3f\n",
	     lum[i].coord.x, lum[i].coord.y, lum[i].coord.z);
      printf("color =\n\tred : %3.3f\n\tgreen : %3.3f\n\tblue : %3.3f\n",
		lum[i].color.r, lum[i].color.v, lum[i].color.b);
      i++;
    }
}
