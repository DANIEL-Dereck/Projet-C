/*
** my_check_sh.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/alias
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 28 10:16:02 2014 bouchard alexandre
** Last update Mon May 19 16:15:12 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

void	my_check_sh(int fd_sh, int fd_tmp)
{
  char	*line;
  int	countline_sh;

  countline_sh = 0;
  while ((line = my_get_nextline(fd_sh)) != NULL)
      my_check_alias(line, ++countline_sh, fd_tmp);
}
