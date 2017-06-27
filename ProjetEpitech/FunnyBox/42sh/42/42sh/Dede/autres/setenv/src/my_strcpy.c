/*
** my_strcpy.c for String Copy in /home/aubry_f/rendu/Piscine-C-Jour_06
**
** Made by aubry_f
** Login   <aubry_f@epitech.net>
**
** Started on  Mon Oct  7 08:16:27 2013 aubry_f
** Last update Wed Apr 23 16:31:50 2014 aubry_f
*/

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
