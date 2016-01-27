# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:36:04 by jlepere           #+#    #+#              #
#    Updated: 2016/01/27 14:39:24 by jlepere          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CXX = gcc
NAME = fillit
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -lft

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIB_PATH = ./libft/

SRC_NAME = main.c parser.c result.c tetrim.c transform.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
INC += $(addprefix -I, $(LIB_PATH)$(INC_PATH))
LIB = $(addprefix -L, $(LIB_PATH))

all: $(LIB) $(NAME)

$(LIB):
	@$(foreach DIR, $(LIB_PATH), $(MAKE) -C $(DIR))

$(NAME): $(OBJ)
	@$(CXX) $(LIB) $(LFLAGS) $^ -o $@
	@echo "\033[32;01m===> Building \033[33;01m$@ \033[32;01mOK !\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo " # Compile $< => $@"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CXX) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31;01m===>    Clean \033[33;01m$(NAME) \033[31;01mOK !\033[0m"

fclean: clean
	@$(foreach DIR, $(LIB_PATH), $(MAKE) -C $(DIR) fclean)
	@rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC_PATH)
	norminette $(INC_PATH)
