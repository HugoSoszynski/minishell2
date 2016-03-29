##
## Makefile for minishell2 in /home/soszyn_h/rendu/PSU/PSU_2015_minishell2
## 
## Made by Hugo SOSZYNSKI
## Login   <hugo.soszynski@epitech.eu>
## 
## Started on  Tue Mar 29 16:08:49 2016 Hugo SOSZYNSKI
## Last update Tue Mar 29 17:08:47 2016 Hugo SOSZYNSKI
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wextra -Wall
#CFLAGS	+=	-Werror
CFLAGS	+=	-Iinclude
CFLAGS	+=	-ggdb3

NAME	=	mysh

SRCS	=	src/main.c \
		src/my_getenv.c \
		src/get_next_line.c \
		src/my_env_cpy.c \
		src/my_strlen.c \
		src/my_strncmp.c \
		src/my_strcpy.c \
		src/mysh.c

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
