/*
** my_strlcat.c for my_strlcat in /home/julien_t/rendu/Piscine-C-lib/my
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Mon Oct 21 17:46:39 2013 julien_t
** Last update Mon Oct 21 17:47:27 2013 julien_t
*/

void    cpy_strlcat(char **d, char **s, char *dest, char *src)
{
  *d = dest;
  *s = src;
}

int     my_strlcat(char *dest, char *src, int size)
{
  char  *d;
  char  *s;
  int   n;
  int   dlen;

  n = size;
  cpy_strlcat(&d, &s, dest, src);
  while (n-- != 0 && *d != '\0')
    d = d + 1;
  dlen = d - dest;
  n = size - dlen;
  if (n == 0)
    return (dlen + my_strlen(s));
  while (*s != '\0')
    {
      if (n != 1)
        {
          *d = *s;
          *d = *d + 1;
          n = n - 1;
        }
      *s = *s + 1;
    }
  *d = '\0';
  return (dlen + (s - src));
}
