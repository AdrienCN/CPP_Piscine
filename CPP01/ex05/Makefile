SRCS = main.cpp \
	   Karen.cpp \

OBJ = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

NAME = manager

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean  all
