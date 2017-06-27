/*
** my.h for my.h in /home/julien_t/rendu/Piscine-C-include
** 
** Made by julien_t
** Login   <julien_t@epitech.net>
** 
** Started on  Thu Oct 10 18:09:00 2013 julien_t
** Last update Thu Feb 13 17:58:28 2014 julien_t
*/

#ifndef MY_
# define MY_

void	 my_putchar(char);
int	 my_isneg(int);
int	 my_put_nbr(int);
int	 my_swap(int *, int *);
int	 my_putstr(char *);
int	 my_strlen(char *);
int	 my_getnbr(char *);
void	 my_sort_int_tab(int *, int);
int	 my_power_rec(int, int);
int	 my_square_root(int);
int	 my_is_prime(int);
int	 my_find_prime_sup(int);
char	 *my_strcpy(char *, char *);
char	*my_strdup(char *str);
char	 *my_strncpy(char *, char *, int);
char	 *my_revstr(char *);
char	 *my_strstr(char *, char *);
int	 my_strcmp(char *, char *);
int	 my_strncmp(char *, char *, int);
char	 *my_strupcase(char *);
char	 *my_strlowcase(char *);
char	 *my_strcapitalize(char *);
int	 my_str_isalpha(char *);
int	 my_str_isnum(char *);
int	 my_str_islower(char *);
int	 my_str_isupper(char *);
int	 my_str_isprintable(char *);
char    **my_str_to_wordtab(char *str);
int	 my_showstr(char *);
int	 my_showmem(char *, int);
char	 *my_strcat(char *, char *);
char	 *my_strncat(char *, char *, int);
int	 my_strlcat(char *, char *, int);
char	*get_next_line(int fd);
char	*my_realloc(char *, int);
char    **my_str_to_wordtab2(char *str);
#endif
