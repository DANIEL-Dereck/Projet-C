/*
** my_calc.c for 103 in /home/daniel_d/rendu/103architecte
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Dec 13 12:37:16 2013 daniel_d
** Last update Wed Dec 18 13:45:10 2013 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "../Lib/include/my.h"
#include "../Lib/include/architect.h"

float	*my_calc(char **av, float *tab, int *verif)
{
  int	i;
  
  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == 'S')
        {
          if (av[i][1] == '\0' && av[i + 1] != NULL)
            {
              tab = symetrie(tab, my_getnbr(av[i + 1]));
              verif[3] = verif[3] + 1;
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
  while (av[i] != NULL)
    {
      if (av[i][0] == 'R')
        {
          if (av[i][1] == '\0' && av[i + 1] != NULL)
            {
              tab = rotation(tab, my_getnbr(av[i + 1]));
              verif[2] = verif[2] + 1;
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
      if (av[i][0] == 'H')
        {
          if (av[i][1] == '\0' && av[i + 1] != NULL && av[i + 2] != NULL)
            {
              tab = homothetie(tab, my_getnbr(av[i + 1]), my_getnbr(av[i + 2]));
              verif[1] = verif[1] + 1;
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
      if (av[i][0] == 'T')
        {
          if (av[i][1] == '\0' && av[i + 1] != NULL && av[i + 2] != NULL)
            {
              tab = translation(tab, my_getnbr(av[i + 1]), my_getnbr(av[i + 2]));
              verif[0] = verif[0] + 1;
            }
          else
            {
	      my_printf("Argument de Translation invalide.\n");
              my_usage();
              return (0);
            }
        }
      i++;
    }
  return (tab);
}
