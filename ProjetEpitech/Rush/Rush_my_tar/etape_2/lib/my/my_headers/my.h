/*
** libmy.h for libmy in /home/bertho_d/rendu/Piscine-C-include
** 
** Made by bertho_d
** Login   <bertho_d@epitech.net>
** 
** Started on  Tue Oct  8 09:51:37 2013 bertho_d
** Last update Thu Nov 28 15:36:16 2013 bertho_d
*/

#ifndef MY_H_
# define MY_H_

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

/*
** io functions :
*/
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_n_chars(char c, int n);
void	my_showstr_n_base(char *str, int len, char *base);
void	my_showstr(char *str);

void	my_putnbr(int nb);
void	my_u_putnbr(unsigned int nb);
void	my_putnbr_base(int nb, char *base);
void	my_ulong_putnbr_base(unsigned long nb, char *base);

int	my_getnbr_base(char *str, char *base);
int	my_getnbr(char *str);
int	my_atoi(char *str);

int	get_numstr_sign(char *str, int *pos);
int	check_numstr(char *str, char *base);
int	my_check_base(char *base, char *forbidden_chars);

int	my_showmem(char *str, int size);

int	my_printf(const char *format, ...);

char	*get_next_line(const int fd);

/*
** math functions :
*/
int	my_pow(int nb, int power);
int	my_sqrt(int nb);
int	my_floor_sqrt(int nb);
int	my_is_prime(int nb);
int	my_find_prime_sup(int nb);

/*
** string functions :
*/
char	*my_strstr(char *str, char *to_find);
int	my_strlen(char *str);

int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
int	my_strcmp_alpha(char *s1, char *s2);

char	*my_strdup(char *str);
char	*my_strcat_alloc(char *dest, char *src);

char	*my_revstr(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);

int	read_positive_int(const char *str, int *nb, int non_zero);

/*
** utility functions :
*/
int	my_char_type(char c);
int	my_find_char(char c, char *str);
char	*next_non_num_char(char *str);
void	my_memset(char *address, char value, int len);
int	calc_u_nb_len(unsigned long nb, int base_type);

/*
** lists functions :
*/
void	list_swap_elems(t_list *elem1, t_list *elem2);
void	list_free(t_list *list, int free_data);
void	list_free_f(t_list *list, void (*free_data)());
t_list	*list_remove_elem(t_list *elem, int free_data);
t_list	*list_new_elem(void *data, t_list *next);

t_list	*list_concat(t_list *l1, t_list *l2);
t_list	*list_rev(t_list *elem, t_list *prev);
void	list_sort(t_list *begin, int (*cmp)());
void	list_apply_fct(t_list *list, int (*f)());
void	list_rm_matching(t_list **list, int (*match)(), int free_data);

#endif
