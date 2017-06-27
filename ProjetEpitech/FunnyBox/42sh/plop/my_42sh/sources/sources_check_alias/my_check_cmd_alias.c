/*
** my_check_cmd_alias.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/alias/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 28 11:42:10 2014 bouchard alexandre
** Last update Tue May 20 16:40:03 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

void	my_check_cmd_alias(char *str, int countline_sh, int fd_tmp)
{
  int	i;
  int	count;
  int	count_erreur;

  i = -1;
  count = 0;
  count_erreur = 0;
  while (str[++i] != '\0')
    if (str[i] == '\'')
      count++;
  if (count == 0)
    printf("There are no simple cote in cmd line:%d\n", countline_sh);
  else if ((count % 2) == 1)
    printf("Need some simple cote in cmd alias line:%d\n", countline_sh);
  else
    {
      while (str[i] != '\'')
	if (str[i] != '\'' && str[i] != '\n' && str[i--] != '\0')
	  count_erreur++;
      if (count_erreur > 0)
	printf("Write nothing after command,line:%d\n", countline_sh);
      else
	my_write_alias_in_tmp(str, fd_tmp);
    }
}
