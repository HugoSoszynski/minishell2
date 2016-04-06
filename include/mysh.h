/*
** mysh.h for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/include/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 29 16:32:45 2016 Hugo SOSZYNSKI
** Last update Wed Apr  6 17:09:35 2016 Hugo SOSZYNSKI
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

# ifndef		T_END
#  define		T_END		(6)
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
  struct s_list		next;
  struct s_list		previous;
  struct s_list		pipe;
  bool			origin;
  char			**cmd;
}			t_list;

typedef struct		s_data
{
  char			**env;
  t_btree		*head;
}			t_data;

char			**my_env_cpy(const char **env);
char			*my_getenv(char **env, const char *var);
char			*my_strcpy(char *dest, const char *src);
int			my_strlen(const char *str);
int			my_strncmp(const char *s1, const char *s2,
				   const int nb);
int			error_msg(const char *msg);
int			mysh(char **env);
void			my_free_wordtab(char **tab);
char			*my_epurstr(char *str);
int			error_null(const char *msg);

#endif			/* !MYSH_H_ */
