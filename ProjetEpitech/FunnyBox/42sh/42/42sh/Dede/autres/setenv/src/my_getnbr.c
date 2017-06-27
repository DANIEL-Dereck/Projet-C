/*
** my_getnbr.c for GetNumber in /home/aubry_f/rendu/Piscine-C-Jour_04
**
** Made by aubry_f
** Login   <aubry_f@epitech.net>
**
** Started on  Wed Oct  9 09:56:40 2013 aubry_f
** Last update Fri May 16 16:17:30 2014 aubry_f
*/

int	my_nbrneg(char *str)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (str[i] != 0)
    {
      if (str[i] == '-')
	c++;
      i++;
    }
  if (c % 2 != 0)
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;

  i = 0;
  nbr = 0;
  while (str[i] != 0)
    {
      while (str[i] >= '0' && str[i] <= '9')
	{
	  nbr = (nbr * 10) + (str[i] - 48);
	  i++;
	  if (str[i] < '0' || str[i] > '9')
	    {
	      if (my_nbrneg(str) == 1)
		nbr = - nbr;
	      return (nbr);
	    }
	}
      i++;
    }
  return (0);
}
