/*
** sudoku.h for rush in /home/daniel_d/rendu/Rush-Sudoku-bi/Lib/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat Mar  1 08:59:51 2014 daniel_d
** Last update Sat Mar  1 17:40:05 2014 daniel_d
*/

#ifndef SUDOKU_H_
# define SUDOKU_H_

#define ERROR -1
#define NOP '+'

typedef struct xy
{
  
} t_xy;

void	res();
void	my_free(char **sudo);
int	sudokumain(char ** av);
char	**epur_sudo(char **sudo);

#endif
