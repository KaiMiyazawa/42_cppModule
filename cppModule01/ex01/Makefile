# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 13:32:46 by miyazawa.ka       #+#    #+#              #
#    Updated: 2024/06/19 14:08:53 by miyazawa.ka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
#CFLAGS += -g -fsanitize=address
RM = rm -rf

SRC = main.cpp Zombie.cpp zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Zombie.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
