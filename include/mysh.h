/*
** mysh.h for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/include/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 29 16:32:45 2016 Hugo SOSZYNSKI
** Last update Tue May  3 15:25:10 2016 Hugo SOSZYNSKI
*/

#ifndef			MYSH_H_
# define		MYSH_H_

#include		<stdbool.h>

# ifndef		SUCCESS
#  define		SUCCESS		(0)
# endif			/* !SUCCESS */

# ifndef		ERROR
#  define		ERROR		(1)
# endif			/* !ERROR */

# ifndef		T_CMD
#  define		T_CMD		(0)
# endif			/* !T_CMD */

# ifndef		T_SCOL
#  define		T_SCOL		(1)
# endif			/* !T_SCOL */

# ifndef		T_PIPE
#  define		T_PIPE		(2)
# endif			/* !T_PIPE */

# ifndef		T_RREDIR
#  define		T_RREDIR	(3)
# endif			/* !T_RREDIR */

# ifndef		T_REDIRL
#  define		T_REDIRL	(4)
# endif			/* !T_REDIRL */

# ifndef		T_DREDIRL
#  define		T_DREDIRL	(5)
# endif			/* !T_DREDIRL */

# ifndef		T_NULL
#  define		T_NULL		(6)
# endif			/* !T_END */

# ifndef		T_FILE
#  define		T_FILE		(7)
# endif			/* !T_FILE */

# ifndef		T_STRING
#  define		T_STRING	(8)
# endif			/* !T_STRING */

# ifndef		T_ARG
#  define		T_ARG		(9)
# endif			/* !T_STRING */

# ifndef		T_LINE
#  define		T_LINE		(10)
# endif			/* !T_LINE */

# ifndef		T_ERROR
#  define		T_ERROR		(-1)
# endif			/* !T_ERROR */

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

char			**my_env_cpy(const char **env);
char			*my_getenv(char **env, const char *var);
char			*my_strcpy(char *dest, const char *src);
int			my_strlen(const char *str);
int			my_strncmp(const char *s1, const char *s2,
				   const int nb);
int			error_msg(const char *msg);
int			mysh(t_data *exec);
int			script(t_data *exec);
void			my_free_wordtab(char **tab);
char			*my_epurstr(char *str);
void			*error_null(const char *msg);
int			find_next_state(char *line,
					int *cpt, int state);
char			*my_arg_dup(const char *line);
void			init_cmd_node(t_list *current);
void			init_cmd_node(t_list *current);
int			state_cmd(char *line, int *cpt,
				  t_list *current);
int			state_error(char *line, int *cpt,
				    t_list *current);
int			state_line(char *line, int *cpt);
int			state_pipe(char *line, int *cpt,
				   t_list *current);
int			state_semicol(char *line, int *cpt);
t_list			*my_smachine(char **line);
char			**add_to_wordtab(char **src, char *arg);
void			my_free_list(t_list *list);
void			my_start_exec(t_data *exec);
int			test_path(t_data *exec);
char			*my_path_dup(const char *line,
				     char *cmd, int cmd_len);
int			error_mult(const char *msg, const char *part,
				   const char *end);
char			*my_path_dup(const char *line,
				     char *cmd, int cmd_len);
int			test_path(t_data *exec);
void			exec_cmd(t_data *exec);
void			init_data(t_data *exec);
int			is_built_in(t_list *current);
void			exec_built_in(t_data *exec, t_list *current, int fd);
void			my_exit(t_data *exec, t_list *current);
void			my_env(t_data *exec, int fd);
int			my_strcmp(const char *s1, const char *s2);
int			my_getnbr(char *str);

#endif			/* !MYSH_H_ */
