CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LDFLAGS = -lcrypto -lssl

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/block.cpp $(SRC_DIR)/blockchain.cpp
HEADERS = $(INC_DIR)/block.h $(INC_DIR)/blockchain.h
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))

TARGET = placentium

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
