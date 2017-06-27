/*
** my_str_to_wordtab.c for strtowordtab in /home/daniel_d/rendu
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat Jan  4 15:02:32 2014 daniel_d
** Last update Tue Jan  7 16:26:42 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>

int	my_cw(char *str)
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

int	my_cc(char *str)
{
  int   i;

  i = 0;
  while ((str[i] != ' ') && (str[i] != '\0') && (str[i] != '\n'))
    i++;
  i = i + 1;
  return (i);
}

char	**my_str_to_wordtab(char *str)
{
  char  **wtab;
  int   i;
  int   b;
  int   a;

  b = 0;
  i = 0;
  a = 0;
  if ((wtab = malloc(sizeof(wtab) * ((my_cw(str) + 1)))) == NULL)
    return (0);
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
        {
          while (str[i++] == ' ');
          a++;
          b = 0;
        }
      if ((wtab[a] = malloc(sizeof(*wtab) * ((my_cc(str + i) + 1)))) == NULL)
	return (0);
      while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
        wtab[a][b++] = str[i++];
      wtab[a][b] = '\0';
    }
  wtab[a + 1] = 0;
  return (wtab);
}
