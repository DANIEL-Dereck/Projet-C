/*
** my_square_root.c for Piscine-C-lib/my in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Tue Oct  8 08:11:51 2013 jouana_j
** Last update Thu Nov 14 17:54:56 2013 jouana_j
*/

int	my_square_root(int nb)
{
  int	n;

  n = 1;
  if (nb > 0)
    {
      while ((n * n) < (nb + n))
	{
	  if ((n * n) == nb)
	    return (n);
	  n = n + 1;
	}
    }
  return (0);
}
