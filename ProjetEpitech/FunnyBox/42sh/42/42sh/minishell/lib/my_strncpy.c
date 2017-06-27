/*
** my_strncpy.c for char *my_strncpy(char *dest, char *src, int n) in /home/boucha_q/rendu/Piscine-C-Jour_06/ex_02
**
** Made by boucha_q
** Login   <boucha_q@epitech.net>
**
** Started on  Mon Oct  7 10:28:23 2013 boucha_q
** Last update Thu Nov 14 10:54:45 2013 boucha_q
*/

char	*my_strncpy(char *dest, char *src, int n )
{
  int	i;

  i = 0;
  while (i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
