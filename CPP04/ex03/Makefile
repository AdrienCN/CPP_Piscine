SRCS = 	main.cpp			\
	   	AMateria.cpp		\
	   	Ice.cpp				\
		Cure.cpp			\
	   	ICharacter.cpp		\
	#	Character.cpp		\
		IMateriaSource.cpp	\
		MateriaSource.cpp

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98

NAME = ff7

INCLUDE = $(subst cpp,hpp, $(SRCS))	

#		main.hpp			\
	   	AMateria.hpp		\
	   	Materia.hpp			\
	   	ICharacter.hpp		\
		Character.hpp		\
		IMateriaSource.hpp	\
		MateriaSource.hpp

%.o:%.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(NAME): $(OBJ) $(INCLUDE)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

echo :
	@echo $(SRCS)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
