/*
** my_cd.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/exec/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Fri May  6 12:58:39 2016 Hugo SOSZYNSKI
** Last update Fri May  6 14:24:07 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<unistd.h>
#include	"mysh.h"

static void	move_directory(t_data *exec, const char *path)
{
  char		buf[4096];
  int		pos;
  char		*old_path;

  if (chdir(path) == -1 || getcwd(buf, 4096) == NULL)
    return ;
  if ((old_path = my_getenv(exec->env, "PWD")) == NULL)
    return ;
  pos = var_pos(exec->env, "OLDPWD");
  if (exec->env[pos] == NULL)
    {
      if ((exec->env = add_env_var(exec->env, "OLDPWD", old_path)) == NULL)
	return ;
    }
  else
    change_env_var(exec->env, pos, "OLDPWD", old_path);
  pos = var_pos(exec->env, "PWD");
  if (exec->env[pos] == NULL)
    {
      if ((exec->env = add_env_var(exec->env, "PWD", buf)) == NULL)
	return ;
    }
  else
    change_env_var(exec->env, pos, "PWD", buf);
}

void		my_cd(t_data *exec, t_list *current)
{
  char		*path;

  if (current->cmd[1] == NULL || current->cmd[1][0] == '~')
    {
      if ((path = my_getenv(exec->env, "HOME")) == NULL)
	return ;
    }
  else if (current->cmd[1][0] == '-')
    {
      if ((path = my_getenv(exec->env, "OLDPWD")) == NULL)
	return ;
    }
  else
    {
      path = current->cmd[1];
    }
  move_directory(exec, path);
}
