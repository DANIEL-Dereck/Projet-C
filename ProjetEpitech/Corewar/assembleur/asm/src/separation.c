/*
** separation.c for saper in /home/daniel_d/rendu/asm/src
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Apr 13 18:55:14 2014 daniel_d
** Last update Sun Apr 13 21:31:37 2014 daniel_d
*/

char	**sepapa(char **tab, int i, int l, char *buffer)
{ 
  while (buffer[i] == ' ' && buffer[i] == '\t')
    i++;
  while (buffer[i] != '\0')
    {
      l++;
      i++;
    }
  if ((tab[1] = malloc(sizeof(*tab)) * (l + 1)) == NULL)
    return (NULL);
  i = i - l;
  l = 0;
  while (buffer[i] != '\0')
    {
      tab[1][l] = buffer[i];
      l++;
      i++;
    }
  return (tab); 
}

char	**sepa(char	*buffer)
{
  int	l;
  int	i;
  char	**tab;

  i = 0;
  l = 0;
  if ((tab = malloc(sizeof(tba) * 2)) == NULL)
    return (NULL);
  while (buffer[i] != ' ' && buffer[i] != '\t')
    i++;
  if ((tab[0] = malloc(sizeof(*tab) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (buffer[i] != ' ' && buffer[i] != '\t')
    {
      tab[0][i] = buffer[i];
      i++;
    }
  tab[0][i] = '\0';
  tab  = sepapa(tab, i, l, buffer);
  return (tab);
}
