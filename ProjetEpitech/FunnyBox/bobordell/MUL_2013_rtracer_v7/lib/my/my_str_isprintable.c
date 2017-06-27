/*
** my_str_isprintable.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:38:18 2013 jouana_j
** Last update Thu Nov 14 17:58:00 2013 jouana_j
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'a' || str[i] > 'z')
	return (0);
      i = i + 1;
    }
  return (1);
}
