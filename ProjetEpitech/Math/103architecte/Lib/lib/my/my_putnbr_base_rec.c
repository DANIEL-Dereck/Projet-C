/*
** my_putnbr_base_rec.c for nbr in /home/daniel_d/rendu/103architecte/Lib/lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Dec  9 14:46:56 2013 daniel_d
** Last update Mon Dec  9 14:47:02 2013 daniel_d
*/

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
