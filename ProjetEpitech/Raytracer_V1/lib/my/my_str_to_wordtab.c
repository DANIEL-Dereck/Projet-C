/*
** my_str_to_wordtab.c for strtowordtab in /home/daniel_d/rendu
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat Jan  4 15:02:32 2014 daniel_d
** Last update Sat Mar 15 15:49:47 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>

int	my_c_w(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ' ' && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

int	my_c_c(char *str)
{
  int   i;

  i = 0;
  while ((str[i] != ' ') && (str[i] != '\0') && (str[i] != '\n'))
    i++;
  i = i + 1;
  return (i);
}

char	**my_wordtab(char *str, char **tab, int i, int a)
{
  int b;

  b = 0;
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
        {
          while (str[i++] == ' ');
	  i--;
          a++;
          b = 0;
        }
      if ((tab[a] = malloc(sizeof(*tab) * ((my_c_c(str + i) + 1)))) == NULL)
	return (0);
      while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
        tab[a][b++] = str[i++];
      tab[a][b] = '\0';
    }
  tab[a + 1] = 0;
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  char  **tab;
  int   i;
  int   a;

  i = 0;
  a = 0;
  if ((tab = malloc(sizeof(tab) * ((my_c_w(str) + 1)))) == NULL)
    return (0);
  tab = my_wordtab(str, tab, i, a);
  return (tab);
}
