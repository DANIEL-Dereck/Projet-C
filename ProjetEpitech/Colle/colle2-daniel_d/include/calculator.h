/*
** calculator.h for calculator in /home/daniel_d/colle2-daniel_d/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue May  6 14:09:42 2014 daniel_d
** Last update Tue May  6 17:27:34 2014 gautie_a
*/

#ifndef CALCULATOR_H_
# define CALCULATOR_H_

# define OPEN	'('
# define CLOSE	')'
# define OPS	"+-*/%"
# define VALID	"()+-*/%0123456789"

typedef struct s_nb
{
  int		nb;
  int		priority;
  int		done;
  struct s_nb	*next;
  struct s_nb	*prev;
} t_nb;

typedef struct s_core
{
  t_nb *list;
  int	size;
  char	*op;
  int	del;
} t_core;

int	colle2(char *);
int	verif_expr(char *);
char	*func(char *);

//OPERATIONS
int	colle_add(int, int);
int	colle_sub(int, int);
int	colle_mul(int, int);
int	colle_div(int, int);
int	colle_mod(int, int);

//LIB
void	my_putchar(char);
void	my_putstr(char *);
int	my_strlen(char *);
int	my_str_contains(char *, char);
int	my_getnbr(char *);
void	my_putnbr(int);

#endif
