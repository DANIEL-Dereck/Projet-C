/*
** my_putchar.c for my_putchar in /home/boucha_q/rendu/Piscine-C-lib/my
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Oct 21 09:15:14 2013 boucha_q
** Last update Mon Apr 14 13:55:10 2014 bouchard alexandre
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
