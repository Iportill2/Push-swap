# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 12:28:21 by iportill          #+#    #+#              #
#    Updated: 2025/07/04 12:28:22 by iportill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# # Definir colores
# RED = \033[0;31m
# GREEN = \033[0;32m
# YELLOW = \033[0;33m
# NC = \033[0m # No color (reiniciar)

# #Comandos
# DEL			=	rm -f
# CC			=	gcc
# CCFLAGS		=	-Wall -Wextra -Werror

# # -g3 -fsanitize=address

# #Nombre ejecutable
# NAME		=	push_swap

# #Ficheros
# SRC_FILES	=	00_main 01_init_stack 02_utils_stack 03_error 04_sort_stack 05_init_a 06_move_stack_a 07_init_b 08_move_stack_b 99_push 99_rotate 99_reverse_rotate 99_sort3 99_swap
# SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
# OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
# LIBFT		=	libs/Libft
# PRINTF		=	libs/ft_printf

# #Librerias 
# LIBS		= $(PRINTF)/libftprintf.a $(LIBFT)/libft.a 

# # Header Files (dedicated and from libraries):
# HEADERS		= $(PRINTF)/ft_printf.h $(LIBFT)/libft.h $(INC)/push_swap.h

# #Directorios
# SRC_DIR = srcs/
# OBJ_DIR = objs/
# OBJF = objs
# INC = incs

# # REGLAS # 
# all:	printf libft $(NAME)

# #Compilar 
# $(NAME):$(OBJ)
# 		@$(CC) $(OBJ) $(LIBS) -o $(NAME)
# 		@echo "$(GREEN)PUSH SWAP HAS BEEN COMPILED!$(NC)"

# # Compilar objetos individualmente y crear carpeta objs
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@echo "$(YELLOW)Compiling: $<$(NC)"
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)
# 	@echo "$(YELLOW)Compiled!$(NC)"


# # $@ : The file name of the target of the rule. If the target is an archive member, then ‘$@’ is the name of the archive file.
# # $< : The name of the first prerequisite.

# #compilar librerias individuales
# libft:
# 	@echo "$(YELLOW)COMPILING LIBFT...$(NC)"
# 	@$(MAKE) -C ./$(LIBFT)
# 	@echo "$(GREEN)LIBFT HAS BEEN COMPILED$(NC)"

# printf:
# 	@echo "$(YELLOW)COMPILING FT_PRINTF...$(NC)"
# 	@$(MAKE) -C ./$(PRINTF)
# 	@echo "$(GREEN)FT_PRINTF HAS BEEN COMPILED$(NC)"

# # Eliminar tmp ft_printf
# fclean_printf:
# 	@make fclean -C ./$(PRINTF)
# 	@echo "$(RED)PRINTF FULL CLEANED!$(NC)"

# # Eliminar tmp libft
# fclean_libft:
# 	@make fclean -C ./$(LIBFT)
# 	@echo "$(RED)LIBFT FULL CLEANED!$(NC)"


# # Eliminar temporales
# clean:
# 	@$(RM) -r $(OBJ_DIR)
# 	@echo "$(RED)OBJS AND DIRECTORY CLEANED!$(NC)"

# # Eliminar temporales y ejecutable fclean_mlx
# fclean: clean  fclean_libft fclean_printf
# 	@$(RM) $(NAME)
# 	@echo "$(RED)EXECUTABLE CLEANED!$(NC)"

# re: fclean all

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
NAME		=	push_swap
LIB_NAME	=	libpush_swap.a

#Ficheros
SRC_FILES	=	00_main 01_init_stack 02_utils_stack 03_error 04_sort_stack 05_init_a 06_move_stack_a 07_init_b 08_move_stack_b 09_push 11_rotate 10_reverse_rotate 12_sort3 13_swap
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
LIBFT		=	libs/Libft
PRINTF		=	libs/ft_printf

#Librerias 
LIBS		= $(PRINTF)/libftprintf.a $(LIBFT)/libft.a 

# Header Files (dedicated and from libraries):
HEADERS		= $(PRINTF)/ft_printf.h $(LIBFT)/libft.h $(INC)/push_swap.h

#Directorios
SRC_DIR = srcs/
OBJ_DIR = objs/
OBJF = objs
INC = incs

# REGLAS # 
all: libft printf $(NAME) $(LIB_NAME)
$(LIB_NAME): libft printf $(OBJ)

#Compilar el ejecutable
$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(GREEN)PUSH SWAP HAS BEEN COMPILED!$(NC)"

#Compilar la biblioteca
$(LIB_NAME): $(OBJ)
	@ar rc $(LIB_NAME) $(OBJ) $(PRINTF)/*.o $(LIBFT)/*.o
	@ranlib $(LIB_NAME)
	@echo "$(GREEN)LIBRARY HAS BEEN COMPILED!$(NC)"

# Compilar objetos individualmente y crear carpeta objs
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)
	@echo "$(YELLOW)Compiled!$(NC)"

#compilar librerias individuales
libft:
	@echo "$(YELLOW)COMPILING LIBFT...$(NC)"
	@$(MAKE) -C ./$(LIBFT)
	@echo "$(GREEN)LIBFT HAS BEEN COMPILED$(NC)"

printf:
	@echo "$(YELLOW)COMPILING FT_PRINTF...$(NC)"
	@$(MAKE) -C ./$(PRINTF)
	@echo "$(GREEN)FT_PRINTF HAS BEEN COMPILED$(NC)"

# Eliminar temporales
clean:
	@$(RM) -r $(OBJ_DIR) $(PRINTF)/objs $(LIBFT)/objs
	@echo "$(RED)OBJS AND DIRECTORIES CLEANED!$(NC)"

clean_libft:
	@$(MAKE) -C ./$(LIBFT) fclean
	@echo "$(RED)LIBFT OBJECTS CLEANED!$(NC)"

clean_printf:
	@$(MAKE) -C ./$(PRINTF) fclean
	@echo "$(RED)FT_PRINTF OBJECTS CLEANED!$(NC)"
	
fclean: clean clean_libft clean_printf
	@$(RM) $(NAME) $(LIB_NAME)
	@echo "$(RED)EXECUTABLE AND LIBRARY CLEANED!$(NC)"


re: fclean all