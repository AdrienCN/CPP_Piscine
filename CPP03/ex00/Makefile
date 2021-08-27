SRCS = main.cpp \
	   ClapTrap.cpp

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME = a.out

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
