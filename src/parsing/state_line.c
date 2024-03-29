/*
** state_line.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Apr  5 18:44:29 2016 Hugo SOSZYNSKI
** Last update Sat Apr  9 13:22:15 2016 Hugo SOSZYNSKI
*/

#include	"mysh.h"

int		state_line(char *line, int *cpt)
{
  while (line[*cpt] == ';' || line[*cpt] == ' ')
    *cpt += 1;
  if (line[*cpt] == '\0')
    return (T_NULL);
  if (line[*cpt] == '>' || line[*cpt] == '<' || line[*cpt] == '|')
    return (T_ERROR);
  return (T_CMD);
}
