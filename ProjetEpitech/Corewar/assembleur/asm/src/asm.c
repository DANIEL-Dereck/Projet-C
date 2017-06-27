/*
** asm.c for asm in /home/daniel_d/rendu/PSU_2014_Corewar/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Mar 17 09:51:39 2014 daniel_d
** Last update Mon Apr 14 15:27:32 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "asm.h"

void	my_encod(char **commande, int fdnf)
{
  int	i;
  int	x;
  union union1 *u;

  u = malloc(sizeof(*u));
  i = 0;
  while (commande[i] != NULL && commande[i][0] != '\0' && i != 2)
    {
      x = my_strlen(commande[i]) - 1;
      if (commande[i][x] != ':')
	my_who(commande[i], commande[i + 1], fdnf, u);
      i = i + 1;
    }
   my_putchar('\n');
}

int	encoding_file(int fd, int fdnf, char *file)
{
  char	**commande;
  char	*buffer;
  int	ligne;

  if (file == NULL)
    return (0);
  while ((buffer = get_next_line(fd)) != NULL)
    {
      my_printf("%s\n", buffer);
      if ((commande = malloc(sizeof(commande) * 3)) == NULL)
	return (ERROR1);
      commande = my_tab(buffer, commande);
      if (verifligne(commande, ligne) == ERROR3)
	return (ERROR3);
      if (my_header(fdnf, commande, ligne) == ERROR3)
	return (ERROR3);
      my_encod(commande, fdnf);
      if (close(fd) == -1)
	return (ERROR3);
      ligne++;
    }
  if (close(fdnf) == ERROR1)
    return (ERROR3);
  return (0);
}

char	*rename_file(char *src,  char *dest)
{
  int	i;
  int	v;

  i = 0;
  v = 0;
  if (src == NULL)
    return (NULL);
  while (src[i] != '\0' && v != 1)
    {
      if (src[i] == '.')
	if (src[i + 1] == 's')
	  if (src[i + 2] == '\0')
	    v = 1;
      if (v == 0)
	dest[i] = src[i];
      if (v == 0)
	i++;
    }
  if (v == 0)
    return (NULL);
  dest[i++] = '.';
  dest[i++] = 'c';
  dest[i++] = 'o';
  dest[i] = 'r';
  return (dest);
}

int	verif_file(char *file)
{
  int	i;

  i = 0;
  while (file[i] != '\0')
    {
      if (file[i] == '.')
	if (file[i + 1] == 's')
	  if (file[i + 2] == '\0')
	    return (0);
      i++;
    }
  my_printf("ERROR : Bad file\n");
  return (ERROR2);
}

int 	assembleur_main(char *file)
{
  char	*new_name;
  int	fd_new_file;
  int	fd_file;

  if ((fd_file = open(file, O_RDONLY)) == ERROR1)
    return (ERROR1);
  if (verif_file(file) == ERROR2)
    return (ERROR2);
  if ((new_name = malloc(sizeof(*new_name) * (my_strlen(file) + 3))) == NULL)
    return (ERROR3);
  if ((new_name = rename_file(file, new_name)) == NULL)
    free(new_name);
  if (new_name == NULL)
    return (ERROR2);
  if ((fd_new_file = open(new_name, O_CREAT | O_RDWR | O_TRUNC ,
                   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == ERROR1)
    {
      free(new_name);
      return (ERROR3);
    }
  free(new_name);
  if (encoding_file(fd_file, fd_new_file, file) == ERROR3)
    return (ERROR3);
  return (0);
}
