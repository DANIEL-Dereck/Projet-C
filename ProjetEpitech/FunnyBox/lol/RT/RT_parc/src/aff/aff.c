/*
** aff.c for aff in /home/daniel_d/rendu/RT/RT_parc/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jun  2 17:03:36 2014 daniel_d
** Last update Thu Jun  5 17:42:16 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "rt_pars.h"

void	aff_all(t_obj *obj, t_eye eye, t_lumos *lum)
{
  int	i;

  i = 0;
  printf("eye pos =\n\tx : %3.3f\n\ty : %3.3f\n\tz : %3.3f\n",
	 eye.coord.x, eye.coord.y, eye.coord.z);
  printf("eye angle =\n\tx : %3.3f\n\ty : %3.3f\n\tz : %3.3f\n",
	 eye.angle.x, eye.angle.y, eye.angle.z);
  while (i < obj[i].nb_obj)
    {
      my_printf("\n-----item : %d-----\n", (i + 1));
      if (obj[i].type == 'p')
	my_printf("type =\tplan\n");
      else if (obj[i].type == 's')
	my_printf("type =\tsphere\n");
      else if (obj[i].type == 'c')
	my_printf("type =\tcone\n");
      else if (obj[i].type == 'y')
	my_printf("type =\tcylindre\n");
      else
	my_printf("truc inconue\n");
      printf("pos =\n\tx : %3.3f\n\ty : %3.3f\n\tz : %3.3f\n",
	     obj[i].coord.x, obj[i].coord.y, obj[i].coord.z);
      printf("angle =\n\tx : %3.3f\n\ty : %3.3f\n\tz : %3.3f\n",
	     obj[i].angle.x, obj[i].angle.y, obj[i].angle.z);
      my_printf("color =\n\tred : %d\n\tgreen : %d\n\tblue : %d\n",
		obj[i].color.r, obj[i].color.v, obj[i].color.b);
      printf("\tbrill %3.3f\n", obj[i].brill);
      i++;
    }
  i = 0;
  printf("%d\n", lum[i].nb_spot);
  while (i < lum[i].nb_spot)
    {
      my_printf("\n-----spot : %d-----\n", (i + 1));
      printf("pos =\n\tx : %3.3f\n\ty : %3.3f\n\tz : %3.3f\n",
	     lum[i].coord.x, lum[i].coord.y, lum[i].coord.z);
      my_printf("color =\n\tred : %d\n\tgreen : %d\n\tblue : %d\n",
		lum[i].color.r, lum[i].color.v, lum[i].color.b);
      i++;
    }
}
