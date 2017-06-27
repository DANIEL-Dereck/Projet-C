/*
** my_revstr.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Mon Oct 21 13:35:22 2013 jouana_j
** Last update Fri Oct 25 13:49:07 2013 jouana_j
*/

char	*my_revstr(char *str)
{
  int	i;
  int	n;
  char	tmp;

  i = 0;
  n = 0;
  while (str[n] != '\0')
    {
      n = n + 1;
    }
  n = n - 1;
  while (i < n)
    {
      tmp = str[i];
      str[i] = str[n];
      str[n] = tmp;
      i = i + 1;
      n = n - 1;
    }
  return (str);
}
