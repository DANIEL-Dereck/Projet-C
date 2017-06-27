/*
** main.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/alias
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Apr 28 09:01:37 2014 bouchard alexandre
** Last update Mon Apr 28 13:50:58 2014 bouchard alexandre
*/

#include "proto.h"

int	main()
{
  int	fd_sh;
  int	fd_tmp;

  fd_sh = open("test.sh", O_RDONLY);
  fd_tmp = open("tmp.sh", O_TRUNC | O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
  my_check_sh(fd_sh, fd_tmp);
  return (0);
}
