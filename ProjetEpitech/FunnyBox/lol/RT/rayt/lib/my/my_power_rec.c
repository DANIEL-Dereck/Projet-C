/*
** my_power_rec.c for my_power_rec in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 13:01:33 2013 julien_t
** Last update Fri Oct 25 15:47:43 2013 julien_t
*/

int     my_power_rec(int nb, int power)
{
  if (power == 0)
    return (0);
  else if (power > 1)
    nb = nb * my_power_rec(nb, power - 1);
  return (nb);
}
