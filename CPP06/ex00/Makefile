SRCS = 	main.cpp		\
		Bureaucrat.cpp	\
		Form.cpp		\
		ShrubberyCreationForm.cpp	\
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address -std=c++98

NAME = Vog_world

INCLUDE = Bureaucrat.hpp \
		  Form.hpp	\
		  ShrubberyCreationForm.hpp \
		  RobotomyRequestform.hpp \
		  PresidentialPardonForm.hpp \
		  Intern.hpp

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
