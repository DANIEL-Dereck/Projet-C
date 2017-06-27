/*
** my_tmp_alias.c for  in /home/boucha_q/rendu/PSU/PSU_2014_42/my_42sh/sources/sources_check_alias
** 
** Made by bouchard alexandre
** Login   <boucha_q@epitech.net>
** 
** Started on  Fri May 16 17:13:14 2014 bouchard alexandre
** Last update Sun May 25 17:21:15 2014 bouchard alexandre
*/

#include "../../include/sh.h"
#include "../../include/my.h"

void     my_tmp_alias()
{
  int   fd_sh;
  int   fd_tmp;

  fd_sh = open("test.sh", O_RDONLY);
  fd_tmp = open("tmp.sh",
		O_TRUNC | O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
  my_check_sh(fd_sh, fd_tmp);
  close(fd_sh);
  close(fd_tmp);
}
