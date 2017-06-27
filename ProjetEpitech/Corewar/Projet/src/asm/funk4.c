/*
** funk4.c for asm in /home/daniel_d/rendu/CPE_2014_Corewar-rom1/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr  8 11:18:38 2014 daniel_d
** Last update Sun Apr 13 22:46:19 2014 grasla_r
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

void	my_aff(char *param, int  fdnf, union1 *u, t_oct *oct)
{
  char **plop;
  int i;

  plop = malloc(sizeof(**plop) * 4);
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x10;
  write(fdnf, &u->tab[0], 1);
  oct->a = oct->a + 1;
  u->a = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u, oct);
}

void    my_ldi(char *param, int fdnf, union1 *u, t_oct *oct)
{
  my_printf("0x0a\n");
  my_printf("%s\n", param);
  u->a = 0x0a;
  write(fdnf, &u->tab[0], 1);
  oct->a = oct->a + 1;
}
