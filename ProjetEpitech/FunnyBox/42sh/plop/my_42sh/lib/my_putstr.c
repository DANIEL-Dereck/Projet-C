/*
** my_putstr.c for int my_putstr(char *str) in /home/boucha_q/rendu/Piscine-C-Jour_04
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Thu Oct  3 12:57:25 2013 boucha_q
** Last update Tue May 20 16:13:44 2014 le-franc
*/

#include "../include/my.h"

void	my_putstr(char *str)
{
  int n;

  n = 0;
  while (str[n] != '\0')
    {
      my_putchar(str[n]);
      n = n + 1;
    }
}
