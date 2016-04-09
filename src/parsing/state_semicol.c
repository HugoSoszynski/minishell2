/*
** state_semicol.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Fri Apr  8 18:34:54 2016 Hugo SOSZYNSKI
** Last update Sat Apr  9 18:44:31 2016 Hugo SOSZYNSKI
*/

#include	"mysh.h"

int		state_semicol(char *line, int *cpt)
{
  while (line[*cpt] == ';' || line[*cpt] == ' ')
    *cpt += 1;
  if (line[*cpt] == '\0')
    return (T_NULL);
  if (line[*cpt] == '>' || line[*cpt] == '<' || line[*cpt] == '|')
    return (T_ERROR);
  return (T_CMD);
}
