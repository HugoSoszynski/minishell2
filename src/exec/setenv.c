/*
** setenv.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/exec/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue May  3 17:08:20 2016 Hugo SOSZYNSKI
** Last update Thu May  5 11:48:07 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"mysh.h"

static char	*my_env_concat(const char *str1, const char *str2)
{
  char		*new;
  int		cpt;
  int		cpt_str;
  int		new_len;

  new_len = my_strlen(str1) + my_strlen(str2) + 2;
  if ((new = malloc(new_len * sizeof(char))) == NULL)
    return (NULL);
  cpt = 0;
  while (str1[cpt] != '\0')
    {
      new[cpt] = str1[cpt];
      cpt++;
    }
  new[cpt] = '=';
  cpt++;
  cpt_str = 0;
  while (str2[cpt_str] != '\0')
    {
      new[cpt] = str2[cpt_str];
      cpt_str++;
      cpt++;
    }
  new[new_len -1] = '\0';
  return (new);
}

void		change_env_var(char **env, int pos,
			       const char *var, const char *value)
{
  char		*new;

  if ((new = my_env_concat(var,
			   ((value == NULL) ? ("") : (value)))) == NULL)
    {
      write(2, "setenv: Error changing variable, no change applied\n", 51);
      return ;
    }
  free(env[pos]);
  env[pos] = new;
}

char		**add_env_var(char **env, const char *var, const char *value)
{
  char		**new_env;
  char		*new;
  int		len;
  int		cpt;

  len = 0;
  while (env[len] != NULL)
    len++;
  if ((new_env = malloc((len + 2) * sizeof(char*))) == NULL ||
      (new = my_env_concat(var, ((value == NULL) ? ("") : (value)))) == NULL)
    return (error_null("setenv: Error changing variable, no change applied"));
  cpt = 0;
  while (cpt < len)
    {
      new_env[cpt] = env[cpt];
      cpt++;
    }
  new_env[cpt] = new;
  new_env[cpt + 1] = NULL;
  free(env);
  return (new_env);
}

void		my_setenv(t_data *exec, t_list *current, int fd)
{
  int		pos;

  if (current->cmd[1] == NULL)
    {
      my_env(exec, fd);
      return ;
    }
  pos = var_pos(exec->env, current->cmd[1]);
  if (exec->env[pos] == NULL)
    {
      if ((exec->env = add_env_var(exec->env,
				   current->cmd[1], current->cmd[2])) == NULL)
	return ;
    }
  else
    change_env_var(exec->env, pos, current->cmd[1], current->cmd[2]);
}
