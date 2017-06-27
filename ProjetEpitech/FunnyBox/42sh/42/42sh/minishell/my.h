/*
** my.h for my in /home/boucha_q/rendu/Piscine-C-lib/my/,Piscine-C-include
**
** Made by boucha_q
** Login   <boucha_q@epitech.net>
**
** Started on  Fri Oct 11 10:50:43 2013 boucha_q
** Last update Tue May 20 14:03:04 2014 bouchard alexandre
*/

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int*b);
void	my_putstr(char *str);
int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char    *my_strcat(char *dest, char *src);
int     my_getnbr(char *str);
int     my_strcmp(char *s1, char *s2);
char    *my_strdup(char *src);
int     my_str_isalpha(char *str);
char    *my_strncat(char *dest, char *src, int f);
/* my_str_to_wordtab.c */
int     count_line_str(char *);
int     count_long_line_str(char *, int);
int     count_long_line_str(char *, int);
char    **my_str_to_wordtab(char *);
