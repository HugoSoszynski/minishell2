/*
** mysh.h for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/include/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 29 16:32:45 2016 Hugo SOSZYNSKI
** Last update Tue Mar 29 17:11:38 2016 Hugo SOSZYNSKI
*/

#ifndef		MYSH_H_
# define	MYSH_H_

# ifndef	SUCCESS
#  define	SUCCESS		(0)
# endif		/* !SUCCESS */

# ifndef	ERROR
#  define	ERROR		(1)
# endif		/* !ERROR */

char		**my_env_cpy(const char **env);
char		*my_getenv(char **env, const char *var);
char		*my_strcpy(char *dest, const char *src);
int		my_strlen(const char *str);
int		my_strncmp(const char *s1, const char *s2, const int nb);
int		error_msg(const char *msg);
int		mysh(char **env);
void		my_free_wordtab(char **tab);

#endif		/* !MYSH_H_ */
