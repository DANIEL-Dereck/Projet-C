/*
** toretue.c for 105 in /home/daniel_d/rendu/105tore/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Jan 20 14:08:09 2014 daniel_d
** Last update Wed Jan 22 16:14:22 2014 daniel_d
*/

#include "my.h"
#include "tore.h"

int	equa_aff(char **av)
{
  if ((my_getnbr(av[6])) != 0)
    {
      if ((my_getnbr(av[6])) == 1)
	my_printf("x⁴");
      else
	my_printf("%dx⁴", my_getnbr(av[6]));
      if ((my_getnbr(av[5])) != 0 || (my_getnbr(av[4])) != 0 || (my_getnbr(av[3])) != 0 || (my_getnbr(av[2])) != 0)
	my_printf(" + ");
    }
  if ((my_getnbr(av[5])) != 0)
    {
      if ((my_getnbr(av[5])) == 1)
        my_printf("x³");
      else
        my_printf("%dx³", my_getnbr(av[5]));
      if ((my_getnbr(av[4])) != 0 || (my_getnbr(av[3])) != 0 || (my_getnbr(av[2])) != 0)
	my_printf(" + ");
    }
  if ((my_getnbr(av[4])) != 0)
    {
      if ((my_getnbr(av[4])) == 1)
        my_printf("x²");
      else
        my_printf("%dx²", my_getnbr(av[4]));
      if ((my_getnbr(av[3])) != 0 || (my_getnbr(av[2])) != 0)
	my_printf(" + ");
    }
  if ((my_getnbr(av[3])) != 0)
    {
      if ((my_getnbr(av[3])) == 1)
        my_printf("x");
      else
        my_printf("%dx", my_getnbr(av[3]));
      if ((my_getnbr(av[2])) != 0)
	my_printf(" + ");
    }
  if ((my_getnbr(av[2])) != 0)
    {
      my_printf("%d", my_getnbr(av[2]));
    }
  my_printf("= 0\n");
  return (0);
}

int	toretue(char **av)
{
  int	s;

  s = my_getnbr(av[1]);
  if (s == 1)
    {
      equa_aff(av);
      my_printf("méthode de la bissection\n");
      my_bis(av);
      return (0);
    }
  else if (s == 2)
    {
      equa_aff(av);
      my_printf("méthode de Newton\n");
      my_newton(av);
      return (0);
    }
  else if (s == 3)
    {
      equa_aff(av);
      my_printf("méthode de la sécante\n");
      my_sec(av);
      return (0);
    }
  my_printf("méthode inconue\n");
  my_usage(av);
  return (0);
}
