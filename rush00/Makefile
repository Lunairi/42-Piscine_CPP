# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 22:56:20 by mikim             #+#    #+#              #
#    Updated: 2018/01/13 23:43:02 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp

SRC_CLASS = Alien.class.cpp \
		Bullet.class.cpp \
		Enemy.class.cpp \
		Player.class.cpp \
		Game.class.cpp \
		Elite.class.cpp \
		Timer.class.cpp

OBJ = $(SRC:.cpp=.o)
OBJ_CLASS = $(SRC_CLASS:.cpp=.o)

SRCDIR = srcs/
OBJDIR = objs/
SRCDIR_CLASS = class/
OBJDIR_CLASS = objs_class/

SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJS = $(addprefix $(OBJDIR), $(OBJ))
SRCS_CLASS = $(addprefix $(SRCDIR_CLASS), $(SRC_CLASS))
OBJS_CLASS = $(addprefix $(OBJDIR_CLASS), $(OBJ_CLASS))

LIBS = -lncurses
HEADER = -I includes

CC = g++
CFLAG = -c
WFLAG = -Wall -Wextra -Werror

NAME = ft_retro

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAG) $(HEADER) $< -o $@

$(OBJDIR_CLASS)%.o: $(SRCDIR_CLASS)%.cpp
	@mkdir -p $(OBJDIR_CLASS)
	@$(CC) $(CFLAG) $(HEADER) $< -o $@

$(NAME): $(OBJS) $(OBJS_CLASS)
	@$(CC) $(OBJS) $(OBJS_CLASS) $(HEADER) $(LIBS) -o $@
	@echo "\x1b[32;1m[space.invaders - 모래반지 빵야빵야!]\x1b[0m"

clean:
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -rf $(OBJDIR_CLASS)
	@echo "\x1b[35;1m[space.invaders - 모래반지 빵야빵야!]\x1b[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\x1b[31m[space.invaders - 모래반지 빵야빵야!]\x1b[0m"

re: fclean all
