/*
** sudoku.h for rush in /home/daniel_d/rendu/Rush-Sudoku-bi/Lib/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat Mar  1 08:59:51 2014 daniel_d
** Last update Sat Mar  1 22:59:43 2014 bidard_v
*/

#ifndef SUDOKU_H_
#define SUDOKU_H_

typedef struct s_sudo
{
  int	x;
  int	y;
  int	x2;
  int	y2;
  int	**boole;
} t_sudo;

int	sudokumain(int);
t_sudo	*my_init();
void	my_free(char**, t_sudo*);
void	my_res(char**, t_sudo*);
void	my_affichage(char**);

#endif
