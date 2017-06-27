/*
** my_showstr.c for my_showstr in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 14:54:41 2013 julien_t
** Last update Fri Oct 25 15:50:01 2013 julien_t
*/

int     my_showstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] > 126)
        {
          my_putchar('\\');
          if (str[i] < 14)
            {
              my_putchar('0');
            }
          my_put_nbr((str[i]), "0123456789abcdef");
        }
      else
        {
          my_putchar(str[i]);
        }
      i = i + 1;
    }
  return (0);
}
