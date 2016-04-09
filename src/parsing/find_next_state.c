/*
** find_next_state.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Thu Apr  7 14:44:20 2016 Hugo SOSZYNSKI
** Last update Sat Apr  9 16:43:01 2016 Hugo SOSZYNSKI
*/

#include	"mysh.h"

int		find_next_state(char *line, int *cpt, int state)
{
  while (line[*cpt] != '\0' && line[*cpt] != '<' && line[*cpt] != '|' &&
	 line[*cpt] != ';' && line[*cpt] != ' ' && line[*cpt] != '>' &&
	 (state == T_CMD || state == T_ARG))
    *cpt += 1;
  while (line[*cpt] == ' ')
    *cpt += 1;
  if (line[*cpt] == '\0')
    return (T_NULL);
  else if (line[*cpt] == '|')
    return (T_PIPE);
  else if (line[*cpt] == '<')
    return (T_ERROR);
  else if (line[*cpt] == '>')
    return (T_ERROR);
  else if (line[*cpt] == ';')
    return (T_SCOL);
  else if (state == T_CMD || state == T_ARG)
    return (T_ARG);
  return (T_CMD);
}
