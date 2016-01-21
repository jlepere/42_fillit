.PHONY: all clean fclean re

CXX = gcc

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/

OBJ_PATH = ./obj/

INC_PATH = ./includes/

LIB_PATH = ./libft/

SRC_NAME = main.c parser.c tetrim.c result.c transform.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB_NAME = -lft

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
LIB = $(addprefix -L, $(LIB_PATH))

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME) $(LIB) $(LIB_NAME)

$(LIB):
	cd $(LIB_PATH) && $(MAKE)
	cp $(LIB_PATH)includes/libft.h $(INC_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CXX) $(FLAGS) $(INC) -c $< -o $@

clean:
	cd $(LIB_PATH) && $(MAKE) clean
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	cd $(LIB_PATH) && $(MAKE) fclean
	rm -fv $(INC_PATH)libft.h
	rm -fv $(NAME)

re: fclean all
