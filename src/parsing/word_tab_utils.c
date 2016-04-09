/*
** word_tab_utils.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Apr  6 10:12:23 2016 Hugo SOSZYNSKI
** Last update Sat Apr  9 18:42:45 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	<limits.h>
#include	<unistd.h>
#include	"mysh.h"

static int	wordtab_len(char **tab)
{
  int		cpt;

  cpt = 0;
  while (tab[cpt] != NULL)
    {
      if (cpt == INT_MAX)
	{
	  write(2, "Error: wordtab_len: tab is to long (int overflow)\n", 50);
	  return (-1);
	}
      cpt++;
    }
  return (cpt);
}

char		**add_to_wordtab(char **src, char *arg)
{
  char		**tmp;
  int		len;
  int		cpt;

  if ((len = wordtab_len(src)) == -1)
    return (NULL);
  if ((tmp = malloc((len + 2) * sizeof(char*))) == NULL)
    return (error_null("Error: wordtab_len: can't perform malloc"));
  cpt = 0;
  while (src[cpt] != NULL)
    {
      tmp[cpt] = src[cpt];
      cpt++;
    }
  free(src);
  if ((tmp[len] = my_arg_dup(arg)) == NULL)
    return (error_null("Error: wordtab_len: can't duplicate last arg"));
  tmp[len + 1] = NULL;
  return (tmp);
}
