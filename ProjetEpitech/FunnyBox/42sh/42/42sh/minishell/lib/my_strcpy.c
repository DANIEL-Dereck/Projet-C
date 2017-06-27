/*
** my_strcpy.c for char *my_putstrcpy(char *dest, char *src) in /home/boucha_q/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by boucha_q
** Login   <boucha_q@epitech.net>
** 
** Started on  Mon Oct  7 07:55:27 2013 boucha_q
** Last update Tue Oct  8 21:50:39 2013 boucha_q
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
