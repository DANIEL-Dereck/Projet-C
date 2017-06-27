/*
** my_putchar.c for my_putchar in /home/le-fra_g/minishel
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Fri May 16 16:42:40 2014 le-franc
** Last update Fri May 16 17:07:50 2014 le-franc
*/

#include "../include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
