/*
** my_is_prime.c for Piscine-C-lib/my in /home/jouana_j/rendu/Piscine-C-lib/my
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Tue Oct  8 08:18:43 2013 jouana_j
** Last update Fri Oct 25 13:48:06 2013 jouana_j
*/

int	my_is_prime(int nb)
{
  int	i;
  int	j;

  if (nb > 1)
    {
      i = 1;
      j = 1;
      while (i < nb)
	{
	  while (j < nb)
	    {
	      if ((i * j) == nb)
		return (0);
	      j = j + 1;
	    }
	  j = 1;
	  i = i + 1;
	}
    }
  return (1);
}
