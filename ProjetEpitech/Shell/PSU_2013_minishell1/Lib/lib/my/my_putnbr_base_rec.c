/*
** my_putnbr_base_rec.c for putnbr_rec in /home/daniel_d/rendu/PSU_2013_minishell1/Lib/lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Dec 18 15:18:23 2013 daniel_d
** Last update Wed Dec 18 15:18:33 2013 daniel_d
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
