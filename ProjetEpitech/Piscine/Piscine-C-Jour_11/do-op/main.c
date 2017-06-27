/*
** main.c for do-op in /home/daniel_d/rendu/Piscine-C-Jour_11/do-op
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct 28 11:51:52 2013 daniel_d
** Last update Mon Oct 28 18:22:54 2013 daniel_d
*/

int	main(int ac, char **av)
{
  int result;
  int a;
  char *oper;
  int b;

  oper = av[1];
  a = my_getnbr(*av[1]);
  b = my_getnbr(*av[2]);

  result = my_oper(a, oper, b);
  my_put_nbr(result);
  my_putchar('\n');
}
