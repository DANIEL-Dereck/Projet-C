/*
** my_put_nbr.c for my_put_nbr.c in /home/daniel_d/rendu/Piscine-C-Jour_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  2 18:12:11 2013 daniel_d
** Last update Mon Oct 28 16:45:40 2013 daniel_d
*/

void	my_while(int a, int c, int d, int nb)
{
  int e;

  e = nb;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
      e = nb;
      d = nb;
    }

  while (nb > 9)
    {
      nb = nb / 10;
      a = a * 10;
    }
  while (a > 0)
    {
      e = d / a;
      c = e % 10;
      my_putchar(c + 48);
      a = a / 10;
    }
}

int	my_put_nbr(int nb)
{
  int a;
  int c;
  int d;

  a = 1;
  c = 1;
  d = nb;
  my_while(a, c, d, nb);
}

