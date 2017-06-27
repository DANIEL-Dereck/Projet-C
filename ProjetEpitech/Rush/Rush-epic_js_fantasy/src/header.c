/*
** header.c for epic_rush in /home/daniel_d/rendu/rush-epic_js_fantasy/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sat May 10 21:57:16 2014 daniel_d
** Last update Sat May 10 21:58:46 2014 daniel_d
*/

int     header(int fd, t_headerg *h)
{
  int   retour_val;
  int   *verif;

  if ((verif = malloc(sizeof(verif) * 6)) == NULL)
    return (-1);
  verif[0] = add_in_file(fd, MAGIC_NUMBER, NULL, 1);
  verif[1] = add_in_file(fd, HEADER, NULL, 0);
  verif[2] = add_in_file(fd, NAME, h->name, 0);
  verif[3] = add_in_file(fd, ROOM_TO_WIN, h->room_to_win, 0);
  verif[4] = add_in_file(fd, ROOM_TO_START, h->room_to_start, 0);
  verif[5] = add_in_file(fd, SPE_SECTION, NULL, 1);
  retour_val = resum_error(verif, 9);
  free(verif);
  return (retour_val);
}

t_headerg       *init_header(t_headerg *h)
{
  h->name = strdup("name");
  h->room_to_win = strdup("room_to_win");
  h->room_to_start = strdup("room_to_start");
  return (h);
}

int     remp_header(int fd)
{
  t_headerg     *h;

  if ((h = malloc(sizeof(*h))) == NULL)
    return (-1);
  h = init_header(h);
  header(fd, h);
  return (0);
}
