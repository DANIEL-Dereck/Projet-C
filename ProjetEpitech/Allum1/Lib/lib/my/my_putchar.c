/*
** my_putchar.c for my_putchar.c in /home/daniel_d/rendu/Piscine-C-lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct 21 10:28:12 2013 daniel_d
** Last update Tue Feb 18 15:40:09 2014 daniel_d
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
