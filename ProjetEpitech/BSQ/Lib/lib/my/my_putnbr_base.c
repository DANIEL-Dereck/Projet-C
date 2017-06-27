/*
** my_put_nbr.c for my_putnbr_base.c in /home/daniel_d/rendu/Piscine-C-Jour_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  2 18:12:11 2013 daniel_d
** Last update Tue Dec  3 14:28:40 2013 daniel_d
*/

void    my_basewhile(int c, int d, int ba, char *base)
{
  int nb;
  int a;
  int e;

  a = 1;
  nb = d;
  e = d;
  while (nb >= ba)
    {
      nb = nb / ba;
      a = a * ba;
    }
  while (a > 0)
    {
      e = d / a;
      c = e % ba;
      my_putchar(base[c]);
      a = a / ba;
    }
}

int     my_putnbr_base(int nb, char *base)
{
  int c;
  int d;
  int ba;

  ba = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  c = 1;
  d = nb;
  my_basewhile(c, d, ba, base);
}

int     my_putnrb_base_rec(int nb, char *base)
{
  int   c;

  c = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= c)
    {
      my_putnbr_base_rec(nb / c, base);
      my_putnbr_base_rec(nb % c, base);
    }
  else
    my_putchar(base[c]);
}
