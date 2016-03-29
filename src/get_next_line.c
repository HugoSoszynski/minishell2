/*
** get_next_line.c for get_next_line in /home/soszyn_h/rendu/CPE/CPE_2015_getnextline
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Thu Jan 14 11:10:39 2016 Hugo SOSZYNSKI
** Last update Tue Mar 29 18:03:49 2016 Hugo SOSZYNSKI
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		<stddef.h>
#include		"get_next_line.h"

void			my_super_cat(char *buf,
				     char **line,
				     long int *count,
				     long int i)
{
  char			*tmp;
  long int		size;
  long int		k;

  if ((size = 0) == 0 && *line != NULL)
    {
      while ((*line)[size] != '\0')
	size++;
      if ((tmp = malloc((size + 1) * sizeof(char))) == NULL)
	return ;
      k = -1;
      while ((*line)[++k] != '\0')
	tmp[k] = (*line)[k];
      free(*line);
    }
  if (((*line) = malloc((size + i + 1) * sizeof(char))) == NULL)
    return ;
  k = 0;
  if (size != 0)
    while (k < size)
      (*line)[k] = tmp[(k++)];
  while (*count < i)
    (*line)[k++] = buf[(*count)++];
  (*line)[k] = '\0';
  (size != 0) ? (free(tmp)) : (tmp = NULL);
}

int			my_test_inbuf(char *buf,
				      long int *count,
				      long int *res,
				      char **line)
{
  long int		i;

  i = *count;
  while (buf[i] != '\n' && i < *res)
    i++;
  if (i > *res)
    return (1);
  my_super_cat(buf, line, count, i);
  if (*line == NULL)
    return (1);
  return (0);
}

char			*get_next_line(const int fd)
{
  static char		buf[READ_SIZE];
  static long int	count = 0;
  static long int	res;
  char			*line;

  if ((line = NULL) == NULL && count == 0)
    {
      if ((res = read(fd, buf, READ_SIZE)) <= 0)
	return (NULL);
    }
  else
    count += 1;
  if (my_test_inbuf(buf, &count, &res, &line) == 1)
    return (NULL);
  if (count < res)
    return (line);
  while ((res = read(fd, buf, READ_SIZE)) > 0)
    {
      (count >= res) ? (count = 0) : (count = count);
      if (my_test_inbuf(buf, &count, &res, &line) == 1)
	return (NULL);
      if (count < res)
	return (line);
    }
  return (NULL);
}
