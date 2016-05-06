/*
** mysh.h for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2/include/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 29 16:32:45 2016 Hugo SOSZYNSKI
** Last update Fri May  6 14:13:25 2016 Hugo SOSZYNSKI
*/

#ifndef			MYSH_H_
# define		MYSH_H_

# include		<stdbool.h>
# include		"define.h"
# include		"struct.h"

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
void			my_unsetenv(t_data *exec, t_list *current);
int			var_pos(char **env, char *var);
void			my_setenv(t_data *exec, t_list *current, int fd);
char			**add_env_var(char **env,
				      const char *var, const char *value);
void			change_env_var(char **env, int pos,
				       const char *var, const char *value);
void			exec_pipe(t_data *exec);
void			my_cd(t_data *exec, t_list *current);

#endif			/* !MYSH_H_ */
