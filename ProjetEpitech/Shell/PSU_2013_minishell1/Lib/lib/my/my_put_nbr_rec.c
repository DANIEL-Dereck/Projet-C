/*
** my_put_nbr_rec.c for putnbr_rec in /home/daniel_d/rendu/PSU_2013_minishell1/Lib/lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Dec 18 15:19:38 2013 daniel_d
** Last update Wed Dec 18 15:19:44 2013 daniel_d
*/

int     my_put_nrb_rec(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 9)
    {
      my_put_nbr_rec(nb / 10);
      my_put_nbr_rec(nb % 10);
    }
  else
    my_putchar(nb) + 48;
}
