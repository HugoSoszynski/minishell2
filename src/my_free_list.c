/*
** my_free_list.c for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/src/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sat Apr  9 18:26:18 2016 Hugo SOSZYNSKI
** Last update Sat Apr  9 18:43:09 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"mysh.h"

static void	my_free_pipe(t_list *list)
{
  my_free_wordtab(list->cmd);
  if (list->pipe != NULL)
    my_free_pipe(list->pipe);
  free(list);
}

void		my_free_list(t_list *list)
{
  t_list	*tmp;
  while (list != NULL)
    {
      tmp = list->next;
      my_free_wordtab(list->cmd);
      if (list->pipe != NULL)
	my_free_pipe(list->pipe);
      free(list);
      list = tmp;
    }
}
