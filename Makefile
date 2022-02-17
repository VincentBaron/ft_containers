# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 13:38:45 by vbaron            #+#    #+#              #
#    Updated: 2022/02/16 16:41:25 by vincentbaro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_S = srcs/
DIR_O = objs

SOURCES = 	main.cpp \
			test_unit.cpp \


SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJ = $(addprefix $(DIR_O)/,$(SOURCES:.cpp=.o))
OBJS := $(filter-out objs/test_unit.o, $(OBJ))
OBJS_TEST := $(filter-out objs/main.o, $(OBJ))
HEADERS = headers

NAME = containers
NAME_TEST = unit-test

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -Wno-unused #-fsanitize=address

all: $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.cpp
	mkdir -p $(DIR_O)	
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

unit-test: $(NAME_TEST)

$(DIR_O)/%.o: $(DIR_S)/%.cpp
	mkdir -p $(DIR_O)	
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME_TEST): $(OBJS_TEST)
		$(CC) $(CFLAGS) $^ -o $@

clean:
		rm -f $(OBJS)		
	rm -f $(OBJS)/*.o
	rm -rf $(DIR_O)	

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_TEST)

re: fclean all

.PHONY: re fclean all clean