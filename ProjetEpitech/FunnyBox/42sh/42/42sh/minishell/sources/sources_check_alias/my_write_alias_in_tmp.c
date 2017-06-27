/*
** my_write_in_tmp.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/alias/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 28 13:07:13 2014 bouchard alexandre
** Last update Mon May 19 16:06:11 2014 le-franc
*/

#include "../../include/sh.h"

void	my_write_alias_in_tmp(char *str, int fd_tmp)
{
  int	i;
  char	*str_tmp;

  i = 5;
  if ((str_tmp = malloc(sizeof(*str_tmp) * 2)) == NULL);
  else
    {
      write(fd_tmp, "alias\n", 6);
      while (str[++i] != '\0')
	{
	  if (str[i] != '\'')
	    {
	      str_tmp[0] = str[i];
	      write(fd_tmp, str_tmp, 1);
	    }
	}
      write(fd_tmp, "\n", 1);
    }
}
