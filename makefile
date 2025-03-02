CXX = g++

CXXFLAGS = -std=c++11 -Wall

SRC = main.cpp block.cpp blockchain.cpp

HEADERS = block.h blockchain.h

OBJ = $(SRC:.cpp=.o)

TARGET = placentium

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
