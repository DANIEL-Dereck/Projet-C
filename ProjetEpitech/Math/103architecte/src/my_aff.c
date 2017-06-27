/*
** my_aff.c for 103 in /home/daniel_d/rendu/103architecte
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Dec 13 11:38:35 2013 daniel_d
** Last update Wed Dec 18 13:41:46 2013 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "../Lib/include/my.h"
#include "../Lib/include/architect.h"

int	my_aff(char **av, int *verif)
{
  int	i;

  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == 'T')
        {
          if (av[i][1] == '\0' && av[i + 1] != NULL && av[i + 2] != NULL)
            {
	      if (verif[0] >= 1)
		my_printf("translation de vecteur (%d,%d)\n", my_getnbr(av[i + 1]), my_getnbr(av[i + 2]));
            }
          else
            {
	      my_printf("Argument de Translation invalide invalide.\n");
              my_usage();
              return (0);
            }
        }
      i++;
    }
  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == 'H')
        {
          if (av[i][1] == '\0' && av[i + 1] != NULL && av[i + 2] != NULL)
            {
	      if (verif[1] >= 1)
		my_printf("homothétie de rapports %d et %d\n", my_getnbr(av[i + 1]), my_getnbr(av[i + 2]));
            }
          else
            {
	      my_printf("Argument de l'Homothétie invalide.\n");
              my_usage();
              return (0);
            }
        }
      i++;
    }
  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == 'R')
        {
          if (av[i][1] == '\0' && av[i + 1] != NULL)
            {
	      if (verif[2] >= 1)
		my_printf("rotation d'angle %d degrés\n", my_getnbr(av[i + 1]));
            }
          else
            {
	      my_printf("Argument de Rotation invalide.\n");
              my_usage();
              return (0);
            }
        }
      i++;
    }
  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == 'S')
        {
          if (av[i][1] == '\0' && av[i + 1] != NULL)
            {
	      if (verif[3] >= 1)
		my_printf("symétrie par rapport à un axe incliné de %d degrés\n", my_getnbr(av[i + 1]));
            }
          else
            {
	      my_printf("Argument de Symétrie invalide.\n");
              my_usage();
              return (0);
            }
        }
      i++;
    }
  i = 0;
  return (0);
}

