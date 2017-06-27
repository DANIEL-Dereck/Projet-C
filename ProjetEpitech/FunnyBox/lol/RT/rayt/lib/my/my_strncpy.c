/*
** *my_strncpy.c for *my_strncpy in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 13:49:15 2013 julien_t
** Last update Sat Oct 19 13:49:36 2013 julien_t
*/

char    *my_strncpy(char *dest, char *src, int nb)
{
  int   i;

  i = 0;
  while (src[i] && i < nb)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (!src[nb - 1])
    dest[i] = '\0';
  return (dest);
}
