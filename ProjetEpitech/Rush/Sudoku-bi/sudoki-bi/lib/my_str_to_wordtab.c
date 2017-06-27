/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/bidard_v/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by bidard_v
** Login   <bidard_v@epitech.net>
** 
** Started on  Wed Oct 16 15:20:02 2013 bidard_v
** Last update Sat Mar  1 14:39:17 2014 bidard_v
*/

#include <stdlib.h>
#include "my.h"

int	my_first(char *str, int l)
{
  while (str[l] != '\0')
    {
      if (str[l] >= '!' && str[l] <= '~')
	{
	  return (l);
	}
      l = l + 1;
    }
  return (0);
}

int	my_last(char *str, int first)
{
  while (str[first] >= '!' && str[first] <= '~')
    first = first + 1;
  return (first);
}

char	*delim(char *dest, char *src, int first, int last)
{
  int	counter;

  counter = 0;
  while (counter + first < last)
    {
      dest[counter] = src[first + counter];
      counter = counter + 1;
    }
  dest[counter] = '\0';
  return (dest);
}

char	**my_str_to_wordtab(char *str)
{
  char **tab;
  int	i;
  int	n;
  int	first;
  int	last;
  int	l;

  i = 0;
  l = 0;
  n = my_wordnbr(str);
  tab = malloc(sizeof(char*) * (n + 1));
  while (i < n)
    {
      first = my_first(str, l);
      last = my_last(str, first);
      tab[i] = malloc(sizeof(char) * (last - first + 1));
      tab[i] = delim(tab[i], str, first, last);
      i = i + 1;
      l = l + (last - first + 1);
    }
  tab[i] = NULL;
  return (tab);
}
