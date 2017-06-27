/*
** my_strcat.c for my_strcat in /home/julien_t/rendu/Piscine-C-lib/my
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Mon Oct 21 17:41:55 2013 julien_t
** Last update Mon Oct 21 17:43:02 2013 julien_t
*/

char    *my_strcat(char *dest, char *src)
{
  int   lenght_dest;
  int   i;

  lenght_dest = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[lenght_dest + i] = src[i];
      i = i + 1;
    }
  dest[lenght_dest + i] = '\0';
  return (dest);
}
