/*
** main.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/my_read/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Thu Apr 24 14:09:45 2014 bouchard alexandre
** Last update Mon May 12 15:41:12 2014 daniel_d
*/

#include "../include/my_read.h"

char	*my_read()
{
  char	*buff;
  char	*tmp;
  int	rd;

  rd = 0;
  if ((buff = malloc(sizeof(char *) * 1)) == NULL)
    return (NULL);
  if ((tmp = malloc(sizeof(char *) * 2)) == NULL)
    return (NULL);
  buff[0] = '\0';
  tmp[1] = '\0';
  while (42)
    {
      if ((rd = read(0, tmp, 1)) == -1)
	return (NULL);
      if (tmp[0] == '\n')
	return (buff);
      buff = my_strcat(buff, tmp);
    }
  return (buff);
}

int	prompt()
{
  char	*buff;

  while (42)
    {
      my_putstr("&>");
      buff = my_read();
      my_putstr(buff);
      puts("");
    }
  return (0);
}
