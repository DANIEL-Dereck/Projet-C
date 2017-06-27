/*
** my_put_nbr.c for my_putnbr_base.c in /home/daniel_d/rendu/Piscine-C-Jour_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  2 18:12:11 2013 daniel_d
** Last update Sun Nov 17 17:03:59 2013 daniel_d
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}

int	my_strlen(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    a = a + 1;
  return (a);
}

int	my_putnbr_base(int nb, char *base)
{
  int a;

  a = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= a)
    {
      nb = my_putnbr_base(nb / a, base);
      nb = my_putnbr_base(nb % a, base);
    }
  else
    { 
      my_putchar(base[nb]);
    }
}

int	main()
{
  int a;
  char *str;

  a = 945464;
  str = "0123456789";
  my_putnbr_base(a, str);
}
