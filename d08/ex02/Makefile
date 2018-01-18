#* ************************************************************************** */
#*                                                                            */
#*    Makefile               _             _              :::      ::::::::   */
#*    By: mlu               | |           | |           :+:      :+:    :+:   */
#*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
#*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +#+  +:+       +#+        */
#*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +#+#+#+#+#+   +#+           */
#*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        #+#    #+#             */
#*          __/ | __/ | |                             ###   ########.fr       */
#*         |___/ |___/|_|                                                     */
#* ************************************************************************** */

#* I'm bad at makefiles, but I'm good at grilling eggplants

NAME	= mutatedabomination

SRC		= main.cpp mutantstack.cpp

CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME):
	clang++ $(CFLAG) $(SRC) -I . -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created mutatedabomination"

clean:
	/bin/rm -f *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned mutatedabomination"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned mutatedabomination"

re: fclean all

.PHONY: clean fclean re all test
