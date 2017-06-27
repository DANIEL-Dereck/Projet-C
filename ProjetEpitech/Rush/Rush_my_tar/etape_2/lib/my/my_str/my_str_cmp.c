/*
** my_str_cmp.c for libmy in /home/bertho_d/rendu/lib/my
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Thu Nov 21 07:10:03 2013 bertho_d
** Last update Thu Nov 21 07:36:04 2013 bertho_d
*/

int	my_strcmp(char *s1, char *s2)
{
  if (!s1 || !s2)
    return (0);
  while (*s1 != '\0' || *s2 != '\0')
    {
      if (*s1 != *s2)
	return (*s1 - *s2);
      s1 += 1;
      s2 += 1;
    }
  return (0);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  if (!s1 || !s2)
    return (0);
  i = 0;
  while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i += 1;
    }
  return (0);
}

int	my_strcmp_alpha(char *s1, char *s2)
{
  char	c1;
  char	c2;
  char	diff;

  if (!s1 || !s2)
    return (0);
  diff = 0;
  while (*s1 != '\0' || *s2 != '\0')
    {
      c1 = *s1 + ((*s1 >= 'a' && *s1 <= 'z') ? ('A' - 'a') : 0);
      c2 = *s2 + ((*s2 >= 'a' && *s2 <= 'z') ? ('A' - 'a') : 0);
      if (c1 != c2)
	return (c1 - c2);
      if (!diff && *s1 != *s2)
	diff = *s2 - *s1;
      s1 += 1;
      s2 += 1;
    }
  return (diff);
}
