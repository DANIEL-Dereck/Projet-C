/*
** my_getnbr.c for my_getnbr in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 14:24:48 2014 marrec_k
** Last update Wed May 21 14:32:13 2014 marrec_k
*/

int	my_getnbr(char *str)
{
  int	i;
  int	res;
  int	neg;

  if (!str)
    return (0);
  i = 0;
  res = 0;
  neg = 1;
  while (str[i] && (str[i] == '+' || str[i] == '-'))
    {
      if (str[i] == '-')
	neg *= -1;
      i += 1;
    }
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      res = (res * 10) + str[i] - '0';
      i += 1;
    }
  if (neg == -1)
    return (-res);
  return (res);
}
