# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirardi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 09:57:24 by agirardi          #+#    #+#              #
#    Updated: 2022/07/10 02:07:27 by agirardi         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		:=	phonebook

INC_PATH	:=	includes
SRC_PATH	:=	srcs
OBJ_PATH	:=	.bin

LST_INCS	:=	main.hpp \
				Phonebook.hpp \
				Contact.hpp

LST_SRCS	:=	main.cpp \
				Phonebook.cpp \
				Contact.cpp

LST_OBJS	:=	$(LST_SRCS:.cpp=.o)

CC			:=	c++

CFLAGS	:=	-Wall -Wextra -Werror -std=c++98

RM			:=	rm -rf

ERASE		:=	\033[2K\r
BOLD		:=	\033[1m
redir		:=	\033[31m
GREEN		:=	\033[32m
BLUE		:=	\033[34m
PINK		:=	\033[35m
BOLD		:=	\033[1m
END			:=	\033[0m

INCS		:=	$(addprefix $(INC_PATH)/,$(LST_INCS))
SRCS		:=	$(addprefix $(SRC_PATH)/,$(LST_SRCS))
OBJS		:=	$(addprefix $(OBJ_PATH)/,$(LST_OBJS))

all : ${NAME}

.SILENT:

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(INCS) Makefile | $(OBJ_PATH)
	${CC} ${CFLAGS} -I $(INC_PATH) -c $< -o $@
	printf "$(BLUE)> Compiling :$(END) $<\n"

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

${NAME}: ${OBJS}
	printf "$(GREEN)> All the .cpp files from so_long have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	${CC} ${CFLAGS} ${OBJS} -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"


clean:
	${RM} ${OBJ_PATH}
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	${RM} ${NAME}
	printf "$(GREEN)> all executable files have been removed successfully !$(END)\n"

re: fclean all

.PHONY: all clean fclean re
