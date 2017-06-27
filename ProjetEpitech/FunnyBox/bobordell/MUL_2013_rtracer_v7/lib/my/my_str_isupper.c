/*
** my_str_isupper.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:38:30 2013 jouana_j
** Last update Thu Nov 14 17:58:15 2013 jouana_j
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 65 || str[i] > 90)
	return (0);
      i = i + 1;
    }
  return (1);
}
