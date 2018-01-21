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

# Original creator Mikim (from rush00), using the makefile he made together for
# rush00 since it's so much nicer and convenient compared to my normal makefile
# Mikim gave me permission to keep his header structure and use for this rush
# Visit his awesome github here https://github.com/mikim42

SRC = main.cpp TextDisplay.cpp ImageDisplay.cpp

SRC_CLASS = HostNameModule.cpp OSInfoModule.cpp DateTimeModule.cpp \
			CPUInfoModule.cpp CPUUsageModule.cpp \
			RAMUsageModule.cpp NetworkInfoModule.cpp \
			TerminalDisplay.cpp GraphicDisplay.cpp \
			IMonitorModule.cpp IMonitorDisplay.cpp \
			PonyModule.cpp

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

LIBS = -lncurses -framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML/Frameworks
HEADER = -I includes -I ./SFML/include

SFML = DYLD_FRAMEWORK_PATH="$(PWD)/SFML/Frameworks"

CC = clang++
CFLAG = -c
WFLAG = -Wall -Wextra -Werror

NAME = ft_gkrellm

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAG) $(WFLAG) $(HEADER) $< -o $@

$(OBJDIR_CLASS)%.o: $(SRCDIR_CLASS)%.cpp
	@mkdir -p $(OBJDIR_CLASS)
	@$(CC) $(CFLAG) $(WFLAG) $(HEADER) $< -o $@

$(NAME): $(OBJS) $(OBJS_CLASS)
	@$(CC) $(OBJS) $(OBJS_CLASS) $(HEADER) $(LIBS) -o $@
	@echo "\x1b[32;1m[ft_gkrellm created]\x1b[0m"

sfml:
	@echo export $(SFML)

clean:
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -rf $(OBJDIR_CLASS)
	@echo "\x1b[35;1m[ft_gkrellm cleaned]\x1b[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\x1b[31m[ft_gkrellm fcleaned]\x1b[0m"

re: fclean all