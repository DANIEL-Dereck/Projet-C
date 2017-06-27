/*
** main.c for BSQ in /home/daniel_d/rendu/CPE-2013-BSQ
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Dec  8 11:40:04 2013 daniel_d
** Last update Sun Dec  8 11:50:12 2013 daniel_d
*/

#include "Lib/include/my.h"

int	main(int ac, char **av)
{
  int i;

  while (i != 5)
    {
      i--;
      if (i == 5)
	my_putstr(av[ac]);
    }
  return (0);
}
