/*
** my_get_nextline.c for my_get_nextline in /home/boucha_q/rendu/CPE_2013_getnextline
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Wed Apr  2 09:15:55 2014 bouchard alexandre
** Last update Sun May 25 17:05:14 2014 le-franc
*/

#include "../include/sh.h"

char	*my_get_nextline(int fd)
{
  char	*str;
  char	buff;
  int	i;
  int	ind;

  i = 0;
  ind = 0;
  if ((str = malloc(sizeof(*str))) == NULL)
    return (NULL);
  while (read(fd, &buff, 1) != 0 && buff && buff != '\n')
    {
      str = realloc(str, i + 2);
      if (buff && buff != '\n')
	str[i++] = buff;
      ind = 1;
    }
  str[i] = '\0';
  if (!str[0] && ind == 0)
    return (NULL);
  return (str);
}
