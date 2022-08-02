# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 09:57:24 by agirardi          #+#    #+#              #
#    Updated: 2022/06/29 16:23:35 by agirardi         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		:=	megaphone

OBJ_PATH	:=	.objects

LST_SRCS	:=	megaphone.cpp \

LST_OBJS	:=	$(LST_SRCS:.cpp=.o)

CC			:=	c++

CFLAGS		:=	-Wall -Wextra -Werror -std=c++98

RM			:=	rm -rf

ERASE		:=	\033[2K\r
BOLD		:=	\033[1m
redir		:=	\033[31m
GREEN		:=	\033[32m
BLUE		:=	\033[34m
PINK		:=	\033[35m
BOLD		:=	\033[1m
END			:=	\033[0m

OBJS		:=	$(addprefix $(OBJ_PATH)/,$(LST_OBJS))

all : ${NAME}

.SILENT:

$(OBJ_PATH)/%.o: %.cpp Makefile | $(OBJ_PATH)
	${CC} ${CFLAGS} -c $< -o $@
	printf "$(BLUE)> Compiling :$(END) $<\n"

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

${NAME}: ${OBJS}
	printf "$(GREEN)> All the .cpp files from so_long have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	${CC} ${OBJS} -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"


clean:
	${RM} ${OBJ_PATH}
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	${RM} ${NAME}
	printf "$(GREEN)> all executable files have been removed successfully !$(END)\n"

re: fclean all

.PHONY: all clean fclean re
