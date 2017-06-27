/*
** my_showmem.c for my_showmem in /home/julien_t
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Sat Oct 19 14:56:56 2013 julien_t
** Last update Sat Oct 19 14:58:35 2013 julien_t
*/

int             my_showmem(char *str, int size)
{
  int           i;
  unsigned char positive;

  i = 0;
  while (i < size)
    {
      positive = str[i];
      my_print_adress(i, str, positive);
      my_print_hexa(i, str, size);
      my_verif_printable(i, str);
      while ((i + 1) % 16 != 0 && i < size)
        {
          i = i + 1;
          my_verif_printable(i, str);
        }
      i = i + 1;
      my_putchar('\n');
    }
  return (0);
}
