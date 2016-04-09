/*
** state_error.c for minishell3 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sat Apr  9 10:44:06 2016 Hugo SOSZYNSKI
** Last update Sat Apr  9 15:36:19 2016 Hugo SOSZYNSKI
*/

#include	"mysh.h"

int		state_error(char *line, int *cpt, t_list *current)
{
  int		state;

  current->correct = false;
  state = T_ERROR;
  while (state != T_SCOL && state != T_NULL)
    {
      state = find_next_state(line, cpt, state);
      *cpt += 1;
    }
  return (state);
}
