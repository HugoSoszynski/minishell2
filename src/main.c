/*
** main.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 29 16:31:36 2016 Hugo SOSZYNSKI
** Last update Tue May  3 14:47:32 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<signal.h>
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

void		my_sighandler(int signum)
{
  write(2, "\n$> ", 4);
  (void)(signum);
}

int		main(int ac, char **av, char **env)
{
  t_data	exec;
  struct stat	prompt;

  (void)ac;
  (void)av;
  if (signal(SIGINT, my_sighandler) == SIG_ERR)
    return (ERROR);
  init_data(&exec);
  if (env == NULL || env[0] == NULL ||
      (exec.env = my_env_cpy((const char**)env)) == NULL)
    return (error_msg("Can't get or copy the env"));
  fstat(0, &prompt);
  (S_ISCHR(prompt.st_mode)) ? (mysh(&exec)) : (script(&exec));
  return (exec.exit_return);
}
