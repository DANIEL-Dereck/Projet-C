/*
** my_strncat.c for char *my_strncat(char *dest, char *src, int nb) in /home/boucha_q/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Tue Oct  8 15:38:37 2013 boucha_q
** Last update Wed Oct  9 21:23:14 2013 boucha_q
*/

char	*my_strncat(char *dest, char *src, int f)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  n = my_strlen(dest);
  while ( src[i] != '\0' && i < f)
    {
      dest [n] = src[i];
      n = n + 1;
      i = i + 1;
    }
  return (dest);
}
