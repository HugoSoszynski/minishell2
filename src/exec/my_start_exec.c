/*
** my_start_exec.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/exec/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sun Apr 10 10:05:40 2016 Hugo SOSZYNSKI
** Last update Fri May  6 10:16:54 2016 Hugo SOSZYNSKI
*/

#include	<unistd.h>
#include	<stddef.h>
#include	"mysh.h"

static int	my_clean_wordtab(char **tab)
{
  int		cpt;

  cpt = 0;
  while (tab[cpt] != NULL)
    {
      if ((tab[cpt] = my_epurstr(tab[cpt])) == NULL)
	return (error_msg("Error: my_clean_wordtab: NULL while epuration"));
      cpt++;
    }
  return (SUCCESS);
}

static int	my_clean_cmd(t_data *exec)
{
  t_list	*current;
  t_list	*pipe;

  current = exec->list;
  while (current != NULL)
    {
      if (my_clean_wordtab(current->cmd))
	return (ERROR);
      pipe = current->pipe;
      while (pipe != NULL)
	{
	  if (my_clean_wordtab(pipe->cmd))
	    return (ERROR);
	  pipe = pipe->pipe;
	}
      current = current->next;
    }
  return (SUCCESS);
}

static int	my_check_cmd(t_list *current)
{
  t_list	*pipe;

  if (current->correct == false)
    return (error_mult("Error: ", current->cmd[0], ": Command not found"));
  pipe = current->pipe;
  while (pipe != NULL)
    {
      if (pipe->correct == false)
	return (error_mult("Error: ", pipe->cmd[0], ": Command not found"));
      pipe = pipe->pipe;
    }
  return (SUCCESS);
}

void		my_start_exec(t_data *exec)
{
  if (my_clean_cmd(exec))
    return ;
  if (test_path(exec) != SUCCESS)
    return ;
  while (exec->exec_pos == 0 && exec->current != NULL)
    {
      if (!my_check_cmd(exec->current))
	{
	  if (exec->current->pipe != NULL)
	    exec_pipe(exec);
	  else
	    exec_cmd(exec);
	}
      exec->current = exec->current->next;
    }
}
