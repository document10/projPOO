# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -lm

# Target executable
TARGET = main

# Source files
SRCS = main.cpp $(wildcard include/*.cpp) $(wildcard include/componente/*.cpp) $(wildcard include/periferice/*.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)\

# Clean rule to remove generated files
clean:
	rm -rf $(OBJS)

