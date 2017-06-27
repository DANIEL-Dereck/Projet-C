/*
** boogle.h for boogle in /home/marrec_k/Colle
**
** Made by marrec_k
** Login   <marrec_k@epitech.net>
**
** Started on  Wed May 21 14:06:35 2014 marrec_k
** Last update Wed May 21 17:13:48 2014 marrec_k
*/

#ifndef BOOGLE_H_
# define BOOGLE_H_

typedef struct s_data
{
  int	size;
  char	*grid;
  char	*word;
  char	color;
  int	*save;
} t_data;

void	my_putchar(char);
int	my_strlen(char *);
void	my_putstr(char *);
int	my_strcmp(char *, char *);
char	*my_strdup(char *);
int	my_getnbr(char *);
int	my_puterror(char *, int);
char	*get_next_line(int);
void	my_init_data(t_data *);
int	my_get_data(t_data *, char **);
int	my_check(t_data *);
char	*my_generate_grid(int);
void	my_show_grid(t_data *);
int	my_check_word_in_grid(t_data *);
int	my_check_left(t_data *, int *, int);
int	my_check_right(t_data *, int *, int);
int	my_check_up(t_data *, int *, int);
int	my_check_down(t_data *, int *, int);
int	my_check_pos_in_save(int *, int);

#endif
