# a modified generic makefile I found on the internet

# definer compiler and output name
CXX    := g++
OUTPUT := program

# compiler and linker flags
CXX_FLAGS := -std=c++20
INCLUDES  := -I./inc
LDFLAGS   := -lm

# the source files 
SRC_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(SRC_FILES:.cpp=.o)

# all of these targets will be made if you just type make
all: $(OUTPUT)

# define the main executable
$(OUTPUT): $(OBJ_FILES) Makefile
	$(CXX) $(OBJ_FILES) $(LDFLAGS) -o ./bin/$@

# specifies how the object files are compiled from cpp files
.cpp.o:
	$(CXX) -c $(CXX_FLAGS) $(INCLUDES) $< -o $@

# typing 'make clean' will remove build files and output executable
clean:
	rm -f $(OBJ_FILES) ./bin/$(OUTPUT)

# typing 'make run' will compile and run the executable
run: $(OUTPUT)
	cd bin && ./$(OUTPUT) && cd ..
