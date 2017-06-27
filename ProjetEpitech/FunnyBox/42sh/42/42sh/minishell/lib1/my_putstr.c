/*
** my_putstr.c for my_putstr.c in /home/le-fra_g/minishel
** 
** Made by le-franc
** Login   <le-fra_g@epitech.net>
** 
** Started on  Fri May 16 16:55:59 2014 le-franc
** Last update Fri May 16 16:57:21 2014 le-franc
*/

#include "../include/my.h"

int	my_putstr(char *str)
{
  if (str)
    write(1, str, my_strlen(str));
  return (1);
}
