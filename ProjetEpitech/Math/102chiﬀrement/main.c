/*
** main.c for 102 in 
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Nov 28 13:56:27 2013 daniel_d
** Last update Wed Dec 18 13:19:27 2013 daniel_d
*/

#include <stdlib.h>

int	*my_tab(char *av, int *tab)
{
  int	a;
  int	c;

  a = my_strlen(av);
  if ((a % 2) == 1)
    a = a + 1;
  tab = malloc(sizeof(tab) * a);
  if (tab == NULL)
    return (0);
  c = 0;

  while (av[c] !=  0)
    {
      tab[c] = av[c] - 96;
      if (av[c] == ' ')
	tab[c] = 0;
      c = c + 1;
    }
  return (tab);
}

int     *my_key(char **av, int *key)
{
  int   a;
  int   c;

  key = malloc(sizeof(key) * 4);
  if (key == NULL)
    return (0);
  key[0] = my_getnbr(av[2]);
  key[1] = my_getnbr(av[3]);
  key[2] = my_getnbr(av[4]);
  key[3] = my_getnbr(av[5]);
  return (key);
}

int     main(int ac, char **av)
{
  int   *tab;
  int   *key;
  int	len;

  if (ac != 8)
    {
      my_printf("Usage: \"Le message: minuscule ou espace\" \"Une clef constituée de 4 entiers\" \"La base\" \"un flag\"\n flag: 0 = chiffrement \\ 1 = déchiffrement\n");
      my_printf("\texemple chiffrement: \"av czar\" 2 5 1 3 \"CESAR\" 0\n");
      my_printf("\texemple déchiffrement: \"RR SRE A ER SCA ECEA ESE AAC\" 2 5 1 3 \"CESAR\" 1\n");
      return (0);
    }
  len = my_strlen(av[1]);
  tab = my_tab(av[1], tab);
  key = my_key(av, key);
  if (my_getnbr(av[7]) == 0)
    chiffrement(tab, key, len, av[6]);
  else if (my_getnbr(av[7]) == 1)
    my_putstr("en cours ...");
    //    déchiffrement(tab, clef, len, av[6]);
  return (0);
}
