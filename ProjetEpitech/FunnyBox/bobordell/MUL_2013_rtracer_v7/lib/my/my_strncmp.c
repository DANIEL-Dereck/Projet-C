/*
** my_strncmp.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Mon Oct 21 13:39:51 2013 jouana_j
** Last update Mon Oct 21 13:39:52 2013 jouana_j
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((s1[i] != '\0' && s2[i] != '\0') || i < n)
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
