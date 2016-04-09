/*
** my_epurstr.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Fri Apr  1 15:39:41 2016 Hugo SOSZYNSKI
** Last update Sat Apr  9 13:03:21 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"mysh.h"

static void	change_to_space(char *str)
{
  int		cpt;

  cpt = -1;
  while (str[++cpt] != '\0')
    {
      if (str[cpt] == '\t')
	str[cpt] = ' ';
    }
}

static int	chose_to_copy(char *new, char *str,
			      int new_cpt, int str_cpt)
{
  if (str[str_cpt] == ' ')
    return (0);
  if (str_cpt > 0 && str[str_cpt] != ' ' && str[str_cpt - 1] == ' ' &&
      new_cpt != 0)
    {
      new[new_cpt] = ' ';
      new[new_cpt + 1] = str[str_cpt];
      return (2);
    }
  new[new_cpt] = str[str_cpt];
  return (1);
}

char		*my_epurstr(char *str)
{
  char		*new;
  int		str_cpt;
  int		new_cpt;

  new = NULL;
  if ((new = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  change_to_space(str);
  str_cpt = -1;
  while (str[++str_cpt] == ' ' && str[str_cpt] != '\0');
  new_cpt = 0;
  while (str[str_cpt] != '\0')
    {
      new_cpt += chose_to_copy(new, str, new_cpt, str_cpt);
      str_cpt++;
    }
  new[new_cpt] = '\0';
  free(str);
  return (new);
}
