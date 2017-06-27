/*
** string.c for rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Client/src
** 
** Made by decouf_m
** Login   <decouf_m@epitech.net>
** 
** Started on  Sat May 10 17:19:53 2014 decouf_m
** Last update Sat May 10 17:20:35 2014 decouf_m
*/

#include <stdlib.h>
#include <unistd.h>

int     my_putstr(char *src)
{
  int   i;

  i = 0;
  while (src[i])
    {
      write(1, &src[i], 1);
      i += 1;
    }
  return (0);
}

void    *my_put_error_ptr(char *src)
{
  my_putstr(src);
  return (NULL);
}
