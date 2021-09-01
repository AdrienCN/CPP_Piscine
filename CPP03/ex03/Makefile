SRCS = main.cpp \
	   ClapTrap.cpp \
	   FragTrap.cpp \
	   ScavTrap.cpp \
	   DiamondTrap.cpp

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98

NAME = a.out

INCLUDE = ClapTrap.hpp \
		  FragTrap.hpp \
		  ScavTrap.hpp \
		  DiamondTrap.hpp

%.o:%.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(INCLUDE)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
