# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 12:23:41 by iportill          #+#    #+#              #
#    Updated: 2025/07/04 12:23:42 by iportill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#Comandos
AR			=	ar rcs
DEL			=	rm -f
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror

#Nombre ejecutable
NAME		=	get_next_line.a

#Ficheros
SRC			=	get_next_line.c get_next_line_utils.c
OBJ			=	$(SRC:.c=.o)

# REGLAS #
all:	$(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "GNL library compiled!"

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(DEL) $(OBJ)

fclean: clean
	$(DEL) $(NAME)

re: fclean all

.PHONY: all clean fclean re
