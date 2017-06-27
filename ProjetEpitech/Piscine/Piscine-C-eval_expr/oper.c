/*
** eval_expr.c for eval_expr in /home/daniel_d/rendu/Piscine-C-eval_expr
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Fri Oct 25 10:04:56 2013 daniel_d
** Last update Mon Oct 28 15:52:00 2013 daniel_d
*/

int	my_oper(int a, char *oper, int b)
{
  int result;

  if (b == 0 && oper[0] == '/' || b == 0 && oper[0] == '%')
    {
      if (oper[0] == '/')
	my_putstr("Stop : division by 0\n");
      else if (oper[0] == '%')
	my_putstr("Stop : modulo by 0\n");
    }

  if (b != 0 && oper[0] == '/')
    result = a / b;  

  else if (b != 0 && oper[0] == '%')
    result = a % b;

  else if (oper[0] == '*')
    result = a * b;

  else if (oper[0] == '+')
    result = a + b;

  else if (oper[0] == '-')
    result = a - b;

  return (result);
}
