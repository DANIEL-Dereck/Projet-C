/*
** delet_maillon.c for delet in /home/daniel_d/rendu/rush_funk
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun May 11 15:29:01 2014 daniel_d
** Last update Sun May 11 15:29:32 2014 daniel_d
*/

t_monster  *delet_middel_maillon(t_monster *m, t_monster *tmp)
{
  m = m->prev;
  m->next = tmp->next;
  m = m->next;
  m->prev = tmp->prev;
}

t_monster       *delet_maillon(t_monster *tmp)
{
  t_monster     *m;

  m = tmp;
  if (m->next != NULL && m->prev != NULL)
    m = delet_middel_maillon(m, tmp);
  else if (m->next == NULL && m->prev != NULL)
    {
      m = m->prev;
      m->next = NULL;
    }
  else if (m->next != NULL && m->prev == NULL)
    {
      m = m->next;
      m->prev = NULL;
    }
  else
    {
      free(tmp);
      m = NULL;
    }
  return (m);
}
