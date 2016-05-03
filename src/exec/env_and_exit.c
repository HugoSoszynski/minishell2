/*
** env_and_exit.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/exec/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue May  3 11:08:58 2016 Hugo SOSZYNSKI
** Last update Tue May  3 15:27:40 2016 Hugo SOSZYNSKI
*/

#include	<unistd.h>
#include	"mysh.h"

void		my_exit(t_data *exec, t_list *current)
{
  exec->exit_bool = true;
  if (current->cmd[1] != NULL)
    {
      exec->exit_return = (unsigned char)(my_getnbr(current->cmd[1]));
    }
}

void		my_env(t_data *exec, int fd)
{
  unsigned int	cpt;

  cpt = 0;
  while (exec->env[cpt] != NULL)
    {
      write(fd, exec->env[cpt], my_strlen(exec->env[cpt]));
      write(fd, "\n", 1);
      cpt++;
    }
}
