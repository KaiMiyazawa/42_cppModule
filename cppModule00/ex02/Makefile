# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 16:43:35 by miyazawa.ka       #+#    #+#              #
#    Updated: 2024/06/19 13:32:27 by miyazawa.ka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Account.hpp

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
