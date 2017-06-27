/*
** encodeur.c for encod in /home/daniel_d/CPE_2014_corewar/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Apr 13 23:00:30 2014 daniel_d
** Last update Sun Apr 13 23:33:26 2014 daniel_d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

void    my_encod(char **commande, t_oct *oct)
{
  int   i;
  int   x;
  union union1 *u;

  u = malloc(sizeof(*u));
  i = 0;
  while (commande[i] != NULL && commande[i][0] != '\0' && i <= 2)
    {
      x = my_strlen(commande[i]) - 1;
      if (commande[i][x] != LABEL_CHAR)
        my_who(commande[i], commande[i + 1], u, oct);
      else if (commande[i][x] == LABEL_CHAR)
        {
          oct->label[oct->pos] = my_str_cpy(commande[i], oct->label[oct->pos]);
          oct->oct_pos[oct->pos] = oct->a;
          oct->pos = oct->pos + 1;
        }
      i = i + 1;
    }
  free(u);
}

int     encod_fin(int ligne, char *buffer, char **commande, t_oct *oct)
{
  commande[3] = NULL;
  commande = my_tab(buffer, commande);
  if (verifligne(commande, ligne) == ERROR3)
    return (ERROR3);
  if (my_header(oct->fdnf, buffer, ligne) == ERROR3)
    return (ERROR3);
  my_encod(commande, oct);
  free(commande);
  return (0);
}

int     encoding_file(int fd, int fdnf, char *file)
{
  char  **commande;
  char  *buffer;
  int   ligne;
  int   len;
  t_oct *oct;

  ligne = 1;
  if ((oct = malloc(sizeof(*oct))) == NULL)
    return (ERROR1);
  len = my_size(fd);
  oct = init_oct(oct, fdnf);
  close(fd);
  while ((buffer = get_next_line((fd = open(file, O_RDONLY)), len)) != NULL)
    {
      if ((commande = malloc(sizeof(commande) * 4)) == NULL)
        return (ERROR1);
      if (encod_fin(ligne, buffer, commande, oct) == ERROR3)
        return (ERROR3);
      if (close(fd) == -1)
        return (ERROR3);
      ligne++;
    }
  if (close(fdnf) == ERROR1)
    return (ERROR3);
  return (0);
}
