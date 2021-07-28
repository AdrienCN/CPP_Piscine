SRCS = $(wildcard *.cpp)

OBJ = $(SRCS:.cpp=.o)

NAME = phonebook

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

INCLUDE = phonebook.h 

%.o:%.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) $(OBJ) -o $@

all : $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
