/*
** lem_in.h for lem_in in /home/daniel_d/rendu/prog_elem/lem_in/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun May  4 20:45:35 2014 daniel_d
** Last update Sun May  4 23:23:33 2014 daniel_d
*/

#ifndef LEM_IN_H_
# define LEM_IN_H_

typedef struct s_node
{
  char *nom;
  int	order;
  int	fourmi;
  int	x;
  int	y;
  int	*pipe;
  int	*dist;
}t_node;

t_node  *my_node_tab(char **tab);
t_node  *my_info_in_node(char **tab, t_node *node);
t_node  *prepared_pipes(t_node *node);
void	init_str(int *str, int nb);
void    node_become_room(char *str, t_node *node);
void    clear_buffer(char *str);
void	my_pipe_conf(char **tab);
int     it_is_room(char *str);
int     main_lem_in();
int	pos_room(char *str);
int     pos_x_room(char *str);
int     pos_y_room(char *str);
int     lem_in_func(char *str);
int     us_lem_in(char **tab);
int     my_com(char *tab);

char    **my_algo(t_node *bloc);
int     my_trait_end(t_node *bloc);
int     my_trait_start(t_node *bloc);
int     my_calc_dist(t_node *bloc);
int     my_main_algo(t_node *bloc);

char	**my_str_to_strtab(char *str);
int	my_getnbr(char *str);
int     value_func(char *str, int s, int i, int k);
int     signe_func(char *str);

#endif /* LEM_IN_H_ */
