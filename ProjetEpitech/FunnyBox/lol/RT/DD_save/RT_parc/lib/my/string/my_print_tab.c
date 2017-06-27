/*
** my_print_tab.c for my_print_tab in /home/daniel_d/rendu/RT/RT_parc/lib/my/string
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 31 14:14:16 2014 daniel_d
** Last update Sat May 31 14:16:13 2014 daniel_d
*/

#include <stdlib.h>
#include "my.h"

void	my_print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_printf("%d = %s\n", i , tab[i]);
      i++;
    }
}
