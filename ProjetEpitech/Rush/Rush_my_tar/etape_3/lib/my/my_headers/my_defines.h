/*
** my_macros.h for libmy in /home/bertho_d/rendu/lib/my
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Fri Nov 22 01:42:39 2013 bertho_d
** Last update Sun Dec  1 02:45:50 2013 bertho_d
*/

#ifndef MY_MACROS_H_
# define MY_MACROS_H_

# define MIN(x, y)		(((x) < (y)) ? (x) : (y))
# define MAX(x, y)		(((x) > (y)) ? (x) : (y))
# define ABS(x)			((x < 0) ? -(x) : (x))
# define SGN(x)			((x < 0) ? -1 : 1)

# define MY_LOWER_CHAR		1
# define MY_UPPER_CHAR		2
# define MY_NUMERIC_CHAR	3
# define MY_PRINTABLE_CHAR	4

# define GNL_READ_SIZE	256

#endif
