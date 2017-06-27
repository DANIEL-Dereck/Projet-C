/*
** my_putchar.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:34:15 2013 jouana_j
** Last update Thu Nov 14 17:22:29 2013 jouana_j
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
