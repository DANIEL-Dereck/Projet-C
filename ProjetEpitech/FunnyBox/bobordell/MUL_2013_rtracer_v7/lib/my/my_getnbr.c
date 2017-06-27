/*
** my_getnbr.c for Piscine-C-lib/my in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:32:36 2013 jouana_j
** Last update Sun Dec  8 11:30:55 2013 jouana_j
*/

int	my_nbr(char *str, int a, int c, int d)
{
  int	b;

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
  int	a;
  int	c;
  int	d;

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
  return (c);
}
