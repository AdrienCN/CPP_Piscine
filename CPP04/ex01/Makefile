SRCS = 	main.cpp \
	   	Animal.cpp \
	   	Dog.cpp \
	   	Cat.cpp \
		WrongAnimal.cpp  \
		WrongCat.cpp	\
		Brain.cpp

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME = zoo

INCLUDE = Animal.hpp \
	   	Dog.hpp \
	   	Cat.hpp \
		WrongAnimal.hpp  \
		WrongCat.hpp	\
		Brain.hpp

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
