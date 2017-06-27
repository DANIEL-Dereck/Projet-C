/*
** main.c for test in /home/daniel_d/rendu/Projet_fini/rush_my_tar/etape_1
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Dec  6 14:01:00 2013 daniel_d
** Last update Fri Dec  6 14:03:20 2013 daniel_d
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lib/my/my.h"

int main(int ac, char **av)
{
  static int fd;
  char *s;

  fd = open(av[1], O_RDONLY);
  while ((s = get_next_line(fd)))
    {
      my_putstr(s);
      free(s);
      my_putchar('\n');
    }
  my_putchar('\n');
  return (0);
}

