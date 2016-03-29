/*
** my_strcpy.c for my_strcpy in /home/soszyn_h/rendu/Piscine_C_J06
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Oct  5 09:36:05 2015 Hugo SOSZYNSKI
** Last update Tue Mar 29 16:41:11 2016 Hugo SOSZYNSKI
*/

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
