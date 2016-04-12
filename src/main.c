/*
** main.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 29 16:31:36 2016 Hugo SOSZYNSKI
** Last update Tue Apr 12 15:03:51 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	"mysh.h"

int		error_msg(const char *msg)
{
  write(2, msg, my_strlen(msg));
  write(2, "\n", 1);
  return (ERROR);
}

int		error_mult(const char *msg, const char *part,
			   const char *end)
{
  write(2, msg, my_strlen(msg));
  write(2, part, my_strlen(part));
  write(2, end, my_strlen(end));
  write(2, "\n", 1);
  return (ERROR);
}

void		*error_null(const char *msg)
{
  write(2, msg, my_strlen(msg));
  write(2, "\n", 1);
  return (NULL);
}

int		main(int ac, char **av, char **env)
{
  t_data	exec;
  struct stat	prompt;

  (void)ac;
  (void)av;
  exec.exec_pos = 0;
  exec.exec_return = SUCCESS;
  exec.exit_return = 0;
  if (env == NULL || env[0] == NULL ||
      (exec.env = my_env_cpy((const char**)env)) == NULL)
    return (error_msg("Can't get or copy the env"));
  fstat(0, &prompt);
  if (((S_ISCHR(prompt.st_mode)) ? (mysh(&exec)) : (script(&exec))) != SUCCESS)
    return (ERROR);
  return (exec.exit_return);
}
