/*
** struct.h for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/include/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Thu May  5 14:10:54 2016 Hugo SOSZYNSKI
** Last update Thu May  5 16:21:20 2016 Hugo SOSZYNSKI
*/

#ifndef			STRUCT_H_
# define		STRUCT_H_

# include		<unistd.h>

typedef struct		s_redir
{
  char			activ;
  char			a_type;
  char			*arg;
}			t_redir;

typedef struct		s_list
{
  struct s_list		*next;
  struct s_list		*pipe;
  char			**cmd;
  bool			correct;
  bool			origin;
  bool			is_bi;
}			t_list;

typedef struct		s_data
{
  char			**env;
  t_list		*list;
  t_list		*current;
  int			exec_pos;
  int			exec_return;
  unsigned char		exit_return;
  bool			exit_bool;
}			t_data;

typedef struct		s_pipe
{
  int			**fd;
  pid_t			*pid;
  int			nb_pipe;
}			t_pipe;

#endif			/* !STRUCT_H_ */
