/*
** my_res.c for  in /home/bidard_v/rendu/sudoki-bi/src
** 
** Made by bidard_v
** Login   <bidard_v@epitech.net>
** 
** Started on  Sat Mar  1 16:43:35 2014 bidard_v
** Last update Sun Mar  2 03:17:11 2014 bidard_v
*/

#include <stdio.h>
#include "sudoku.h"
#include "my.h"

void	resolv(t_sudo *sudo, char value)
{
  printf("%c, %d, %d\n", value, sudo->x2, sudo->y2);
  sudo->boole[sudo->y2][sudo->x2] =  value;
  sudo->boole[sudo->y2][sudo->x2 + 1] =  sudo->x2;
  sudo->boole[sudo->y2][sudo->x2 + 2] =  sudo->y2;
  sudo->boole[sudo->y2][sudo->x2 + 3] =  0;
}

void	my_res(char **tab, t_sudo *sudo)
{
  if (sudo->y != 10)
    {
      sudo->x += 2;
      resolv(sudo, tab[sudo->y][sudo->x]);
      sudo->x2++;
      if (sudo->x == 18)
	{
	  sudo->x = 0;
	  sudo->x2 = 0;
	  sudo->y++;
	  sudo->y2++;
	}
      my_res(tab, sudo);
    }
}
