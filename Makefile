# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obaranni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/27 15:44:29 by obaranni          #+#    #+#              #
#    Updated: 2018/08/01 19:56:21 by obaranni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

SRC_DIR = ./src/

OBJ_DIR = ./obj/

OBJ_DIRS = $(addprefix $(OBJ_DIR)$(shell cd src ; find . -maxdepth 25 -type d | grep ./ ; cd ..))

INC_DIR = ./headers/

LIB_DIR = ./libft/

LIBFT = $(LIB_DIR)libft.a

SRC = $(shell cd src ; find . ; cd ..)

OBJ = $(SRC:.c=.o)

SRC_FILES =	$(addprefix $(SRC_DIR),$(SRC))

OBJ_FILES =	$(addprefix $(OBJ_DIR),$(OBJ))

COMPALING_FLAGS = -I$(INC_DIR) -I$(LIB_DIR)# `pkg-config --cflags gtk+-3.0`

LINKING_FLAGS = -framework opengl -framework appkit -lft -L$(LIB_DIR)# `pkg-config --libs --cflags gtk+-3.0`

CC = gcc

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
#	$(CC) $(LINKING_FLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(COMPALING_FLAGS) -o $@ -c $<

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	mkdir $(OBJ_DIRS)

$(LIBFT):
	make -C $(LIB_DIR)


clean:
	rm -rf $(OBJ_FILES)
	make clean -C $(LIB_DIR)


fclean: clean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all
