/*
** start_smachine.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Fri Apr  1 15:30:02 2016 Hugo SOSZYNSKI
** Last update Wed Apr  6 17:52:34 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	"mysh.h"

static int	my_pars_line(char *line, t_list *current, int state)
{
  
}

t_list		*my_smachine(char *line)
{
  t_list	*list;
  t_list	*current;
  int		state;

  current = NULL;
  if ((line = my_epurstr(line)) == NULL)
    {
      error_msg("Error: my_epurstr returned NULL");
      return (NULL);
    }
  state = state_line(line);
  if (state == T_ERROR)
    return (error_null("Invalid Syntax"));
  if (state == T_SCOL)
    state_semicol(line);
  else if (state == T_CMD)
    if ((list = state_cmd(line)))
	return (error_null("Error: my_smachine: Can't create the list"));
}
