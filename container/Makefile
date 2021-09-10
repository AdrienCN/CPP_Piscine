#Makefile that compiles all the files in the directory using clang++ and generates and executable

CC = clang++
SRC_FILES = main.cpp main_ft.cpp main_stl.cpp 
HEAD_FILES = Iterators.hpp Lexicographic.hpp Map.hpp Meta.hpp Stack.hpp Vector.hpp main.hpp utils.hpp test.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
EXE_FILE = ft_containers.ft
EXE_FILE_STL = ft_containers.stl
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g


all: $(EXE_FILE)

$(EXE_FILE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(CXXFLAGS) $(OBJ_FILES) -o $(EXE_FILE)
	cp $(EXE_FILE) $(EXE_FILE_STL)

#compiles obj files one by one
$(OBJ_FILES): %.o: %.cpp $(HEAD_FILES)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@
#phony and clean rules

clean:
	rm -f $(EXE_FILE) $(OBJ_FILES) $(EXE_FILE_STL)
	rm -f *.o

#re rule
re: clean all

#phony rule

#rule that prints all the variables
.PHONY: print-vars
print-vars:
	@echo "CC = $(CC)"
	@echo "SRC_FILES = $(SRC_FILES)"
	@echo "OBJ_FILES = $(OBJ_FILES)"
	@echo "EXE_FILE = $(EXE_FILE)"
	@echo "CXXFLAGS = $(CXXFLAGS)"

.PHONY: all clean
