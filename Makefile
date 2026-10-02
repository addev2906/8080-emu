CXX := g++
CXXFLAGS := -Wall -std=c++17
LDFLAGS := -lSDL3

TARGET := 8080
SRCS := main.cpp 8080.cpp Platform.cpp SpaceInvadersMachine.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET) $(ROM)

clean:
	rm -f $(TARGET)
