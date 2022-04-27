EXECUTABLE=project.exe
SOURCE_FILES=$(wildcard *.cpp)
OBJ_FILES=$(patsubst %.cpp, %.o, $(SOURCE_FILES))
CC=g++

$(EXECUTABLE) : $(OBJ_FILES)
	$(CC) $^ -o $@

%.o : %.cpp
	$(CC) -c $^ -o $@

clear:
	rm -rf *o
