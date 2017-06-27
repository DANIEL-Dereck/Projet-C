/*
** sapin.c for sapin.c in /home/daniel_d/rendu/Piscine-C-sapin
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Oct  3 20:41:23 2013 daniel_d
** Last update Sun Nov 10 11:48:18 2013 daniel_d
*/

int	pied(int p, int sp, int a, int b, int y)
{
  b = p;
  y = p;

  while (a >= 1)
    {
      sp = b * 3;
      if (y%2 < 1)
	p = p - 1;
      while (sp >= 1)
	{
	  my_putchar(' ');
	  sp = sp - 1;
	}
      while (p >= 1)
	{
	  my_putchar('|');
	  p = p - 1;
	}
      p = y;
      a = a - 1;
      my_putchar('\n');
    }
}

int	epine(int a)
{
  int f;
  int o;

  f = a;
  o = f;
  while(f >= 1)
    {
      a = a -1;
      while(a >= 1)
	{
	  my_putchar(' ');
	  a = a - 1;
	  while (f >= 1)
	    {
	      my_putchar('*');
	      f = f - 1;
	    }
	  my_putchar('\n');
	  f = f - 1;
	}
      a = o;
    }
}

void	sapin(int taille)
{
  int a;
  int sp;
  int p;
  int b;
  int y;

  p = taille;
  a = taille;

  epine(a);
  my_putchar('\n');
  pied(p, sp, a, b, y);
}
