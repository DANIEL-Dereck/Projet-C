/*
** eval_expr.c for eval_expr in /home/daniel_d/rendu/Piscine-C-eval_expr
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Oct 25 10:04:56 2013 daniel_d
** Last update Fri Nov  8 09:10:18 2013 daniel_d
*/

#include "my.h"
#include "bistro.h"

int	my_oper(char *nb1, char *oper, char *nb2)
{
  int	len2;

  len2 = my_strlen(nb2);
  if (len2 == 0 && (oper[0] == '/' || oper[0] == '%'))
    {
      if (oper[0] == '/')
	my_putstr("Stop : division by 0\n");
      else if (oper[0] == '%')
	my_putstr("Stop : modulo by 0\n");
      return (1);
    }
  if (oper[0] == '/')
    // my_divinf(nb1, nb2);
    len2 = len2 + 1;
  else if (oper[0] == '%')
    // my_moduloinf(nb1, nb2);
    len2 = len2 + 1;
  else if (oper[0] == '*')
    my_multinf(nb1, nb2);
  else if (oper[0] == '+')
    my_addinf(nb1, nb2);
  else if (oper[0] == '-')
    my_sousinf(nb1, nb2);
  return (1);
}
