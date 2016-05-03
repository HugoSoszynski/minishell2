/*
** init_struct.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Apr 13 15:49:40 2016 Hugo SOSZYNSKI
** Last update Tue May  3 11:25:05 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	"mysh.h"

void		init_data(t_data *exec)
{
  exec->env = NULL;
  exec->list = NULL;
  exec->current = NULL;
  exec->exec_pos = 0;
  exec->exec_return = SUCCESS;
  exec->exit_return = 0;
  exec->exit_bool = false;
}
