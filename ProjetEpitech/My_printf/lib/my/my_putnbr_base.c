/*
** my_put_nbr.c for my_putnbr_base.c in /home/daniel_d/rendu/Piscine-C-Jour_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  2 18:12:11 2013 daniel_d
** Last update Sun Nov 17 23:05:27 2013 daniel_d
*/

int	my_putnbr_base(int nb, char *base)
{
  int a;

  a = my_strlen(base);
  if (nb > a)
    {
      nb = my_putnbr_base(nb / a, base);
      nb = my_putnbr_base(nb % a, base);
    }
  if (nb < a)
    { 
      my_putchar(base[nb]);
    }
}
