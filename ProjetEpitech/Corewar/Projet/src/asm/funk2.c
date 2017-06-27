/*
** funk1.c for asm in /home/daniel_d/rendu/CPE_2014_Corewar-rom1/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr  8 11:06:06 2014 daniel_d
** Last update Sun Apr 13 23:30:15 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

void	my_and(char *param, int fdnf, union1 *u, t_oct *oct)
{
  char **plop;
  int i;

  if ((plop = malloc(sizeof(**plop) * 4)) == NULL)
    return;
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x06;
  write(fdnf, &u->tab[0], 1);
  u->a  = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u, oct);
  oct->a = oct->a + 1;
}

void	my_or(char *param, int fdnf, union1 *u, t_oct *oct)
{
  char **plop;
  int i;

  if ((plop = malloc(sizeof(**plop) * 4)) == NULL)
    return;
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x07;
  write(fdnf, &u->tab[0], 1);
  u->a  = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u, oct);
  oct->a = oct->a + 1;
}

void	my_xor(char *param, int fdnf, union1 *u, t_oct *oct)
{
  char **plop;
  int i;

  if ((plop = malloc(sizeof(**plop) * 4)) == NULL)
    return;
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x08;
  write(fdnf, &u->tab[0], 1);
  u->a  = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u, oct);
  oct->a = oct->a + 1;
}

void	zjmpbis(t_oct *oct, int k, int x, int fdnf)
{
  k = oct->oct_pos[x];
  k = oct->a - k;
  x = 0xff;
  write(fdnf, &x, 1);
  k = k * (-1);
  write(fdnf, &k, 1);
}

void	my_zjmp(char *param, int fdnf, union1 *u, t_oct *oct)
{
  char **plop;
  int x;
  int k;

  if ((plop = malloc(sizeof(**plop) * 4)) == NULL)
    return;
  plop = my_param(param, plop);
  u->a = 0x09;
  write(fdnf, &u->tab[0], 1);
  k = 0;
  x = oct->pos - 1;
  plop[0] = my_label(plop[0]);
  while (oct->label[x] != NULL && k != 2 && x != -1)
    {
      k = my_strcmp(oct->label[x], plop[0]);
      if (k == 2)
	zjmpbis(oct, k, x, fdnf);
      x = x - 1;
    }
  oct->a = oct->a + 1;
}
