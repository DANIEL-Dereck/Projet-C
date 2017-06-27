/*
** main.c for main in /home/daniel_d/rendu/Piscine-C-eval_expr
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Oct 27 11:31:53 2013 daniel_d
** Last update Wed Oct 30 16:29:39 2013 daniel_d
*/

#include <stdlib.h>

int	main(int av, char **ac)
{
  int a;
  int po;
  int pf;
  char *pos;
  int s;

  a = 0;
  po = 0;
  pf = 0;
  s = 0;

  while (ac[a] =! '\0')
    {
      if (ac[a] == '(')
	po = po + 1;
      if (ac[a] == ')')
	pf = pf + 1;
      a = a + 1;
    }

  if (po != pf)
    my_putchar('E');
  

  pos = malloc(sizeof(char) * po + 1);
  a = 0;
  my_putchar('O');

  while (ac =! '\0')
    {
      if (ac[a] == '(')
	{
	  pos[s] = ac[a];
	  s = s + 1;
	}
      a = a + 1;
    }
}

