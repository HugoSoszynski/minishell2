/*
** main.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 29 16:31:36 2016 Hugo SOSZYNSKI
** Last update Tue Mar 29 16:53:41 2016 Hugo SOSZYNSKI
*/

#include	<unistd.h>
#include	"mysh.h"

int		error_msg(const char *msg)
{
  write(2, msg, my_strlen(msg));
  write(2, "\n", 1);
  return (ERROR);
}

int		main(int ac, char **av, char **env)
{
  return (0);
}
