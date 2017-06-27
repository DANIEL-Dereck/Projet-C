/*
** fillfuncpath.c for  in /home/boucha_q/rendu/PSU_42/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 14 10:33:42 2014 bouchard alexandre
** Last update Mon May 19 16:17:05 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

int     my_strlen_space(char *str)
{
  int   i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  return (i);
}

char    *fill_func_path(char *path, char *buff)
{
  char *str;
  int   i;
  int   j;

  j = 0;
  i = my_strlen_space(buff);

  if ((str = malloc(sizeof(*str) * (my_strlen(path) + i + 1))) == NULL)
    return (NULL);
  while (path[j] != '\0')
    {
      str[j] = path[j];
      j++;
    }
  i = 0;
  while (buff[i] != '\0' && buff[i] != ' ')
    str[j++] = buff[i++];
  str[j] = '\0';
  return (str);
}
