/*
** my_strcmp.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:37:07 2013 jouana_j
** Last update Thu Nov 14 17:55:52 2013 jouana_j
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i] && s1[i + 1] != '\0')
	return (s1[i] - s2[i]);
      else if (s1[i] != s2[i] && s2[i + 1] != '\0')
	return (s1[i] - s2[i]);
      else if (s2[i] == '\0')
	return (-s2[i + 1]);
      i = i + 1;
    }
  return (0);
}
