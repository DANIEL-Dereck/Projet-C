/*
** my_strncat.c for my_strncat in /home/julien_t/rendu/Piscine-C-lib/my
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Mon Oct 21 17:43:39 2013 julien_t
** Last update Mon Oct 21 17:46:11 2013 julien_t
*/

char    *my_strncat(char *dest, char *src, int nb)
{
  int   i;
  int   j;

  j = 0;
  i = my_strlen(dest);
  while (src[j] && i < nb)
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
  return (dest);
}
