/*
** my_showmem.c for libmy in /home/bertho_d/rendu/lib/io
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sat Oct 12 17:54:48 2013 bertho_d
** Last update Thu Nov 21 10:45:56 2013 bertho_d
*/

#include "my.h"

static void	my_disp_byte_hexa(char c)
{
  char	*tab;
  int	signe;

  signe = 0;
  if (c < 0)
    {
      signe = 8;
      c = 128 + c;
    }
  tab = "0123456789abcdef";
  my_putchar(tab[signe + c / 16]);
  my_putchar(tab[c % 16]);
}

static void	disp_n_bytes(char *str, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (!my_char_type(str[i]))
	my_putchar('.');
      else
	my_putchar(str[i]);
      i += 1;
    }
}

static void	disp_showmem_line(char *str, int len, char *address)
{
  int	i;

  my_putstr(address);
  my_putstr("0: ");
  i = 0;
  while (i < 16)
    {
      if (i < len)
	my_disp_byte_hexa(str[i]);
      else
	my_put_n_chars(' ', 2);
      if (i % 2 == 1)
	my_putchar(' ');
      i += 1;
    }
  disp_n_bytes(str, len);
  my_put_n_chars(' ', (16 - len));
  my_putchar('\n');
}

static void	increment_address(char *address, int pos)
{
  if (pos < 0)
    return ;
  if ((address[pos] >= '0' && address[pos] <= '8')
      || (address[pos] >= 'a' && address[pos] <= 'e'))
    address[pos] += 1;
  else if (address[pos] == '9')
    address[pos] = 'a';
  else
    {
      address[pos] = '0';
      increment_address(address, (pos - 1));
    }
}

int	my_showmem(char *str, int size)
{
  int	i;
  char	address[7];

  i = 0;
  while (i < 7)
    {
      address[i] = '0';
      i += 1;
    }
  i = 0;
  while ((size - 1) / 16 > 0)
    {
      disp_showmem_line(str, 16, address);
      increment_address(address, 6);
      str += 16;
      size -= 16;
      i += 1;
    }
  disp_showmem_line(str, size, address);
  return (0);
}
