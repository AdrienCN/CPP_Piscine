SRCS = 	main.cpp			\
	   	AMateria.cpp		\
	   	Ice.cpp				\
		Cure.cpp			\
		Character.cpp		\
		MateriaSource.cpp

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98

NAME = ff7

INCLUDE = 	ICharacter.hpp	\
			AMateria.hpp		\
	   		Cure.hpp		\
			Ice.hpp			\
			Character.hpp		\
			IMateriaSource.hpp	\
			MateriaSource.hpp

#$(subst cpp,hpp, $(SRCS))	

%.o:%.cpp  $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(NAME): $(OBJ)
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
