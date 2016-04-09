/*
** my_arg_dup.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Apr  6 10:29:39 2016 Hugo SOSZYNSKI
** Last update Sat Apr  9 11:37:56 2016 Hugo SOSZYNSKI
*/

#include	<unistd.h>
#include	<stddef.h>
#include	<stdlib.h>
#include	<limits.h>
#include	"mysh.h"

static int	my_arg_len(const char *line)
{
  int		cpt;

  cpt = 0;
  while (line[cpt] != '\0' && line[cpt] != ' ' && line[cpt] != ';' &&
	 line[cpt] != '<' && line[cpt] != '>' && line[cpt] != '|')
    {
      if (cpt == INT_MAX)
	{
	  write(2, "Error: my_arg_len: arg is to long (int overflow)\n", 49);
	  return (-1);
	}
      cpt++;
    }
  return (cpt);
}

char		*my_arg_dup(const char *line)
{
  char		*arg;
  int		len;
  int		cpt;

  if ((len = my_arg_len(line)) == -1)
    return (NULL);
  if ((arg = malloc((len + 1) * sizeof(char))) == NULL)
    return (error_null("Error: my_arg_dup: Can't perform malloc"));
  cpt = -1;
  while (++cpt < len)
    arg[cpt] = line[cpt];
  arg[len] = '\0';
  return (arg);
}
