/*
** my_usage.c for 104 in /home/daniel_d/rendu/104intersection/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 19 15:25:54 2013 daniel_d
** Last update Tue Jan  7 16:00:36 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Lib/include/my.h"
#include "../Lib/include/intersection.h"

int	my_usage()
{
  printf(" 8 argument: 1 2 3 4 5 6 7 8\n 1 = l'option :  1 = sphére / 2 = cylindre / 3 = cône\n");
  printf("2 / 3 / 4 : les coordonées d'un point par lequel passe le rayon\n");
  printf("5 / 6 / 7 : les coordonnées d'un vecteur de ses vecteur directeurs\n");
  printf("8 : arguments suivant les option\n");
  printf("\t option 1: (sphère) le rayon\n\t option 2: (cylindre) le rayon\n\t option 3: (cône) l'angle qu'il forme avec le plan (Oxy)\n");
  return (0);
}
