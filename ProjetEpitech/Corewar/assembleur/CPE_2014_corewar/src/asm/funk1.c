/*
** funk1.c for asm in /home/daniel_d/rendu/CPE_2014_Corewar-rom1/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr  8 11:06:06 2014 daniel_d
** Last update Sun Apr 13 18:50:17 2014 grasla_r
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

void	my_live(char *param, int fdnf, union1 *u, t_oct *oct)
{
  int i;
  char *nbr;
  int k;

  nbr = malloc(sizeof(*nbr) * 10);
  u->a = 0x01;
  write(fdnf, &u->tab[0], 1);
  if (param != NULL)
    {
      k = 0;
      i = 1;
      while (param[i] != '\0')
	nbr[k++] = param[i++];
      u->a = my_getnbr(nbr);
      write(fdnf, &u->tab[3], 1);
      write(fdnf, &u->tab[2], 1);
      write(fdnf, &u->tab[1], 1);
      write(fdnf, &u->tab[0], 1);
    }
  oct->a = oct->a + 5;
  my_putchar('a');
}

void	my_ld(char *param, int fdnf, union1 *u, t_oct *oct)
{
  char **plop;
  int i;

  plop = malloc(sizeof(**plop) * 4);
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x02;
  write(fdnf, &u->tab[0], 1);
  u->a  = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u, oct);
  my_putchar('b');
  oct->a = oct->a + 1;
}

void	my_st(char *param, int fdnf, union1 *u, t_oct *oct)
{
  char **plop;
  int i;

  plop = malloc(sizeof(**plop) * 4);
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x03;
  write(fdnf, &u->tab[0], 1);
  u->a  = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u, oct);
  my_putchar('c');
  oct->a = oct->a + 1;
}

void	my_add(char *param, int fdnf, union1 *u, t_oct *oct)
{
  char **plop;
  int i;

  plop = malloc(sizeof(**plop) * 4);
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x04;
  write(fdnf, &u->tab[0], 1);
  u->a = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u, oct);
  my_putchar('d');
  oct->a = oct->a + 1;
}

void	my_sub(char *param, int fdnf, union1 *u, t_oct *oct)
{
  char **plop;
  int i;

  plop = malloc(sizeof(**plop) * 4);
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x05;
  write(fdnf, &u->tab[0], 1);
  u->a  = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u, oct);
  my_putchar('e');
  oct->a = oct->a + 1;
}
