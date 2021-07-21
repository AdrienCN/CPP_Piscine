SRCS = main.cpp \
	   Zombie.cpp \
	   randomChump.cpp \
	   newZombie.cpp 

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

INCLUDE = Zombie.hpp

%.o:%.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

NAME = graveyard

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) $(OBJ) -o $(NAME)

all : $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean  all
