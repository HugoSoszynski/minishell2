/*
** built_in.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/exec/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Apr 12 21:42:54 2016 Hugo SOSZYNSKI
** Last update Thu May  5 10:57:26 2016 Hugo SOSZYNSKI
*/

#include	"mysh.h"

int		is_built_in(t_list *current)
{
  int		ret;

  ret = my_strcmp(current->cmd[0], "cd");
  ret &= my_strcmp(current->cmd[0], "env");
  ret &= my_strcmp(current->cmd[0], "exit");
  ret &= my_strcmp(current->cmd[0], "setenv");
  ret &= my_strcmp(current->cmd[0], "unsetenv");
  if (!ret)
    {
      current->is_bi = true;
      return (SUCCESS);
    }
  current->is_bi = false;
  return (ERROR);
}

void		exec_built_in(t_data *exec, t_list *current, int fd)
{
  if (my_strcmp(current->cmd[0], "env") == SUCCESS)
    my_env(exec, fd);
  else if (my_strcmp(current->cmd[0], "exit") == SUCCESS)
    my_exit(exec, current);
  else if (my_strcmp(current->cmd[0], "unsetenv") == SUCCESS)
    my_unsetenv(exec, current);
  else if (my_strcmp(current->cmd[0], "setenv") == SUCCESS)
    my_setenv(exec, current, fd);
}
