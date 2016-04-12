/*
** my_path_dup.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/exec/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Apr 11 11:43:42 2016 Hugo SOSZYNSKI
** Last update Mon Apr 11 15:29:54 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	<limits.h>
#include	<unistd.h>
#include	"mysh.h"

static int	my_path_len(const char *line)
{
  int		cpt;

  cpt = 0;
  while (line[cpt] != '\0' && line[cpt] != ':')
    {
      if (cpt == INT_MAX)
	{
	  write(2, "Error: my_path_len: arg is to long (int overflow)\n", 49);
	  return (-1);
	}
      cpt++;
    }
  return (cpt);
}

char		*my_path_dup(const char *line, char *cmd, int cmd_len)
{
  char		*arg;
  int		len;
  int		cpt;
  int		count;

  if ((len = my_path_len(line)) == -1)
    return (NULL);
  if ((arg = malloc((len + cmd_len + 2) * sizeof(char))) == NULL)
    return (error_null("Error: my_path_dup: Can't perform malloc"));
  cpt = -1;
  while (++cpt < len)
    arg[cpt] = line[cpt];
  count = -1;
  arg[cpt] = (arg[cpt - 1] == '/') ? ('\0') : ('/');
  cpt = (arg[cpt] == '/') ? (cpt + 1) : (cpt);
  while (++count < cmd_len)
    arg[cpt++] = cmd[count];
  arg[cpt] = '\0';
  return (arg);
}
