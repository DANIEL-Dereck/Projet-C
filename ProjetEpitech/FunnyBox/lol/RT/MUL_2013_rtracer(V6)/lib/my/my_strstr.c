/*
** my_strstr.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:40:14 2013 jouana_j
** Last update Thu Nov 14 18:01:00 2013 jouana_j
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	n;

  i = 0;
  while (str[i] != '\0')
    {
      j = 0;
      n = i;
      while (str[n] == to_find[j])
	{
	  j = j + 1;
	  if (to_find[j] == '\0')
	    return (to_find);
	  n = n + 1;
	}
      i = i + 1;
    }
  return (0);
}
