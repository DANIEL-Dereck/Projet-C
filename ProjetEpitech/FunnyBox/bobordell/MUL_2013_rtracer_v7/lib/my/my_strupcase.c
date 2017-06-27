/*
** my_strupcase.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:40:26 2013 jouana_j
** Last update Thu Nov 14 18:01:14 2013 jouana_j
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 122 && str[i] >= 97)
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
