/*
** my.h for lib in /home/jouana_j/rendu/MUL_2013_fdf/lib/my
** 
** Made by jouana_j
** Login   <jouana_j@epitech.net>
** 
** Started on  Sun Dec  8 11:38:29 2013 jouana_j
** Last update Sun Dec  8 11:38:31 2013 jouana_j
*/

#ifndef MY_H_
#define MY_H_

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_find_prime_sup(int nb);
int	my_getnbr(char *str);
void	my_isneg(int n);
int	my_is_prime(int nb);
int	my_power_rec(int nb, int power);
void	my_put_nbr(int nb);
char	*my_revstr(char *str);
int	my_showmem(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_square_root(int nb);
char	*mmy_strcapitalize(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
int	my_putnbr(int n);
int	my_str_is_lower(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int	my_str_isupper(char *str);
char	*my_strlcar(char *dest, char *src, int size);
int	my_strlen(char *str);
char	*my_strlowcase(char *str);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strstr(char *str, char *to_find);
char	*my_strupcase(char *str);
void	my_swap(int *a, int *b);
void	my_putnbr_base(int nb, int base, int upcase);
int	my_getnbr_base(char *str, int base);
void	my_putnbr_base_long(long nb, int base, int upcase);
void	my_put_nbr_u(unsigned int nb);
unsigned int my_putnbr_u_rec(unsigned int nb);
char	*my_get_nextline(int fd);
void	my_printf(const char *format, ...);
char	*my_realloc(char *str, int size);

#endif
