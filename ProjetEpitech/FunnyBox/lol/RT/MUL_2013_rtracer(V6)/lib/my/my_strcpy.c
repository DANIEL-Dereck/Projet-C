/*
** my_strcpy.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
**
** Made by jouana_j
** Login   <jouana_j@epitech.net>
**
** Started on  Mon Oct 21 13:37:17 2013 jouana_j
** Last update Thu Nov 14 17:56:27 2013 jouana_j
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (dest[i] != '\0' || src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
