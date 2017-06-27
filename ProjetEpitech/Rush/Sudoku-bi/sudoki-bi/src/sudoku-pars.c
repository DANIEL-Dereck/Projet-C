/*
** sudoku-pars.c for rush in /home/daniel_d/rendu/Rush-Sudoku-bi/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat Mar  1 09:01:34 2014 daniel_d
** Last update Sun Mar  2 18:20:39 2014 daniel_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "sudoku.h"
#include "my.h"

char	**epur_sudo(char **tab, t_sudo *sudo)
{
  sudo->x = 0;
  sudo->y = 0;
  while (tab[sudo->y] != NULL)
    {
      while (tab[sudo->y][sudo->x] != '\0')
	{
	  if ((sudo->x % 2) == 1 && tab[sudo->y][sudo->x] == '.')
	    tab[sudo->y][sudo->x] = ' ';
	  sudo->x++;
	}
      sudo->x = 0;
      sudo->y++;
    }
  return (tab);
}

void	my_affichage(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_printf("%s\n", tab[i]);
      if ((tab[i + 1] != NULL) && my_strcmp(tab[i], tab[i + 1]) == 2)
	my_printf("####################\n");
      i++;
    }
}

int	sudokumain(int fd)
{
  int	r;
  int	i;
  char	**tab;
  char	buffer[4096];
  t_sudo	*sudo;

  i = 0;
  sudo = my_init();
  if ((r = read(fd, buffer, 4095)) == -1)
    return (-1);
  while (buffer[i])
    {
      if (buffer[i] == ' ')
	buffer[i] = '.';
      i++;
    }
  i = 0;
  tab = my_str_to_wordtab(buffer);
  tab = epur_sudo(tab, sudo);
  my_affichage(tab);
  sudo->x = 0;
  sudo->y = 1;
  sudo->x2 = 0;
  sudo->y2 = 0;
  //my_res(tab, sudo);
  //my_free(tab, sudo);
  return (0);
}
