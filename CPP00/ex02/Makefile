SRCS = Account.cpp \
	   tests.cpp

OBJ = $(SRCS:.cpp=.o)

NAME = bank

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

INCLUDE = Account.hpp


%.o:%.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) $(OBJ) -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
