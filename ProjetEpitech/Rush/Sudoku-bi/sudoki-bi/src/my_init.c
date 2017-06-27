/*
** my_init.c for  in /home/bidard_v/rendu/sudoki-bi/src
** 
** Made by bidard_v
** Login   <bidard_v@epitech.net>
** 
** Started on  Sat Mar  1 15:27:23 2014 bidard_v
** Last update Sun Mar  2 13:34:15 2014 daniel_d
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "sudoku.h"
#include "my.h"

t_sudo	*my_init()
{
  int	i;
  t_sudo	*sudo;

  i = 0;
  sudo = malloc(sizeof(*sudo));
  sudo->boole = malloc(sizeof(int*) * 82);
  while (i < 82)
    sudo->boole[i++] = malloc(sizeof(int) * 5);
  if (sudo == NULL ||
      sudo->boole == NULL)
    return (NULL);
  sudo->boole[--i] = NULL;
  i = 0;
  while (sudo->boole[i])
    sudo->boole[i++][5] = '\0';
  return (sudo);
}
