SRCS = main.cpp \
	   ClapTrap.cpp \
	   FragTrap.cpp \
	   ScavTrap.cpp \
	   DiamondTrap.cpp

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME = a.out

INCLUDE = ClapTrap.hpp \
		  FragTrap.hpp \
		  ScavTrap.hpp \
		  DiamondTrap.hpp

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(INCLUDE)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
