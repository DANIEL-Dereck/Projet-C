/*
** init.c for corewar/asm in /home/daniel_d/rendu/CPE_2014_Corewar/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Apr  2 16:47:17 2014 daniel_d
** Last update Sun Apr 13 23:34:32 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

int     my_whotwo(char *commande, char *param, union1 *u, t_oct *oct)
{
  if ((my_strcmp(commande, "zjmp")) == 2)
    my_zjmp(param, oct->fdnf, u, oct);
  else if ((my_strcmp(commande, "fork")) == 2)
    my_fork(param, oct->fdnf, u, oct);
  else if ((my_strcmp(commande, "aff")) == 2)
    my_aff(param, oct->fdnf, u, oct);
  else
    return (-1);
  return (0);
}

int    my_who(char *commande, char *param, union1 *u, t_oct *oct)
{
  int   verif;

  verif = 0;
  if ((my_strcmp(commande, "live")) == 2)
    my_live(param, oct->fdnf, u, oct);
  else if ((my_strcmp(commande, "ld")) == 2)
    my_ld(param, oct->fdnf, u, oct);
  else if ((my_strcmp(commande, "st")) == 2)
    my_st(param, oct->fdnf, u, oct);
  else if ((my_strcmp(commande, "add")) == 2)
    my_add(param, oct->fdnf, u, oct);
  else if ((my_strcmp(commande, "sub")) == 2)
    my_sub(param, oct->fdnf, u, oct);
  else if ((my_strcmp(commande, "and")) == 2)
    my_and(param, oct->fdnf, u, oct);
  else if ((my_strcmp(commande, "or")) == 2)
    my_or(param, oct->fdnf, u, oct);
  else if ((my_strcmp(commande, "xor")) == 2)
    my_xor(param, oct->fdnf, u, oct);
  else
    verif = my_whotwo(commande, param, u, oct);
  return (verif);
}

char    **my_tab(char *buffer, char **commande)
{
  int i;
  int k;
  int x;

  i = 0;
  k = 0;
  x = 0;
  while (buffer[i] != '\0' && buffer[i] != COMMENT_CHAR)
    {
      if ((commande[k] = malloc(sizeof(*commande) * 256)) == NULL)
	return (NULL);
      while (buffer[i] == ' ' || buffer[i] == '\t')
        i = i + 1;
      while (buffer[i] != ' ' && buffer[i] != '\t' &&
	     buffer[i] != '\0' && buffer[i] != '\n' &&
	     buffer[i] != COMMENT_CHAR)
	commande[k][x++] = buffer[i++];
      commande[k][x] = '\0';
      k = k + 1;
      x = 0;
    }
  return (commande);
}
