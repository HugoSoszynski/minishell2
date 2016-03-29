/*
** my_getenv.c for wolf3d in /home/soszyn_h/rendu/Infographie/gfx_wolf3d
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Dec 30 15:30:36 2015 Hugo SOSZYNSKI
** Last update Tue Mar 29 16:41:00 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	"mysh.h"

char		*my_getenv(char **env, const char *var)
{
  int		var_len;
  int		count;
  int		i;

  count = 0;
  var_len = my_strlen(var);
  while (env[count] != NULL && my_strncmp(env[count], var, var_len) != 0)
    count++;
  if (env[count] == NULL)
    return (NULL);
  i = 0;
  while (env[count][i] != '\0' && env[count][i] != '=')
    i++;
  i++;
  if (env[count][i] == '\0')
    return (NULL);
  return (&(env[count][i]));
}
