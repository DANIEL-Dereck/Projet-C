/*
** my_minishell.h for minishell in /home/daniel_d/rendu/PSU_2013_minishell1/Lib/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Dec 18 16:15:17 2013 daniel_d
** Last update Mon Jan  6 20:50:08 2014 daniel_d
*/

#ifndef MY_MINISHELL_H_
# define MY_MINISHELL_H_

int     run_cmd(char **envp, char *buffer);
int     my_prompt(char **envp);
char	*my_concat_str(char *usrbin, char *cmd);
int     my_clear_prompt(char **envp);
void	get_sigall();
void	signal_set();

#endif
