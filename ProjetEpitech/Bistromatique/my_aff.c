/*
** my_aff.c for Bistro in /home/daniel_d/rendu/Bistro
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Nov  5 13:42:26 2013 daniel_d
** Last update Fri Nov  8 12:39:32 2013 daniel_d
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

int	my_aff(char *result)
{
  int	a;

  a = 0;
  while (result[a] != '\0')
    {
      if (result[a] != '0')
	{
	  while (result[a] != '\0')
	    {
	      my_putchar(result[a]);
	      a = a + 1;
	    }
      my_putchar('\n');
      free(result);
      return (1);
	}
      a = a + 1;
    }
  my_putchar('0');
  my_putchar('\n');
  return (a);
}

