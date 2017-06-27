/*
** my.h for my.h in /home/daniel_d/rendu/Piscine-C-Jour_09/ex_02
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Oct 10 14:50:55 2013 daniel_d
** Last update Tue Apr 22 17:08:25 2014 daniel_d
*/

#ifndef MY_H_
# define MY_H_

#define BUFFER_SIZE	10
#include <stdarg.h>

void	my_putchar(char c);
void    my_putstr(char *str);
void	my_revstr(char *str);
int     my_printf(const char *format, ...);
void    my_print_func(va_list ap, int f);
void    my_print_funk(const char *format, char *my_formatall, va_list ap);
char    *my_printformat(char *my_formatall);
void    my_formatd(va_list ap);
void    my_formati(va_list ap);
void    my_formatb(va_list ap);
void    my_formato(va_list ap);
void    my_formatxmin(va_list ap);
void    my_formatxmaj(va_list ap);
void    my_formatp(va_list ap);
void    my_formatu(va_list ap);
void    my_formats(va_list ap);
void    my_formatc(va_list ap);
void    my_formatsmaj(va_list ap);
int     my_strlen(char *str);
int     my_needposchar(char *str, char c);
char    *my_strdup(char *src);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
int	my_put_nbru(unsigned int nb);
int	my_putnbr_base(int nb, char *base);
int     my_putnrb_base_rec(int nb, char *base);
void	my_basewhile(int c, int d, int ba, char *base);
int	my_put_nbr(int nb);
int     my_put_nrb_rec(int nb);
void	my_while(int a, int c, int d, int e);
int     my_getnbr(char *str);
char    *get_next_line(const int fd);
char    *my_concat_str(char *src, char *str);
char    **my_str_to_wordtab(char *str);
int     my_c_c(char *str);
int     my_c_w(char *str);
char	*my_epur_str(char *str);
int     my_nmatch(char *s1, char *s2, int pos);
int     my_nmatch_bis(char *s1, char *s2, int pos);

#endif
