/*
** my_getnbr.c for my_getnbr in /home/soszyn_h/Desktop/RE_LIB
**
** Made by Hugo SOSZYNSKI
** Login   <soszyn_h@epitech.net>
**
** Started on  Thu Oct 15 10:00:18 2015 Hugo SOSZYNSKI
** Last update Tue Nov 10 16:40:53 2015 Hugo SOSZYNSKI
*/

int	my_getnbr(char *str)
{
  int	nb;
  int	test;
  int	multi;

  multi = 1;
  nb = 0;
  test = 0;
  while (*str != '\0' && test == 0)
    {
      if (*str <= '9' && *str >= '0')
	nb = nb * 10 + (*str - 48);
      else if (nb == 0 && *str == '-')
	multi = multi * -1;
      else if (nb != 0)
	test = 1;
      str++;
    }
  return (nb * multi);
}
