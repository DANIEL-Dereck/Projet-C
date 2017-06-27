/*
** my_aff_comb.c for my_aff_comb in /home/daniel_d/rendu/Piscine-C-Jour_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  2 14:39:09 2013 daniel_d
** Last update Thu Jul 24 16:48:16 2014 daniel_d
*/

int	my_aff_comb()
{
  char a;
  char b;
  char c;

  a = 48;
  b = 49;
  c = 50;

 while(a <= 55)
   {
     while(b <= 56)
       {
	 while (c <= 57)
	   {
	     my_putchar(' ');
	     my_putchar(a);
	     my_putchar(b);
	     my_putchar(c);
	     my_putchar(',');    
	     c = c + 1;
	   }
	 b = b + 1;
	 c = b + 1;
       }
     a = a + 1;
     b = a + 1;
     c = b + 1;}
}
