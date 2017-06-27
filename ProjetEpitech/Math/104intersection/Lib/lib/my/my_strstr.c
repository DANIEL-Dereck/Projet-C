/*
** my_strstr.c for my_strstr.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct  7 16:36:35 2013 daniel_d
** Last update Mon Oct 21 13:56:04 2013 daniel_d
*/


int	my_putstrstr(char *str, char *to_find)
{
  int h;

  h = 0;

  while (str[h] != *to_find)
    {
      h = h + 1;
    }
  if (str[h] == *to_find)
    {
      while (str[h] != '\0')
	{
	  my_putchar(str[h]);
	  h = h + 1;
	}
    }
}

char	*my_strstr(char *str, char *to_find)
{
  my_putstrstr(str, to_find);
}
