/*
** my_perror.c for rush#2 in /home/decouf_m/Projet/Epic_js_fantasy/Server
** 
** Made by decouf_m
** Login   <decouf_m@epitech.net>
** 
** Started on  Sun May 11 03:47:37 2014 decouf_m
** Last update Sun May 11 03:47:38 2014 decouf_m
*/

#include <stdlib.h>
#include <stdio.h>

int	my_perror_int(char *src, int ret)
{
  perror(src);
  return (ret);
}

void	*my_perror_ptr(char *src)
{
  perror(src);
  return (NULL);
}
