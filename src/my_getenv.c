/*
** my_getenv.c for wolf3d in /home/soszyn_h/rendu/Infographie/gfx_wolf3d
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Dec 30 15:30:36 2015 Hugo SOSZYNSKI
** Last update Mon Apr 11 15:16:39 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"mysh.h"

static char	*get_var(const char *var)
{
  char		*var_cpy;
  int		var_len;
  int		cpt;

  var_len = my_strlen(var);
  if ((var_cpy = malloc((var_len + 2) * sizeof(char))) == NULL)
    return (NULL);
  cpt = -1;
  while (++cpt < var_len)
    var_cpy[cpt] = var[cpt];
  var_cpy[var_len] = '=';
  var_cpy[var_len + 1] = '\0';
  return (var_cpy);
}

char		*my_getenv(char **env, const char *var)
{
  int		var_len;
  int		count;
  int		i;
  char		*var_cpy;

  count = 0;
  if ((var_cpy = get_var(var)) == NULL)
    return (NULL);
  var_len = my_strlen(var_cpy);
  while (env[count] != NULL && my_strncmp(env[count], var_cpy, var_len) != 0)
    count++;
  free(var_cpy);
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
