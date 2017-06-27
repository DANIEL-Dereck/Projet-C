/*
** server.h for rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Server
** 
** Made by decouf_m
** Login   <decouf_m@epitech.net>
** 
** Started on  Sun May 11 05:23:37 2014 decouf_m
** Last update Sun May 11 03:44:48 2014 decouf_m
*/

#ifndef SERVER_H_
# define SERVER_H_

int     my_perror_int(char *src, int ret);
void    *my_perror_ptr(char *src);

t_manage        *clear_client(t_manage *m);
t_manage        *add_client(t_manage *m);
t_manage        *delete_client(t_manage *m, int i);

t_manage        *init_select(t_manage *m);
t_manage        *read_client(t_manage *m, int i);
t_manage        *select_client(t_manage *m);

#endif
