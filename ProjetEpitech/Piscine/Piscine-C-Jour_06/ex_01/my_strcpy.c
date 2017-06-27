/*
** my_strcpy.c for my_strcpy.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct  7 08:56:30 2013 daniel_d
** Last update Mon Oct  7 14:11:06 2013 daniel_d
*/


int my_putstr(char *src)
{
  char h;

  h = 0;

  while (src[h] != '\0')
    {
      my_putchar(src[h]);
      h = h + 1;
    }
}

int	*my_strcpy(char *dest, char *src)
{
  my_putstr(src);
  dest = src;
  my_putstr(dest);
}
