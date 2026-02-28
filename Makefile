#Makefile Anatomy
CXX      := g++
CXXFLAGS := -g -std=c++17 -Werror -Wall

TARGET   := taskmanager
SRCS     := main.cpp App.cpp Task.cpp TaskManager.cpp
OBJS     := $(SRCS:.cpp=.o)

#Makefile Rules
all: $(TARGET)
	@echo "Files are compiled!"

$(TARGET): $(OBJS)
	@echo "Linking files..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	@echo "Compiling $@..."
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: $(TARGET)
	@echo "Running program..."
	./$(TARGET)

clean: 
	@echo "Cleaning up..."
	@rm -f $(OBJS) $(TARGET)
	@echo "Clean up complete!"
