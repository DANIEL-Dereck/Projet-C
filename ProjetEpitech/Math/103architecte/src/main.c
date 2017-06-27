/*
** main.c for 103 in /home/daniel_d/rendu/103architecte/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Dec 13 12:57:53 2013 daniel_d
** Last update Wed Dec 18 13:37:21 2013 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "../Lib/include/my.h"
#include "../Lib/include/architect.h"

int main(int ac, char **av)
{
  int	i;
  float *matrix;
  float	*tab;
  int	*verif;

  if (ac < 3)
    {
      my_printf("Nombre d'arguments invalide.\n");
      my_usage();
      return (0);
    }
  i = 0;
  verif = malloc(sizeof(verif) * 4);
  if (verif == NULL)
    return (0);
  while (i <= 3)
    verif[i++] = 0;
  i = 0;
  tab = malloc(sizeof(tab) * 9);
  if (tab == NULL)
    return (0);
  while (i <= 8)
    tab[i++] = 0.000;
  tab[0] = 1.000;
  tab[4] = 1.000;
  tab[8] = 1.000;
  i = 0;
  matrix = malloc(sizeof(matrix) * 2);
  if (matrix == NULL)
    return (0);
  matrix[0] = my_getnbr(av[1]);
  matrix[1] = my_getnbr(av[2]);
  if ((tab = my_calc(av, tab, verif)) == 0)
      return (0);
  my_aff(av, verif);
  matrix = my_coord(matrix, verif, av);
  printf("\t %.3f %.3f %.3f\n\t %.3f %.3f %.3f\n\t %.3f %.3f %.3f\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6], tab[7], tab[8]);
  printf("(%d,%d) => (%.3f,%.3f)\n", my_getnbr(av[1]), my_getnbr(av[2]), matrix[0], matrix[1]);
  return (0);
}
