/*
** jesus.c for jesus in /home/daniel_d/CPE_2014_corewar/src/asm
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Apr 13 23:21:08 2014 daniel_d
** Last update Sun Apr 13 23:24:28 2014 daniel_d
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "op.h"

void    jesus1(int k, char **plop, int i, union1 *u)
{
  k = my_value(plop[i]);
  u->a = k;
}

void    jesus2(int fdnf, union1 *u, t_oct *oct)
{
  write(fdnf, &u->tab[0], 1);
  oct->a = oct->a + REG_SIZE;
}

void    jesus_back1(int fdnf, int x, t_oct *oct, union1 *u)
{
  x = DIR_SIZE - 1;
  while (x >= 0)
    write(fdnf, &u->tab[x--], 1);
  oct->a = oct->a + DIR_SIZE;
}

void    jesus_back2(int fdnf, int x, t_oct *oct, union1 *u)
{
  x = IND_SIZE - 1;
  while (x >= 0)
    write(fdnf, &u->tab[x--], 1);
  oct->a = oct->a + IND_SIZE;
}
