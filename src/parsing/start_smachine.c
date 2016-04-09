/*
** start_smachine.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Fri Apr  1 15:30:02 2016 Hugo SOSZYNSKI
** Last update Sat Apr  9 15:18:53 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"mysh.h"

void		init_cmd_node(t_list *current)
{
  current->next = NULL;
  current->pipe = NULL;
  current->cmd = NULL;
  current->correct = false;
  current->origin = false;
}

static int	my_pars_line(char *line, t_list *current, int state, int cpt)
{
  while (state != T_NULL)
    {
      if (state == T_SCOL)
	state = state_semicol(line, &cpt);
      else if (state == T_CMD)
	{
	  if ((current->next = malloc(sizeof(t_list))) == NULL)
	    return (error_msg("Error: my_smachine: Can't create the list"));
	  current = current->next;
	  init_cmd_node(current);
	  state = state_cmd(line, &cpt, current);
	}
      else if (state == T_ERROR)
	{
	  state = state_error(line, &cpt, current);
	  return (error_msg("Invalid syntax"));
	}
    }
  return (SUCCESS);
}

t_list		*my_smachine(char **line)
{
  t_list	*list;
  t_list	*current;
  int		state;
  int		cpt;

  cpt = 0;
  current = NULL;
  if ((*line = my_epurstr(*line)) == NULL)
    return (error_null("Error: my_smachine: my_epurstr returned NULL"));
  state = state_line(*line, &cpt);
  if (state == T_NULL)
    return (NULL);
  if (state == T_ERROR)
    return (error_null("Invalid Syntax"));
  else if (state == T_CMD)
    {
      if ((current = malloc(sizeof(t_list))) == NULL)
	return (error_null("Error: my_smachine: Can't create the list"));
      init_cmd_node(current);
      state = state_cmd(*line, &cpt, current);
    }
  list = current;
  state = my_pars_line(*line, current, state, cpt);
  return (list);
}
