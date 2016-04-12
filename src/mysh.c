/*
** mysh.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 29 17:00:46 2016 Hugo SOSZYNSKI
** Last update Sun Apr 10 15:27:08 2016 Hugo SOSZYNSKI
*/

#include	<unistd.h>
#include	<stddef.h>
#include	<stdlib.h>
#include	"mysh.h"
#include	"get_next_line.h"

static char	*my_prompt(void)
{
  char		*line;

  line = NULL;
  write(1, "$> ", 3);
  line = get_next_line(0);
  return (line);
}

static void	pars_and_exec(t_data *exec, char **line)
{
  if (**line != '\0')
    {
      if ((exec->list = my_smachine(line)) != NULL)
	{
	  exec->current = exec->list;
	  my_start_exec(exec);
	  my_free_list(exec->list);
	}
    }
}

int		script(t_data *exec)
{
  char		*line;

  while (exec->exec_pos == 0 && (line = get_next_line(0)) != NULL)
    {
      pars_and_exec(exec, &line);
      free(line);
    }
  my_free_wordtab(exec->env);
  return (exec->exec_return);
}

int		mysh(t_data *exec)
{
  char		*line;

  while (exec->exec_pos == 0 && (line = my_prompt()) != NULL)
    {
      pars_and_exec(exec, &line);
      free(line);
    }
  my_free_wordtab(exec->env);
  if (exec->exec_pos == 0)
    write(1, "exit\n", 5);
  return (exec->exec_return);
}
