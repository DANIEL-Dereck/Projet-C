/*
** my_str_isnum.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:38:03 2013 jouana_j
** Last update Thu Nov 14 17:57:47 2013 jouana_j
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] > 57)
	return (0);
      i = i + 1;
    }
  return (1);
}
