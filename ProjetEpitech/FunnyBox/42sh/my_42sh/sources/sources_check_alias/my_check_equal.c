/*
** my_check_equal.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/alias/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 28 10:57:01 2014 bouchard alexandre
** Last update Tue May 20 16:41:11 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

void	my_check_equal(char *str, int countline_sh, int fd_tmp)
{
  int	i;
  int	count;

  count = 0;
  i = -1;
  while (str[++i] != '\0' && str[i] != '\'')
    {
      if (str[i] == '=')
	count++;
    }
  if (count == 1)
    my_check_name_alias(str, countline_sh, fd_tmp);
  else
    printf("Il y %d égals écrit à la ligne %d\n", count, countline_sh);
}
