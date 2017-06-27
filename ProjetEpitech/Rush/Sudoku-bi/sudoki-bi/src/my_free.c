/*
** my_free.c for  in /home/bidard_v/rendu/sudoki-bi/src
** 
** Made by bidard_v
** Login   <bidard_v@epitech.net>
** 
** Started on  Sat Mar  1 14:27:22 2014 bidard_v
** Last update Sun Mar  2 13:28:40 2014 daniel_d
*/

#include <stdlib.h>
#include "my.h"
#include "sudoku.h"

void	my_free(char **sudo, t_sudo *sud)
{
  int	i;
  int	k;

  i = 0;
  k = 82;
  while (sudo[i])
    free(sudo[i++]);
  free(sudo);
  i = 0;
  while (k > 0)
    {
      my_printf("debug 1\n");
      free(sud->boole[i++]);
      my_printf("debug 2\n");
      k--;
    }
  free(sud->boole);
  free(sud);
}
