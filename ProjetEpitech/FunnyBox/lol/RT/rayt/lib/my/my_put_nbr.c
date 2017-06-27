/*
** my_put_nbr.c for my_putnbr in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Fri Oct 11 09:34:08 2013 julien_t
** Last update Sun Dec  8 19:45:35 2013 julien_t
*/

int	my_abs(int nb)
{
  if (nb < 0)
    return (-nb);
  else
    return (nb);
}

int	my_put_nbr(int nb)
{
  int	 a;
  int	 b;
  int	 abc;

  b = 0;
  abc = nb;
  while (abc >= 10)
    {
      abc = abc / 10;
      b = b + 1;
    }
  while (b >= 0)
    {
      abc = nb;
      a = 0;
      while (a < b)
	{
	  abc = abc / 10;
	  a = a + 1;
	}
      abc = abc % 10;
      my_putchar(abc + 48);
       b = b - 1;
    }
  my_putchar('\n');
}
