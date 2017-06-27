/*
** init_oct.c for init in /home/daniel_d/rendu/assembleur/asmjv/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Apr 13 21:15:01 2014 daniel_d
** Last update Sun Apr 13 21:18:54 2014 daniel_d
*/

#include <stdio.h>
#include <stdlib.h>
#include "asm.h"

t_oct	*init_oct(t_oct *oct, int fdnf)
{
  oct->a = 2176;
  oct->pos = 0;
  if ((oct->oct_pos = malloc(sizeof(*oct->oct_pos) * 256)) == NULL)
    return (NULL);
  if ((oct->label = malloc(sizeof(**oct->label) * 256)) == NULL)
    return (NULL);
  oct->fdnf = fdnf;
  return (oct);
}
