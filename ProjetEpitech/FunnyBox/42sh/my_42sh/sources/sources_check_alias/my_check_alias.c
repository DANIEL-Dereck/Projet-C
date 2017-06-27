/*
** my_check_alias.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/alias/sources
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 28 10:38:41 2014 bouchard alexandre
** Last update Tue May 20 16:39:31 2014 le-franc
*/

#include "../../include/sh.h"
#include "../../include/my.h"

void	my_check_alias(char *str, int countligne_sh, int fd_tmp)
{
  char	*tmp;
  int	i;

  i = -1;
  tmp = malloc(sizeof(*tmp) * 6);
  while (str[++i] != '\0' && i != 5)
    tmp[i] = str[i];
  tmp[i] = '\0';
  if ((my_strcmp(tmp, "alias")) == -1)
    printf("Alias non valide ligne:%d\n", countligne_sh);
  else if (str[5] != ' ')
    printf("Oublie d'espace après l'alias ligne:%d\n", countligne_sh);
  else
    my_check_equal(str, countligne_sh, fd_tmp);
}
