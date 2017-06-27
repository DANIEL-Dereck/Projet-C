/*
** my.h for my.h in /home/daniel_d/rendu/Piscine-C-Jour_09/ex_02
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Oct 10 14:50:55 2013 daniel_d
** Last update Tue Dec 10 12:55:28 2013 daniel_d
*/

#ifndef MY_H_
# define MY_H_

#define BUFFER_SIZE	10
#include <stdarg.h>

void	my_putchar(char c);
int     my_putstr(char *str);

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
int	my_isneg(int nb);
int     my_needposchar(char *str, char c);
char    *my_strdup(char *src);
int	my_swap(int *a, int *b);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);

char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);


int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);

int	my_put_nbru(unsigned int nb);
int	my_putnbr_base(int nb, char *base);
int     my_putnrb_base_rec(int nb, char *base);
void	my_basewhile(int c, int d, int ba, char *base);

int	my_put_nbr(int nb);
int     my_put_nrb_rec(int nb);
void	my_while(int a, int c, int d, int e);

int     my_getnbr(char *str);

char    *get_next_line(const int fd);

#endif
