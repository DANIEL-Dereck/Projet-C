/*
** my_strncpy.c for my_strncpy.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_02
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct  7 10:52:14 2013 daniel_d
** Last update Wed Feb 19 13:39:58 2014 daniel_d
*/

int	my_put_strncpy(char *src, int n)
{
  int h;

  h = 0;
  while (n != 0)
    {
      if (src[h] == '\0')
	n = 1;
      n = n - 1;
      h = h + 1;
    }
  return (h);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  my_put_strncpy(src, n);
  dest = src;
  my_put_strncpy(dest, n);
  return (dest);
}
