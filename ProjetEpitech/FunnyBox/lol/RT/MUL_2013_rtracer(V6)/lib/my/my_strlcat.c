/*
** my_strlcat.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:38:41 2013 jouana_j
** Last update Thu Nov 14 17:58:34 2013 jouana_j
*/

char	*my_strlcat(char *dest, char *src, int size)
{
  int	i;
  int	nb;

  i = 0;
  nb = 1;
  while (dest[nb] != '\0')
    nb = nb + 1;
  while (src[i] != '\0' && i < size)
    {
      dest[nb + i] = src[i];
      i = i + 1;
    }
  return (dest);
}
