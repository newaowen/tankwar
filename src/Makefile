#compile tool
CC=g++
#SHELL:=/bin/bash
INCLUDE_DIR=-Iinclude 
LIBS=-lSDL -lSDLmain -lSDL_image -lGL -lGLU -lCEGUIBase -lCEGUIOpenGLRenderer
CFLAGS=-Wall -O3

BUILD_DIR=../build/
BIN_DIR=../bin/

#目标程序名
TARGET=tankwar
#伪对象
INSTALL=install

SOURCES=$(wildcard *.cpp)

OBJS=$(patsubst %.cpp, %.o, $(SOURCES))

all : $(TARGET) $(INSTALL)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LIBS)
                         
%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@ -I/usr/local/include/CEGUI

$(INSTALL) : 
	mv *.o $(BUILD_DIR) && mv $(TARGET) $(BIN_DIR)

#gcc test.cpp -I/usr/local/include/CEGUI/ -lSDL -lGL -lGLU -lCEGUIBase -lCEGUIOpenGLRenderer
