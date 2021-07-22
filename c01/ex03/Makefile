SRCS = main.cpp \
	   Weapon.cpp \
	   HumanA.cpp \
	   HumanB.cpp 

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

INCLUDE = Weapon.hpp \
		  HumanA.hpp \
#		  HumanB.hpp

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

NAME = smash_smash

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean  all
