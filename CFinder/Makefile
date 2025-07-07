CC = gcc
CXX = g++
CFLAGS = -Wall -I./src
CXXFLAGS = -Wall -std=c++17 -I./src

SRC_C = src/main.c
SRC_CPP = src/search.cpp src/utils.cpp
OBJ_C = $(SRC_C:.c=.o)
OBJ_CPP = $(SRC_CPP:.cpp=.o)

TARGET = cfinder

all: $(TARGET)

$(OBJ_C): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CPP): %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ_C) $(OBJ_CPP)
	$(CXX) -o $@ $^

clean:
	rm -f $(OBJ_C) $(OBJ_CPP) $(TARGET)
