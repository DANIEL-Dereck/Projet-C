/*
** pi.h for colle1 in /home/daniel_d/colle1-daniel_d
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr 29 14:17:11 2014 daniel_d
** Last update Tue Apr 29 16:59:12 2014 bertho_d
*/

#ifndef PI_H_
# define PI_H_

# include <unistd.h>

# define PUTSTR(x)	write(1, (x), (my_strlen(x)))
# define PUTERR(x)	write(2, (x), (my_strlen(x)))
# define MAX(x, y)	(((x) > (y)) ? (x) : (y))

# define DFLT_DEPTH	300
# define DFLT_PRECISION	20

# define ALLOC_ERROR	-2

typedef enum		e_optype
{
  ADD = 0,
  SUB,
  DIV,
  PI,
  NB_OPS
} t_optype;

typedef struct		s_nb
{
  char			*val;
  char			*end;
  int			int_part_size;
} t_nb;

typedef struct		s_op
{
  t_optype		type;
  t_nb			nb1;
  t_nb			nb2;
  int			depth;
  int			precision;
} t_op;

int			set_op(t_op *op, t_optype type, char *nb1, char *nb2);
int			parsing(int argc, char **argv, t_op *op);

/*
**nb.c
*/
int			nb_get_val(t_nb *nb, char *nb_ptr);
char			*nb_get_dec_ptr(t_nb *nb);
void			disp_nb(t_nb *nb);
int			check_nb(char *val);
int			init_nb(t_nb *nb, char *val);

/*
**calc.c
*/
int			init_res(t_nb *res, t_op *op);
int			op_add(t_op *op);
int			op_sub(t_op *op);
int			op_div(t_op *op);

/*
**pi.c
*/
int			op_pi(t_op *op);

/*
**utils.c
*/
void			my_memset(char *ptr, char val, int size);
int			my_strlen(char *str);
int			my_atoi(char *str);

#endif
