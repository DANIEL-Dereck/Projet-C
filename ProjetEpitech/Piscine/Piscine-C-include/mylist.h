/*
** mylist.h for mylist.h in /home/daniel_d/rendu/Piscine-C-include
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Oct 22 09:18:29 2013 daniel_d
** Last update Tue Oct 22 09:30:28 2013 daniel_d
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

#endif /* LIST_H_ */
