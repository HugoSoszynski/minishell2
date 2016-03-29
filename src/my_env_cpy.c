/*
** my_env_cpy.c for mysh in /home/soszyn_h/rendu/PSU/PSU_2015_minishell1
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Jan 19 11:04:05 2016 Hugo SOSZYNSKI
** Last update Tue Mar 29 16:41:54 2016 Hugo SOSZYNSKI
*/

#include	<stdlib.h>
#include	<stddef.h>
#include	"mysh.h"

char		**my_env_cpy(const char **env)
{
  int		count;
  int		i;
  char		**cpy;

  count = 0;
  while (env[count] != NULL)
    count++;
  if ((cpy = malloc((count + 1) * sizeof(char*))) == NULL)
    return (NULL);
  cpy[count] = NULL;
  i = 0;
  while (i < count)
    {
      if ((cpy[i] = malloc((my_strlen(env[i]) + 1) * sizeof(char))) == NULL)
	return (NULL);
      my_strcpy(cpy[i], env[i]);
      i++;
    }
  return (cpy);
}

void		my_free_wordtab(char **tab)
{
  int		cpt;

  cpt = 0;
  while (tab[cpt] != NULL)
    {
      free(tab[cpt]);
      tab[cpt] = NULL;
      cpt++;
    }
  free(tab);
  tab = NULL;
}
