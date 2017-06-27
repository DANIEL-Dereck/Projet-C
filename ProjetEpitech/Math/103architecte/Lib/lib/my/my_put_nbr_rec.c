/*
** my_put_nbr_rec.c for nbr rec in /home/daniel_d/rendu/103architecte/Lib/lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Dec  9 14:47:45 2013 daniel_d
** Last update Mon Dec  9 14:47:50 2013 daniel_d
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

