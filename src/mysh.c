/*
** mysh.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 29 17:00:46 2016 Hugo SOSZYNSKI
** Last update Tue Mar 29 17:52:25 2016 Hugo SOSZYNSKI
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

int		mysh(char **env)
{
  char		*line;

  while ((line = my_prompt()) != NULL)
    {
      write(1, line, my_strlen(line));
      free(line);
    }
  my_free_wordtab(env);
  write(1, "exit\n", 5);
  return (SUCCESS);
}
