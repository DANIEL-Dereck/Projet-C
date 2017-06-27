/*
** verifligne.c for verifligne in /home/daniel_d/rendu/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Apr 13 15:40:32 2014 daniel_d
** Last update Sun Apr 13 18:14:43 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

int	veriffunkbis(char *command)
{
  if (my_strcmp(command, "xor") == 2)
    return (0);
  else if (my_strcmp(command, "zjmp") == 2)
    return (0);
  else if (my_strcmp(command, "ldi") == 2)
    return (0);
  else if (my_strcmp(command, "sti") == 2)
    return (0);
  else if (my_strcmp(command, "fork") == 2)
    return (0);
  else if (my_strcmp(command, "lld") == 2)
    return (0);
  else if (my_strcmp(command, "lldi") == 2)
    return (0);
  else if (my_strcmp(command, "lfork") == 2)
    return (0);
  else if (my_strcmp(command, "aff") == 2)
    return (0);
  else
    return (-1);
}

int	veriffunk(char *command)
{
  int	verif;

  verif = 0;
  if (my_strcmp(command, ".name") == 2)
    return (0);
  else if (my_strcmp(command, ".comment") == 2)
    return (0);
  else if (my_strcmp(command, "live") == 2)
    return (0);
  else if (my_strcmp(command, "ld") == 2)
    return (0);
  else if (my_strcmp(command, "st") == 2)
    return (0);
  else if (my_strcmp(command, "add") == 2)
    return (0);
  else if (my_strcmp(command, "sub") == 2)
    return (0);
  else if (my_strcmp(command, "and") == 2)
    return (0);
  else if (my_strcmp(command, "or") == 2)
    return (0);
  else
    verif = veriffunkbis(command);
  return (verif);
}

int	verifligne(char **command, int ligne)
{
  int	v;

  if (command[0] == NULL)
    return (0);
  v = my_needposchar(command[0], ':');
  if (v == 0)
    {
      if (veriffunk(command[0]) == -1)
	{
	  my_printf("ERROR: ligne %d \"%s\" incorrecte\n", ligne, command[0]);
	  return (ERROR3);
	}
    }
  else if (v > 0)
    {
      if (veriffunk(command[1]) == -1)
	{
	  my_printf("ERROR: ligne %d \"%s\" incorrecte\n", ligne, command[1]);
	  return (ERROR3);
	}
    }
  else
    return (0);
  return (0);
}
