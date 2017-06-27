/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/daniel_d/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Oct 11 09:43:45 2013 daniel_d
** Last update Mon Oct 21 13:23:02 2013 daniel_d
*/

#include <stdlib.h>

int	my_count1(char *str)
{
  int a;
  int b;

  a = 0;
  b = 0;

  while (str[a] != '\0')
    {
      while (str[a] > 64 && str[a] < 91 || str[a] > 96
	     && str[a] < 123 || str[a] > 47 && str[a] < 58)
	{
	  a = a + 1;
	}
      a = a + 1;
      b = b + 1;
      my_putchar(b + 48);
      my_putchar('\n');
    }
  return (b);
}

int	my_count2(char *str, int nm)
{
  int a;
  a = 0;
  while (str[a] > 64 && str[a] < 91 || str[a] > 98
	 && str[a] < 123 || str[a] > 47 && str[a] < 58)
    {
      a = a + 1;
    }
  return (a);
}

char	**my_str_to_wordtab(char *str)
{
  int a;
  int nm;
  int nc;
  char **tab;
  int b;

  a = 0;
  b = 0;
  nm = my_count1(str);
  tab = malloc(sizeof(char*) * nm);
  while (nm >= b)
    {
      nc =  count2(str, nm);
      *tab = malloc(sizeof(char) * nc);
	while (str[a] > 64 && str[a] < 91 || str[a] > 98
	       && str[a] < 123 || str[a] > 47 && str[a] < 58)
	  {
	    tab[b][a] = str[a];
	    a = a + 1;
	  }
      a = a + 1;
      b = b + 1;
    }
}

