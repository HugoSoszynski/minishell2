/*
** state_cmd.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Apr  6 10:07:51 2016 Hugo SOSZYNSKI
** Last update Sat Apr  9 15:00:25 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"mysh.h"

static int	cmd_use_state(char *line, int *cpt,
			      t_list *current, int state)
{
  state = find_next_state(line, cpt, state);
  if (state == T_ARG)
    {
      if ((current->cmd =
	   add_to_wordtab(current->cmd, &(line[*cpt]))) == NULL)
	return (T_ERROR);
    }
  else if (state == T_SCOL)
    return (T_SCOL);
  return (state);
}

int		state_cmd(char *line, int *cpt, t_list *current)
{
  int		state;

  if ((current->cmd = malloc(2 * sizeof(char*))) == NULL)
    return (T_ERROR);
  current->cmd[1] = NULL;
  if ((current->cmd[0] = my_arg_dup(&(line[*cpt]))) == NULL)
    return (T_ERROR);
  current->origin = true;
  current->correct = true;
  state = T_CMD;
  while (state != T_NULL && state != T_ERROR && state != T_SCOL &&
	 state != T_PIPE)
    state = cmd_use_state(line, cpt, current, state);
  if (state == T_PIPE)
    state = state_pipe(line, cpt, current);
  return (state);
}
