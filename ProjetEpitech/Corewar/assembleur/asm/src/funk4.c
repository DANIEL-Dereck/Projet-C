/*
** funk4.c for asm in /home/daniel_d/rendu/CPE_2014_Corewar-rom1/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr  8 11:18:38 2014 daniel_d
** Last update Tue Apr  8 15:47:07 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "asm.h"
#include "op.h"

void	my_aff(char *param, int  fdnf, union1 *u)
{
  my_printf("0x10\n");
  my_printf("%s\n", param);
  u->a = 0x10;
  write(fdnf, &u->tab[0], 1);
}
