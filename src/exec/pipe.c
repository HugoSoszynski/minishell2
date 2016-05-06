/*
** pipe.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/exec/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Thu May  5 14:31:55 2016 Hugo SOSZYNSKI
** Last update Fri May  6 13:26:54 2016 Hugo SOSZYNSKI
*/

#include	<unistd.h>
#include	<stddef.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"mysh.h"

static int	pipe_cmd(t_data *exec, t_pipe *pipes)
{
  t_list	*current;
  int		cpt;

  current = exec->current;
  pipes->nb_pipe = 0;
  while (current != NULL)
    {
      pipes->nb_pipe += 1;
      current = current->pipe;
    }
  if ((pipes->fd = malloc(pipes->nb_pipe * sizeof(int*))) == NULL)
    return (error_msg("Error: pipe_cmd: Can't malloc"));
  cpt = 0;
  while (cpt < pipes->nb_pipe)
    {
      if ((pipes->fd[cpt] = malloc(2 * sizeof(int))) == NULL)
	return (error_msg("Error: pipe_cmd: Can't malloc"));
      if (pipe(pipes->fd[cpt]) == -1)
	return (error_msg("Error: pipe_cmd: Can't create pipe"));
      cpt++;
    }
    if ((pipes->pid = malloc(pipes->nb_pipe * sizeof(int))) == NULL)
      return (error_msg("Error: pipe_cmd: Can't create pipe"));
  return (SUCCESS);
}

static void	close_fd(t_pipe *pipes)
{
  int		cpt;

  cpt = 0;
  while (cpt < pipes->nb_pipe)
    {
      close(pipes->fd[cpt][0]);
      close(pipes->fd[cpt][1]);
      cpt++;
    }
}

static void	wait_childs(t_pipe *pipes)
{
  int		cpt;
  int		status;

  close_fd(pipes);
  status = 0;
  cpt = 0;
  while (cpt < pipes->nb_pipe)
    {
      waitpid(pipes->pid[cpt], &status, WCONTINUED);
      if (status == 139)
	write(2, "Segmentation Fault\n", 19);
      cpt++;
    }
  cpt = 0;
  while (cpt < pipes->nb_pipe)
    {
      free(pipes->fd[cpt]);
      cpt++;
    }
  free(pipes->fd);
  free(pipes->pid);
}

static void	launch_pipe_exec(t_data *exec, t_pipe *pipes,
				 int cpt, t_list *current)
{
  exec->exec_pos = 1;
  if (cpt > 0)
    dup2(pipes->fd[cpt - 1][0], 0);
  if (cpt < pipes->nb_pipe - 1)
    dup2(pipes->fd[cpt][1], 1);
  close_fd(pipes);
  if (current->is_bi == true)
    exec_built_in(exec, current, 1);
  else
    {
      if ((pipes->pid[cpt] = execve(current->cmd[0],
				    current->cmd, exec->env)) == -1)
	write(2, "Error: exec_cmd: Can't execve\n", 30);
    }
}

void		exec_pipe(t_data *exec)
{
  t_pipe	pipes;
  int		cpt;
  t_list	*current;

  if (pipe_cmd(exec, &pipes) != SUCCESS)
    return ;
  current = exec->current;
  cpt = -1;
  while (++cpt < pipes.nb_pipe)
    {
      if (my_strcmp(current->cmd[0], "exit") == SUCCESS)
	exec_built_in(exec, current, 1);
      else
	{
	  if ((pipes.pid[cpt] = fork()) == -1)
	    return ;
	  else if (pipes.pid[cpt] == 0)
	    {
	      launch_pipe_exec(exec, &pipes, cpt, current);
	      return ;
	    }
	  current = current->pipe;
	}
    }
  wait_childs(&pipes);
}
