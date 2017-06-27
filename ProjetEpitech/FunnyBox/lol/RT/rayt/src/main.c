/*
** main.c for main.c in /home/julien_t/Desktop/rayt
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Thu May  8 17:34:04 2014 julien_t
** Last update Tue May 27 10:46:13 2014 daniel_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "main.h"

void	parseur(char *filename)
{
  char	filecontent[1024];
  int	fd;

  if ((fd = open(filename, O_RDONLY)) == -1)
    {
      my_putstr("Open error.\n");
      exit(-1);
    }
  if ((read(fd, filecontent, 1025)) > 0)
    display(filecontent, filename);
  else
    my_putstr("Read error.\n");
}

void	display(char *str, char *filename)
{
  int	i;

  my_putchar('\n');
  my_putstr("FileName: ");
  my_putstr(filename);
  my_putchar('\n');
  i = -1;
  while (str[++i])
    display2(str, &i);
}

void	display2(char *str, int *i)
{
  if (str[*i] == '<' && str[*i + 1] == 'n' && str[*i + 2] == 'u')
    {
      while (str[*i] && str[++(*i)] != '>')
      my_putstr("Numero item: ");
      while (str[(*i)++] && str[*i] != '<')
	my_putchar(str[*i]);
      my_putchar('\n');
    }
  if (str[*i] == '<' && str[*i + 1] == 't' && str[*i + 2] == 'i')
    {
      while (str[*i] && str[++(*i)] != '>')
      my_putstr("title: ");
      while (str[(*i)++] && str[*i] != '<')
	my_putchar(str[*i]);
      my_putchar('\n');
    }
  display3(str, i);
}

void	display3(char *str, int *i)
{
  if (str[*i] == '<' && str[*i + 1] == 'l' && str[*i + 2] == 'i')
    {
      while (str[*i] && str[++(*i)] != '>')
      my_putstr("link: ");
      while (str[(*i)++] && str[*i] != '<')
	my_putchar(str[*i]);
      my_putchar('\n');
    }
  if (str[*i] == '<' && str[*i + 1] == 'd' && str[*i + 2] == 'e')
    {
      while (str[*i] && str[++(*i)] != '>')
      my_putstr("description: ");
      while (str[(*i)++] && str[*i] != '<')
	my_putchar(str[*i]);
      my_putchar('\n');
      my_putchar('\n');
    }
}

int	main(int ac, char **av)
{
  if (ac > 1)
    parseur(av[1]);
  else
    my_putstr("Usage: ./my_reader flux1.xml\n");
  return (0);
}
