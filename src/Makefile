#compile tool
CC=g++
#SHELL:=/bin/bash
INCLUDE_DIR=-Iinclude 
#LIBS=-lSDL -lSDLmain -lSDL_image -lGL -lGLU -lCEGUIBase -lCEGUIOpenGLRenderer
LIBS=-lSDL -lSDLmain -lSDL_image -lGL -lGLU
CFLAGS=-Wall -O3

BUILD_DIR=../build/
BIN_DIR=../bin/

#Ŀ�������
TARGET=tankwar
#α����
INSTALL=install

SOURCES=$(wildcard *.cpp)

OBJS=$(patsubst %.cpp, %.o, $(SOURCES))

all : $(TARGET) $(INSTALL)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LIBS)
                         
%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@ -I/usr/local/include/CEGUI

$(INSTALL) : 
	cp *.o $(BUILD_DIR) && cp $(TARGET) $(BIN_DIR)
	
clean : 
	rm *.o 

#gcc test.cpp -I/usr/local/include/CEGUI/ -lSDL -lGL -lGLU -lCEGUIBase -lCEGUIOpenGLRenderer
