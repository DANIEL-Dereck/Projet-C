/*
** init.c for corewar/asm in /home/daniel_d/rendu/CPE_2014_Corewar/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Apr  2 16:47:17 2014 daniel_d
** Last update Sun Apr 13 15:00:03 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

int     my_whotwo(char *commande, char *param, int fdnf, union1 *u)
{
  if ((my_strcmp(commande, "zjmp")) == 2)
    my_zjmp(param, fdnf,  u);
  else if ((my_strcmp(commande, "ldi")) == 2)
    my_ldi(param, fdnf,  u);
  else if ((my_strcmp(commande, "sti")) == 2)
    my_sti(param, fdnf,  u);
  else if ((my_strcmp(commande, "fork")) == 2)
    my_fork(param, fdnf,  u);
  else if ((my_strcmp(commande, "lld")) == 2)
    my_lld(param, fdnf,  u);
  else if ((my_strcmp(commande, "lldi")) == 2)
    my_lldi(param, fdnf,  u);
  else if ((my_strcmp(commande, "lfork")) == 2)
    my_lfork(param, fdnf,  u);
  else if ((my_strcmp(commande, "aff")) == 2)
    my_aff(param, fdnf,  u);
  else
    return (-1);
  return (0);
}

int    my_who(char *commande, char *param, int fdnf, union1 *u)
{
  int   verif;

  verif = 0;
  if ((my_strcmp(commande, "live")) == 2)
    my_live(param, fdnf, u);
  else if ((my_strcmp(commande, "ld")) == 2)
    my_ld(param, fdnf,  u);
  else if ((my_strcmp(commande, "st")) == 2)
    my_st(param, fdnf,  u);
  else if ((my_strcmp(commande, "add")) == 2)
    my_add(param, fdnf,  u);
  else if ((my_strcmp(commande, "sub")) == 2)
    my_sub(param, fdnf,  u);
  else if ((my_strcmp(commande, "and")) == 2)
    my_and(param, fdnf,  u);
  else if ((my_strcmp(commande, "or")) == 2)
    my_or(param, fdnf,  u);
  else if ((my_strcmp(commande, "xor")) == 2)
    my_xor(param, fdnf,  u);
  else
    verif = my_whotwo(commande, param, fdnf, u);
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
  while (buffer[i] != '\0')
    {
      if ((commande[k] = malloc(sizeof(*commande) * 256)) == NULL)
	return (NULL);
      while (buffer[i] == ' ' || buffer[i] == '\t')
        i = i + 1;
      while (buffer[i] != ' ' && buffer[i] != '\t' &&
	     buffer[i] != '\0' && buffer[i] != '\n')
	commande[k][x++] = buffer[i++];
      commande[k][x] = '\0';
      k = k + 1;
      x = 0;
    }
  return (commande);
}
