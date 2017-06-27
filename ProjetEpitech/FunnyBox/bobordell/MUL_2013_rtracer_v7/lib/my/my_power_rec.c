/*
** my_power_rec.c for Piscine-C-lib/my in /home/jouana_j/rendu/Piscine-C-lib/my
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Mon Oct 21 13:34:00 2013 jouana_j
** Last update Sun Dec  8 11:31:22 2013 jouana_j
*/

int	my_power_rec(int nb, int power)
{
  int	nb1;

  nb1 = 0;
  if (power > 0)
    {
      nb1 = nb * my_power_rec(nb, power - 1);
      if (nb1 > 1000000000)
	return (0);
      else
	return (nb1);
    }
  else if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  return (0);
}
