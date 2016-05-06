##
## Makefile for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2
## 
## Made by Hugo SOSZYNSKI
## Login   <hugo.soszynski@epitech.eu>
## 
## Started on  Tue Mar 29 16:08:49 2016 Hugo SOSZYNSKI
## Last update Fri May  6 14:14:18 2016 Hugo SOSZYNSKI
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wextra -Wall
CFLAGS	+=	-Werror
CFLAGS	+=	-Iinclude
#CFLAGS	+=	-ggdb3

NAME	=	mysh

SRCS	=	src/main.c \
		src/my_getenv.c \
		src/get_next_line.c \
		src/my_env_cpy.c \
		src/my_strlen.c \
		src/my_strncmp.c \
		src/my_strcmp.c \
		src/my_strcpy.c \
		src/my_free_list.c \
		src/my_getnbr.c \
		src/mysh.c \
		src/parsing/my_epurstr.c \
		src/parsing/find_next_state.c \
		src/parsing/my_arg_dup.c \
		src/parsing/start_smachine.c \
		src/parsing/state_cmd.c \
		src/parsing/state_error.c \
		src/parsing/state_line.c \
		src/parsing/state_pipe.c \
		src/parsing/state_semicol.c \
		src/parsing/word_tab_utils.c \
		src/exec/my_start_exec.c \
		src/exec/cmd_path.c \
		src/exec/my_path_dup.c \
		src/exec/exec_cmd.c \
		src/init_struct.c \
		src/exec/built_in.c \
		src/exec/env_and_exit.c \
		src/exec/unsetenv.c \
		src/exec/setenv.c \
		src/exec/pipe.c \
		src/exec/my_cd.c

OBJS	=	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) -Iinclude

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
