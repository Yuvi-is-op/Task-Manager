#Makefile Anatomy
CXX      := g++
CXXFLAGS := -g -std=c++17 -Werror -Wall

TARGET   := taskmanager
SRCS     := main.cpp App.cpp Task.cpp TaskManager.cpp

#Makefile Rules
all: $(SRCS)
	@echo "Compiling files..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	@echo "Files are compiled!"

run: $(TARGET)
	@echo "Running program..."
	./$(TARGET)


