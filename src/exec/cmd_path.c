/*
** exec_cmd.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/exec/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Apr 11 11:06:18 2016 Hugo SOSZYNSKI
** Last update Fri May  6 16:59:58 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"mysh.h"

static char	*get_next_path(char *path, int *cpt)
{
  while (path[*cpt] != '\0' && path[*cpt] != ':')
    *cpt += 1;
  if (path[*cpt] == '\0')
    return (NULL);
  if (path[*cpt + 1] == '\0')
    return (NULL);
  *cpt += 1;
  return (&(path[*cpt]));
}

static int	test_tmp_path(char *tmp, char **cmd, int cmd_len)
{
  if ((tmp = my_path_dup(tmp, *cmd, cmd_len)) == NULL)
    return (error_msg("Error: check_path: Can't duplicate the path"));
  if (access(tmp, X_OK) == 0)
    {
      free(*cmd);
      *cmd = tmp;
      return (SUCCESS);
    }
  return (ERROR);
}

static int	check_path(char **cmd, t_data *exec)
{
  int		cpt;
  int		cmd_len;
  char		*tmp;
  char		*path;

  cpt = 0;
  if ((cmd_len = my_strlen(*cmd)) == -1)
    return (ERROR);
  if (access(cmd[0], X_OK) == 0)
    return (SUCCESS);
  if ((path = my_getenv(exec->env, "PATH")) == NULL)
    return (error_msg("Error: test_path: Can't access PATH env variable"));
  tmp = path;
  while (tmp != NULL)
    {
      if (test_tmp_path(tmp, cmd, cmd_len) == SUCCESS)
	return (SUCCESS);
      free(tmp);
      tmp = get_next_path(path, &cpt);
    }
  return (ERROR);
}

int		test_path(t_data *exec)
{
  t_list	*current;
  t_list	*pipe;

  current = exec->list;
  while (current != NULL)
    {
      if (is_built_in(current) && check_path(&(current->cmd[0]), exec))
	current->correct = false;
      pipe = current->pipe;
      while (pipe != NULL)
	{
	  if (is_built_in(current) && check_path(&(pipe->cmd[0]), exec))
	    pipe->correct = false;
	  pipe = pipe->pipe;
	}
      current = current->next;
    }
  return (SUCCESS);
}
