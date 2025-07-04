# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 12:23:47 by iportill          #+#    #+#              #
#    Updated: 2025/07/04 12:23:50 by iportill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Definir colores
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m # No color (reiniciar)

#Comandos
DEL			=	rm -f
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror

#Nombre ejecutable y biblioteca
NAME		=	checker

#Ficheros
SRC_FILES	=	main
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
GNL			=	libs/get_next_line
PUSH_SWAP	=	../push_swap

#Librerias 
LIBS		= $(GNL)/get_next_line.a $(PUSH_SWAP)/libpush_swap.a

# Header Files (dedicated and from libraries):
HEADERS		= $(GNL)/get_next_line.h $(INC)/checker.h $(PUSH_SWAP)/incs/push_swap.h

#Directorios
SRC_DIR = srcs/
OBJ_DIR = objs/
OBJF = objs
INC = incs

# REGLAS # 
all: gnl push_swap $(NAME) 

#Compilar el ejecutable
$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(GREEN)PUSH SWAP HAS BEEN COMPILED!$(NC)"

# Compilar objetos individualmente y crear carpeta objs
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CCFLAGS) -I$(INC) -I$(GNL) -I$(PUSH_SWAP)/incs -o $@ -c $<
	@echo "$(YELLOW)Compiled!$(NC)"

#compilar librerias individuales
gnl:
	@echo "$(YELLOW)COMPILING GNL...$(NC)"
	@$(MAKE) -C ./$(GNL)
	@echo "$(GREEN)GNL HAS BEEN COMPILED$(NC)"

push_swap:
	@echo "$(YELLOW)COMPILING PUSH...$(NC)"
	@$(MAKE) -C ./$(PUSH_SWAP)
	@echo "$(GREEN)PUSH_SWAP HAS BEEN COMPILED$(NC)"

# Eliminar temporales
clean:
	@$(RM) -r $(OBJ_DIR) $(GNL)/*.o
	@echo "$(RED)OBJS AND DIRECTORIES CLEANED!$(NC)"

clean_gnl:
	@$(MAKE) -C ./$(GNL) fclean
	@echo "$(RED)GNL OBJECTS CLEANED!$(NC)"

fclean: clean clean_gnl
	@$(RM) $(NAME)
	@echo "$(RED)EXECUTABLE AND LIBRARY CLEANED!$(NC)"

re: fclean all