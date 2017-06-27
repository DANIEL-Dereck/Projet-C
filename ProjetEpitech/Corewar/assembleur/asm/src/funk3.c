/*
** funk1.c for asm in /home/daniel_d/rendu/CPE_2014_Corewar-rom1/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr  8 11:06:06 2014 daniel_d
** Last update Tue Apr  8 15:46:51 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

void	my_sti(char *param, int fdnf, union1 *u)
{
  my_printf("0x0b\n");
  my_printf("%s\n", param);
  u->a = 0x0b;
  write(fdnf, &u->tab[0], 1);
}

void	my_fork(char *param, int fdnf, union1 *u)
{
  my_printf("0x0c\n");
  my_printf("%s\n", param);
  u->a = 0x0c;
  write(fdnf, &u->tab[0], 1);
}

void	my_lld(char *param, int fdnf, union1 *u)
{
  my_printf("0x0d\n");
  my_printf("%s\n", param);
  u->a = 0x0d;
  write(fdnf, &u->tab[0], 1);
}

void	my_lldi(char *param, int fdnf, union1 *u)
{
  my_printf("0x0e\n");
  my_printf("%s\n", param);
  u->a = 0x0e;
  write(fdnf, &u->tab[0], 1);
}

void	my_lfork(char *param, int fdnf, union1 *u)
{
  my_printf("0x0f\n");
  my_printf("%s\n", param);
  u->a = 0x0f;
  write(fdnf, &u->tab[0], 1);
}
