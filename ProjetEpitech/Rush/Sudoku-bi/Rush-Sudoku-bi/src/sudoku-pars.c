/*
** sudoku-pars.c for rush in /home/daniel_d/rendu/Rush-Sudoku-bi/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat Mar  1 09:01:34 2014 daniel_d
** Last update Sat Mar  1 17:40:07 2014 daniel_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sudoku.h"
#include "my.h"

void	res()
{
  
}

char	**epur_sudo(char **sudo)
{
  int	k;
  int	i;

  i = 1;
  k = 0;
  while (sudo[i] != NULL)
    {
      while (sudo[i][k] != '\0')
	{
	  if ((k % 2) == 1 && sudo[i][k] == NOP)
	    sudo[i][k] = ' ';
	  k++;
	}
      k = 0;
      i++;
    }
  return (sudo);
}

int	sudokumain(char **av)
{
  char	**sudo;
  char	buffer[4096];
  int	r;
  int	fd;
  int	i;

  i = 0;
  if ((fd = open(av[1], O_RDONLY)) == ERROR)
    return (ERROR);
  if ((r = read(fd, buffer, 4095)) == ERROR)
    return (ERROR);
  if (close(fd) == ERROR)
    return (ERROR);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == ' ')
	buffer[i] = NOP;
      i++;
    }
  i = 0;
  sudo = my_str_to_wordtab(buffer);
  sudo = epur_sudo(sudo);
  while (sudo[i] != NULL && sudo[i + 1] != NULL)
    {
      my_printf("%s\n", sudo[i]);
      if (my_strcmp(sudo[i], sudo[i + 1]) == 2)
	my_printf("####################\n");
      i++;
    }
  res();
  return (0);
}
