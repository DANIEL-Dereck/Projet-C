/*
** funk.c for colle2 in /home/daniel_d/colle2-daniel_d/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue May  6 16:58:52 2014 daniel_d
** Last update Tue May  6 17:57:10 2014 daniel_d
*/

#include <stdlib.h>
#include <stdio.h>

char	*func(char *str)
{
  char	*dest;
  int	p;
  int	i;
  int	l;

  i = 1;
  p = 1;
  while (p != 0)
    {
      if (str[i] == '(')
	p++;
      else if (str[i] == ')')
	p--;
      i++;
    }
  if ((dest = malloc(i)) == NULL)
    return (NULL);
  l = -1;
  while (++l < i - 2)
    dest[l] = str[l + 1];
  dest[l] = '\0';
  return (dest);
}
<<<<<<< .mine

=======
>>>>>>> .r30
