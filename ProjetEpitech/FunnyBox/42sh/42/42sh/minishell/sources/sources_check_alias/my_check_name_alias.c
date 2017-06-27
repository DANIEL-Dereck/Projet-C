/*
** my_check_name_alias.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/alias/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 28 11:10:42 2014 bouchard alexandre
** Last update Mon May 19 16:14:03 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

void	my_check_name_alias(char *str, int countline_sh, int fd_tmp)
{
  int	i;
  int	count;

  i = 5;
  count = 0;
  while (str[++i] != '\0' && str[i] != '=')
    {
      if (str[i] >= 65 && str[i] <= 90);
      else if (str[i] >= 97 && str[i] <= 122);
      else
	count++;
    }
  if (count > 0)
    printf("Invalid name alias ligne %d: only alpha caract\n", countline_sh);
  else
    my_check_cmd_alias(str, countline_sh, fd_tmp);
}
