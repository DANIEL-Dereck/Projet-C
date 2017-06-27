/*
** my_maths.c for libmy in /home/bertho_d/rendu/lib
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Oct 12 17:55:09 2013 bertho_d
** Last update Sun Oct 27 15:52:47 2013 bertho_d
*/

int	my_pow(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  return (nb * my_pow(nb, (power - 1)));
}

int	my_sqrt(int nb)
{
  int	sqrt;

  if (nb < 1)
    return (0);
  sqrt = 1;
  while (sqrt < nb / sqrt)
    sqrt++;
  if (sqrt == nb / sqrt && nb % sqrt == 0)
    return (sqrt);
  return (0);
}

int	my_floor_sqrt(int nb)
{
  int	sqrt;

  if (nb < 1)
    return (0);
  sqrt = 1;
  while (sqrt < nb / sqrt)
    sqrt++;
  if (sqrt == nb / sqrt)
    return (sqrt);
  return (sqrt - 1);
}

int	my_is_prime(int nb)
{
  int	sqrt;
  int	i;

  if (nb < 2 || nb % 2 == 0)
    return (0);
  sqrt = my_floor_sqrt(nb);
  i = 3;
  while (i <= sqrt)
    {
      if (nb % i == 0)
	return (0);
      i += 2;
    }
  return (1);
}

int	my_find_prime_sup(int nb)
{
  if (nb < 3)
    return (2);
  if (nb % 2 == 0)
    nb += 1;
  while (nb > 0)
    {
      if (my_is_prime(nb))
	return (nb);
      nb += 2;
    }
  return (nb - 1);
}
