/*
** my_strcmp.c for my_strcmp in /home/soszyn_h/rendu/Piscine_C_J06
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Oct  5 14:59:38 2015 Hugo SOSZYNSKI
** Last update Tue May  3 15:22:39 2016 Hugo SOSZYNSKI
*/

#include	"mysh.h"

int		my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] - s2[i] != 0)
	return (1);
      i++;
    }
  return (0);
}
