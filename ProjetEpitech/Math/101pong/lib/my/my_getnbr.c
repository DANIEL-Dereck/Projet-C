/*
** my_getnbr.c for my_getnbr.c in /home/daniel_d/rendu/Piscine-C-Jour_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  9 10:24:06 2013 daniel_d
** Last update Thu Oct 17 15:48:01 2013 daniel_d
*/

int	my_nbr(char *str, int a, int c, int d)
{
  int b;

  b = 0;

  while (str[a] >= 48 && str[a] <= 57)
    {
      b = str[a] - 48;
      c = b + c;
      c = c * 10;
      a = a + 1;
    }

  if (d < 0)
    c = -c;
  c = c / 10;

  return (c);
}

int	my_getnbr(char *str)
{
  int a;
  int c;
  int d;

  a = 0;
  c = 0;
  d = 0;

  while (str[a] == '+' || str[a] == '-')
    {
      if (str[a] == '+')
	d = d + 1;
      if (str[a] == '-')
	d = d - 1;
      a = a + 1;
    }
  c = my_nbr(str, a, c, d);
  if (c < -2147483648 || c > 2147483647)
    return (0);
}

