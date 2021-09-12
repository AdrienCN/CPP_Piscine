SRCS = 	main.cpp	\
		mutantstack.cpp

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address 

NAME = Mutant

INCLUDE = mutantstack.hpp

#$(subst cpp,hpp, $(SRCS))	

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(NAME): $(OBJ) $(INCLUDE)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

echo :
	@echo $(SRCS)
	@echo $(INCLUDE)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
