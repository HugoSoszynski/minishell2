/*
** exec_cmd.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/exec/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Apr 12 13:24:42 2016 Hugo SOSZYNSKI
** Last update Tue Apr 12 13:57:42 2016 Hugo SOSZYNSKI
*/

#include	<unistd.h>
#include	<stddef.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"mysh.h"

void		exec_cmd(t_data *exec)
{
  int		status;
  int		pid;
  if ((pid = fork()) == -1)
    return ;
  if (pid == 0)
    {
      exec->exec_pos = 1;
      if ((pid = execve(exec->current->cmd[0],
			exec->current->cmd, exec->env)) == -1)
	write(2, "Error: exec_cmd: Can't execve\n", 30);
      else
	waitpid(pid, &status, 0);
    }
  else
    waitpid(pid, &status, 0);
  (void)(status);
}
