/*
** my_putnbr_base.c for my_putnbr_base.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_15
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Oct 13 13:04:00 2013 daniel_d
** Last update Sun Oct 13 14:00:21 2013 daniel_d
*/

void    my_while(int a, int c, int d, int k)
{
  int e;

  e = d;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
      e = nb;
      d = nb;
    }

  while (nb > k)
    {
      nb = nb / 10;
      a = a * 10;
    }
  while (a > 0)
    {
      e = d / a;
      c = e % 10;
      my_putchar(base[c] + 48);
      a = a / 10;
    }
}

int     my_putnbr_base(int nbr, char *base)
{
  int a;
  int c;
  int d;
  int k;

  a = 1;
  c = 1;
  d = nbr;

  while (base[k] != 0)
    k = k + 1;
  k = k -1;
  my_while(a, c, d, k);
}

int	main()
{
  my_putnbr_base()
}
