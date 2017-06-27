/*
** my_minishell.h for minishell in /home/daniel_d/rendu/PSU_2013_minishell1/Lib/include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Dec 18 16:15:17 2013 daniel_d
** Last update Sun Mar  9 23:31:25 2014 daniel_d
*/

#ifndef MY_MINISHELL_H_
# define MY_MINISHELL_H_

int     my_prompt(char **envp);
int     run_cmd(char **envp, char *buffer);
int     my_parscmd(char **envp, char *buffer);
int	my_cd(char *buffer);
int	signal_set();
char    *my_path(char **envp);
char    *lscolor(char *buffer);
char    *my_epur_buffer(char *str);


#endif
