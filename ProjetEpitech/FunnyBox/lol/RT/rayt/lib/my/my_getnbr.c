/*
** my_getnbr.c for my_getnbr in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Thu Oct 17 14:32:01 2013 julien_t
** Last update Sun Dec  8 19:46:42 2013 julien_t
*/

int	nbrlen(char *str)
{
  int	 a;

  a = 0;
  while (str[a]  != '\0')
    {
      a = a + 1;
    }
  return (a);
}

int	my_pow(int a)
{
  int	m;
  int	p;

  m = 1;
  p = 1;
  while (m < a)
    {
      p = p * 10;
      m = m + 1;
    }
  return (p);
}

int	my_getnbr(char *str)
{
  int	 b;
  int	 pow;
  int	 a;
  int	res;

  b = nbrlen(str);
  pow = my_pow(b);
  a = 0;
  {
  if (str[a] == '-')
    b = -1;
  a = a + 1;
  }
  while (str[a] != '\0')
    {
      res = res + (str[a] - 48) * pow;
      a = a + 1;
      pow = pow / 10;
    }
  my_put_nbr(res);
  return (res);
}

