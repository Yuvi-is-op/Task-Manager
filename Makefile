#Makefile Anatomy
CXX      := g++
CXXFLAGS := -g -std=c++17 -Werror -Wall

BUILDDIR    := build/
TARGET   := taskmanager
SRCS     := main.cpp App.cpp Task.cpp TaskManager.cpp
OBJS     := $(addprefix $(BUILDDIR), $(SRCS:.cpp=.o))

#Makefile Rules
all: $(TARGET)
	@echo "Files are compiled!"

$(TARGET): $(OBJS)
	@echo "Linking files..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(BUILDDIR)%.o: %.cpp
	@mkdir -p $(BUILDDIR)
	@echo "Compiling $@.cpp..."
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: $(TARGET)
	@echo "Running program..."
	./$(TARGET)

clean: 
	@echo "Cleaning up..."
	@rm -rf $(BUILDDIR) $(TARGET)
	@echo "Clean up complete!"
