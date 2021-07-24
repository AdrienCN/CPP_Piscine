SRCS = main.cpp \
	   Karen.cpp \

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

NAME = karenFilter

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean  all
