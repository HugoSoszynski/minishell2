/*
** state_line.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/parsing/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Apr  5 18:44:29 2016 Hugo SOSZYNSKI
** Last update Wed Apr  6 10:03:36 2016 Hugo SOSZYNSKI
*/

int		state_line(char *line)
{
  if (line[0] == ';')
    return (T_SCOL);
  if (line[0] == '\0')
    return (T_END)
  if (line[0] == '>' || line[0] == '<' || line[0] == '|')
    return (T_ERROR);
  return (T_CMD);
}
