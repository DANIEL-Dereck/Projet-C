/*
** my_revstr.c for my_revstr.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct  7 13:41:32 2013 daniel_d
** Last update Mon Oct  7 16:31:57 2013 daniel_d
*/


int     my_putstr(char *str)
{
  char h;

  h = 0;

  while (str[h] != '\0')
    {
      str[h];
      h = h + 1;
    }

  while (h != 0)
    {
      h = h - 1;
      my_putchar(str[h]);
    }
}

char	*my_revstr(char *str)
{
  my_putstr(str);
  my_putchar('\n');
}
