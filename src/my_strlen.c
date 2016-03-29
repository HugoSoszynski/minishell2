/*
** my_strlen.c for my_strlen in /home/soszyn_h/rendu/Piscine_C_J04
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Thu Oct  1 11:45:58 2015 Hugo SOSZYNSKI
** Last update Tue Mar 29 16:42:16 2016 Hugo SOSZYNSKI
*/

#include	<unistd.h>
#include	<limits.h>

int		my_strlen(const char *str)
{
  int		cpt;

  cpt = 0;
  while (str[cpt] != '\0')
    {
      if (cpt == INT_MAX)
	{
	  write(2, "Error: my_strlen: string is to long (int overflow)\n", 51);
	  return (-1);
	}
      cpt++;
    }
  return (cpt);
}
