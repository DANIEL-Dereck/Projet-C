/*
** my_strncat.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:39:38 2013 jouana_j
** Last update Thu Nov 14 18:00:02 2013 jouana_j
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	size;

  i = 0;
  size = 1;
  while (dest[size] != '\0')
    size = size + 1;
  while (src[i] != '\0' && i < nb)
    {
      dest[size + i] = src[i];
      i = i + 1;
    }
  return (dest);
}
