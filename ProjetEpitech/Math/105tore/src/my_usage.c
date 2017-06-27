/*
** my_usage.c for 105 in /home/daniel_d/rendu/105tore/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Jan 15 11:32:46 2014 daniel_d
** Last update Wed Feb 26 11:46:57 2014 daniel_d
*/

#include "my.h"
#include "tore.h"

int	my_usage(char **av)
{
  my_printf("%s 1 2 3 4 5 6 7\n", av[0]);
  my_printf("1 = numero de l'option :\n\t option 1: méthode de la bissection\n\t option 2 : méthode de Newton\n\t option 2: méthode de la sécante\n");
  my_printf("2 / 3 / 4 / 5 / 6 = au nombre de l'equation\n");
  my_printf("7 = au nombre de decimale correctes attendues\n");
  return (0);
}
