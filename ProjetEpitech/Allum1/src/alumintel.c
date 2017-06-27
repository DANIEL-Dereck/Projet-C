/*
** alumintel.c for alum1 in /home/daniel_d/rendu/alum1/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Feb 16 15:07:28 2014 daniel_d
** Last update Sun Feb 16 22:43:19 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "alum.h"

int	my_count_x_char(char *str, char c)
{
  int	a;
  int	p;

  a = 0;
  p = 0;
  while (str[a] != '\0')
    {
      if (str[a] == c)
	p = p + 1;
      a++;
    }
  return (p);
}

char    *my_concat_str(char *dest, char *src)
{
  int i;
  int k;

  i = 0;
  k = 0;
  if (src == NULL)
    return (0);
  while (src[k] != '\0' && src[k] != '\n' && src[k] != ' ')
    dest[i++] = src[k++];
  dest[i] = '\0';
  return (dest);
}

char	*epurestr(char *buffer)
{
  int	i;
  int	p;
  char	*str;

  i = 0;
  p = 0;
  if ((str = malloc(sizeof(str) * my_strlen(buffer))) == NULL)
    return (0);
  while (buffer[i] != '\n')
    {
      if ((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == ' ')
	{
	  str[p] = buffer[i];
	  p++;
	}
      i++;
    }
  buffer = my_concat_str(buffer, "0 0\n");
  if (p < 3)
    return (buffer);
  str[p] = '\0';
  return (str);
}

char    **ia_play(char **sapin, char *buffer, int nl)
{
  char  **buftab;
  int   l;
  int   p;
  int   i;

  i = 0;
  buffer = epurestr(buffer);
  buftab = my_str_to_wordtab(buffer);
  l = my_getnbr(buftab[0]) - 1;
  if (l < 0)
    l = 51;
  if (buftab[1] == NULL || l >= nl)
    return (sapin);
  p = my_getnbr(buftab[1]) - 1;
  i = my_count_x_char(sapin[l], '.');
  p = p + i;
  if (p >= my_strlen(sapin[l]))
    p = my_strlen(sapin[l]) - 2;
  while (i <= p)
    sapin[l][i++] = '.';
  return (sapin);
}

char	**jcj_play(char **sapin, char *buffer, int nl)
{
  char	**buftab;
  int	l;
  int	p;
  int	i;

  i = 0;
  buffer = epurestr(buffer);
  buftab = my_str_to_wordtab(buffer);
  l = my_getnbr(buftab[0]) - 1;
  if (l < 0)
    l = 2000;
  if (buftab[1] == NULL || l >= nl)
    {
      my_printf("CHEATER\n");
      return (sapin);
    }
  p = my_getnbr(buftab[1]) - 1;
  i = my_count_x_char(sapin[l], '.');
  p = p + i;
  if (p >= my_strlen(sapin[l]))
    p = my_strlen(sapin[l]) - 2;
  while (i <= p)
    sapin[l][i++] = '.';
  return (sapin);
}
