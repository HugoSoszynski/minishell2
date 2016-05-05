/*
** unsetenv.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/exec/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue May  3 17:15:14 2016 Hugo SOSZYNSKI
** Last update Thu May  5 10:38:12 2016 Hugo SOSZYNSKI
*/

#include		<stddef.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		"mysh.h"

static char		*get_var(const char *var)
{
  char			*var_cpy;
  int			var_len;
  int			cpt;

  var_len = my_strlen(var);
  if ((var_cpy = malloc((var_len + 2) * sizeof(char))) == NULL)
    return (NULL);
  cpt = -1;
  while (++cpt < var_len)
    var_cpy[cpt] = var[cpt];
  var_cpy[var_len] = '=';
  var_cpy[var_len + 1] = '\0';
  return (var_cpy);
}

int			var_pos(char **env, char *var)
{
  int			var_len;
  int			count;
  char			*var_cpy;

  if ((var_cpy = get_var(var)) == NULL)
    return (-1);
  var_len = my_strlen(var_cpy);
  count = 0;
  while (env[count] != NULL && my_strncmp(env[count], var_cpy, var_len) != 0)
    count++;
  free(var_cpy);
  return (count);
}

static void		del_of_env(char **env, char *var)
{
  int			pos;

  pos = var_pos(env, var);
  if (env[pos] != NULL)
    free(env[pos]);
  while (env[pos] != NULL)
    {
      env[pos] = env[pos + 1];
      pos++;
    }
}

void			my_unsetenv(t_data *exec, t_list *current)
{
  unsigned int		cpt;

  cpt = 1;
  while (current->cmd[cpt] != NULL)
    {
      del_of_env(exec->env, current->cmd[cpt]);
      cpt++;
    }
  if (cpt == 1)
    write(2, "unsetenv: Too few arguments.\n", 29);
}
