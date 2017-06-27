/*
** my_strlowcase.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:39:07 2013 jouana_j
** Last update Thu Nov 14 17:59:41 2013 jouana_j
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 90 && str[i] >= 65)
	str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
