/*
** my_str_const.c for libmy in /home/bertho_d/rendu/lib
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Oct 12 17:56:36 2013 bertho_d
** Last update Thu Nov 21 07:42:00 2013 bertho_d
*/

static int	is_matching_s2(char *s1, char *s2)
{
  if (!s1 || !s2)
    return (0);
  while (*s2)
    {
      if (*s1 != *s2 || !(*s1))
	return (0);
      s1++;
      s2++;
    }
  return (1);
}

char	*my_strstr(char *str, char *to_find)
{
  if (!str || !to_find)
    return ((void *)0);
  while (*str)
    {
      if (is_matching_s2(str, to_find))
	return (str);
      str++;
    }
  return ((void *)0);
}

int	my_strlen(char *str)
{
  int	len;

  if (!str)
    return (-1);
  len = 0;
  while (str[len])
    len += 1;
  return (len);
}
