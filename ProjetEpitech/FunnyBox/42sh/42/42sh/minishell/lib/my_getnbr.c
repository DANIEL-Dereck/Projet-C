/*
** my_getnbr.c for int my_getnbr(char *str) in /home/boucha_q/rendu/Piscine-C-Jour_04
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Sat Oct 19 12:28:04 2013 boucha_q
** Last update Thu Nov 14 10:52:42 2013 boucha_q
*/

int	my_getnbr(char *str)
{
  int	m;
  int	n;
  int	result;

  result = 0;
  m = 0;
  n = 0;
  while ( str[m] == '-' || str[m] == '+')
    {
      if ( str[m] == '-')
	{
	  n = n + 1;
	  m = m + 1;
	}
      else
	m = m + 1;
    }
  while ( str[m] != '\0')
    {
      result = result * 10;
      result = result + (str[m] - 48);
      m = m + 1;
    }
  if ( n % 2 > 0 )
    {
      result = - result;
    }
  return (result);
}
