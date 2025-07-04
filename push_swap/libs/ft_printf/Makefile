# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 12:30:00 by iportill          #+#    #+#              #
#    Updated: 2025/07/04 13:14:30 by iportill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Comandos
AR			=	ar rcs
DEL			=	rm -f
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror

#Nombre ejecutable
NAME		=	libftprintf.a

#Ficheros
SRC			=	ft_printf.c
OBJ			=	$(SRC:.c=.o)

# REGLAS #
all:	$(NAME)

$(NAME): $(SRC)
	@$(CC) $(CCFLAGS) -c $(SRC)
	@$(AR) $(NAME) $(OBJ)
	@echo "libftprintf compiled!"

clean:
	$(DEL) $(OBJ)
	@echo "Objects cleaned!"

fclean: clean
	$(DEL) $(NAME)
	@echo "Objects and librarie cleaned!"

re: fclean all

.PHONY: all clean fclean re
