/*
** my_strcmp.c for my_strcmp in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 13:56:09 2013 julien_t
** Last update Thu Apr 24 13:25:33 2014 jouana_j
*/

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
        return (-1);
      i = i + 1;
    }
  return (0);
}
