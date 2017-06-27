/*
** main.c for Bistro in /home/daniel_d/rendu/Bistro/code
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Nov  1 13:27:04 2013 daniel_d
** Last update Fri Nov  8 09:09:36 2013 daniel_d
*/

#include "my.h"
#include "bistro.h"

int	main(int argc, char **argv)
{
  /*
  int	p;
  char	*expr;

  p = my_parenthesis_counter(argv[1]);
  expr = my_parsing(argv[1], p);
  my_oper(my_nbr1(expr), my_oper_par(expr), my_nbr2(expr));
  */
  if (argc != 4)
    {
      my_putstr("usage: nb1, oper, nb2");
      my_putchar('\n');
      my_putstr("oper = '+' '-' '*' '/' '%'");
      my_putchar('\n');
    }
  if (argc == 4)
    my_oper(argv[1], argv[2], argv[3]);
  return (1);
}
