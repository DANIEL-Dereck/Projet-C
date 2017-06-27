/*
** my_check_buff_for_alias.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/exec_alias/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 28 15:03:32 2014 bouchard alexandre
** Last update Mon May 19 16:16:16 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

char	*my_cmd_buff_for_alias(char *buff, char *line)
{
  char	*tmp;
  char	*tmp1;
  int	i;
  int	j;

  i = -1;
  j = -1;
  tmp = malloc(sizeof(*tmp) * 1000);
  tmp1 = malloc(sizeof(*tmp1) * 1000);
  while (line[++i] != '\0' && line[i] != '=')
    tmp[i] = line[i];
  tmp[i] = '\0';
  if ((my_strcmp(buff, tmp)) == 0)
    {
      while (line[++i] != '\0')
	tmp1[++j] = line[i];
      tmp1[++j] = '\0';
      if (tmp1 != NULL)
	return (tmp1);
      return (NULL);
    }
  return (NULL);
}
