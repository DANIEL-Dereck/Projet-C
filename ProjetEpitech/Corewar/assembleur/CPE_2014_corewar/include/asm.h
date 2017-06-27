/*
** corewar.h for corewar_asm in /home/daniel_d/rendu/PSU_2014_Corewar/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Mar 17 09:49:06 2014 daniel_d
** Last update Sun Apr 13 21:35:02 2014 daniel_d
*/

#ifndef ASM_H_
# define ASM_H_

#define ERROR1 -1
#define ERROR2 -2
#define ERROR3 -3

typedef union union1
{
  int	a;
  char	tab[4];
} union1;

typedef struct s_oct
{
  int	a;
  int	*oct_pos;
  int	pos;
  char	**label;
  int	fdnf;
} t_oct;

int     assembleur_main(char *file);
int     verif_file(char *file);
char    *rename_file(char *str,  char *dest);
int     encoding_file(int fd, int fdnf, char *file);
int     my_header(int fdnf, char *buffer, int ligne);
char    **my_tab(char *buffer, char **commande);
int     my_who(char *commande, char *param, union1 *u, t_oct *oct);
int     my_whotwo(char *commande, char *param, union1 *u, t_oct *oct);
void	my_live(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_ld(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_st(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_add(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_sub(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_and(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_or(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_xor(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_zjmp(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_ldi(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_sti(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_fork(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_lld(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_lldi(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_lfork(char *param, int fdnf, union1 *u, t_oct *oct);
void	my_aff(char *param, int fdnf, union1 *u, t_oct *oct);
int     *binarisation(char **param, int *tab, int i, int c);
int     decimalisation(int *tab);
int     octalisation(char **param);
char    **my_param(char *str, char **params);
int     my_value(char *str);
void    my_value_write(int fdnf, char **plop, union1 *u, t_oct *oct);
char    *my_str_cpy(char *str1, char *str2);
char    *my_label(char *plop);
int     verifligne(char **command, int ligne);
t_oct	*init_oct(t_oct *oct, int fdnf);
char    **sepa(char *buffer);

#endif
