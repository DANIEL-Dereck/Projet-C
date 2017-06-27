/*
** main.c for Prog in /home/daniel_d/Name_Prog
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Dec 12 09:25:38 2013 daniel_d
** Last update Sun Mar  2 17:22:51 2014 daniel_d
*/

#include <fcntl.h>
#include <stdlib.h>
#include "sudoku.h"
#include "my.h"

int	error(char **av, char **envp, int fd)
{
  if (fd <= 0)
    {
      my_printf("L'argument %s est faux\n", av[1]);
      return (-1);
    }
  if (envp[0] == NULL)
    {
      my_printf("Environment missing\n");
      return (-1);
    }
  return (0);
}

int main(int ac, char **av, char **envp)
{
  int	fd;

  fd = 0;
  if (ac != 1)
    {
      fd = open(av[1], O_RDONLY);
      if (error(av, envp, fd) == -1)
	return (-1);
    }
  sudokumain(fd);
  return (0);
}
