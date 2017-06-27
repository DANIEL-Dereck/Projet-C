/*
** my_printf.h for my_printf in /home/bertho_d/rendu/Piscine-C-lib/my/my_io/my_printf
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Sun Nov 10 18:49:20 2013 bertho_d
** Last update Fri Nov 22 01:43:43 2013 bertho_d
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# define FLAG_ALTER_FORM	1
# define FLAG_PADD_ZERO		2
# define FLAG_PADD_RIGHT	4
# define FLAG_SIGN_BLANK	8
# define FLAG_SIGN_PLUS		16
# define CONV_SPECIFIERS	"idouxXbcsSpn"

typedef struct s_params
{
  char flags;
  int min_width;
  int precision;
  int target;
  char conv_spec;
} t_params;

typedef struct s_args
{
  long *args;
  int nb_args;
  int actual_arg;
} t_args;

int	padding(int left, int len, t_params *params);
int	display(long nb, int is_signed, char *base, t_params *params);
int	do_conv(t_params *params, t_args *args, int *len);
int	get_target(const char *format, int *target);
int	get_conv_params(const char *format, t_args *args, int *len);

#endif
