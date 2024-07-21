# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 13:32:46 by miyazawa.ka       #+#    #+#              #
#    Updated: 2024/06/19 16:50:02 by miyazawa.ka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp File.cpp replaceSubstr.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = File.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS) $(HEADER)
	$(CXX) $(CXXFLAGS) -c $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
