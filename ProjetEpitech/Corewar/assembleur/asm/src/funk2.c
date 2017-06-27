/*
** funk1.c for asm in /home/daniel_d/rendu/CPE_2014_Corewar-rom1/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr  8 11:06:06 2014 daniel_d
** Last update Fri Apr 11 01:04:20 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

void	my_and(char *param, int fdnf, union1 *u)
{
  char **plop;
  int i;

  plop = malloc(sizeof(**plop) * 4);
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x06;
  write(fdnf, &u->tab[0], 1);
  u->a  = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u);
}

void	my_or(char *param, int fdnf, union1 *u)
{
  char **plop;
  int i;

  plop = malloc(sizeof(**plop) * 4);
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x07;
  write(fdnf, &u->tab[0], 1);
  u->a  = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u);
}

void	my_xor(char *param, int fdnf, union1 *u)
{
  char **plop;
  int i;

  plop = malloc(sizeof(**plop) * 4);
  plop = my_param(param, plop);
  i = octalisation(plop);
  u->a = 0x08;
  write(fdnf, &u->tab[0], 1);
  u->a  = i;
  write(fdnf, &u->tab[0], 1);
  my_value_write(fdnf, plop, u);
}

void	my_zjmp(char *param, int fdnf, union1 *u)
{
  my_printf("0x09\n");
  my_printf("%s\n", param);
  u->a = 0x09;
  write(fdnf, &u->tab[0], 1);
}

void	my_ldi(char *param, int fdnf, union1 *u)
{
  my_printf("0x0a\n");
  my_printf("%s\n", param);
  u->a = 0x0a;
  write(fdnf, &u->tab[0], 1);
}
