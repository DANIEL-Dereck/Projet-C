/*
** my_strncmp.c for my_strncmp in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 13:58:34 2013 julien_t
** Last update Sat Oct 19 13:59:07 2013 julien_t
*/

int     my_strncmp(char *s1, char *s2, int nb)
{
  int   i;

  i = 0;
  while ((s1[i] || s2[i]) && i < nb)
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
      i = i + 1;
    }
  if ((s1[i] < s2[i]) && i < nb)
    return (-1);
  if ((s1[i] > s2[i]) && i < nb)
    return (1);
  return (0);
}
