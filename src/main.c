/*
** main.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 29 16:31:36 2016 Hugo SOSZYNSKI
** Last update Wed Apr  6 10:21:23 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<unistd.h>
#include	"mysh.h"

int		error_msg(const char *msg)
{
  write(2, msg, my_strlen(msg));
  write(2, "\n", 1);
  return (ERROR);
}

int		error_null(const char *msg)
{
  write(2, msg, my_strlen(msg));
  write(2, "\n", 1);
  return (NULL);
}

int		main(int ac, char **av, char **env)
{
  char		**env_cpy;

  (void)ac;
  (void)av;
  if (env == NULL || env[0] == NULL ||
      (env_cpy = my_env_cpy((const char**)env)) == NULL)
    return (error_msg("Can't get or copy the env"));
  if (mysh(env_cpy) != SUCCESS)
    return (ERROR);
  return (SUCCESS);
}
