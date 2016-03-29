/*
** my_strncmp.c for my_strncmp in /home/soszyn_h/rendu/Piscine_C_J06
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Oct  5 16:20:44 2015 Hugo SOSZYNSKI
** Last update Tue Mar 29 16:42:40 2016 Hugo SOSZYNSKI
*/

int	my_strncmp(const char *s1, const char *s2, const int nb)
{
  int	i;

  i = 0;
  while (i < nb && (s1[i] != 0 && s2[i] != 0))
    {
      if (s1[i] - s2[i] != 0)
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
