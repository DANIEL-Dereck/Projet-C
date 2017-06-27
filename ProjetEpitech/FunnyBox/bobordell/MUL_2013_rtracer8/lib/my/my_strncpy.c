/*
** my_strncpy.c for  in /home/jouana_j/rendu/Piscine-C-lib/my
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Mon Oct 21 13:40:03 2013 jouana_j
** Last update Fri Oct 25 13:54:44 2013 jouana_j
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
