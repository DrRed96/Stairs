# *******************
# * Stairs Makefile *
# *******************

UNAME_S = $(shell uname -s)

CC = g++

CFLAGS = -O3 -std=c++17 -Wall
CFLAGS += -Isrc -Ilib/jsoncpp -Ilib/tinyxml/include "-Ilib/SFML/include"
CFLAGS += -DSFML_STATIC

LDFLAGS = "-Llib/SFML/lib"
LDFLAGS += -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-network-s -lsfml-system-s -lopengl32 -lfreetype -lgdi32 -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lws2_32 -lwinmm

SRC = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/**/**/*.cpp)
LIBS = $(wildcard lib/**/*.cpp)
OBJ = $(SRC:.cpp=.o) $(LIBS:.cpp=.o)

RC = $(wildcard res/*.rc)
RES = $(RC:.rc=.res)

.PHONY: all clean

all: build

run: build
	@printf "\\033[92mRunning executable\\033[0m\\n"
	@cd bin && ./Stairs

build: $(OBJ) $(RES)
	@printf "\\033[92mBuilding Executable\\033[0m\\n"
	@$(CC) -o bin/Stairs $^ $(LDFLAGS)

%.o: %.cpp
	@printf "\\033[92mCompiling $<\\033[0m\\n"
	@$(CC) -c -o $@ $< $(CFLAGS)

%.res: %.rc
	@printf "\\033[92mCompiling $<\\033[0m\\n"
	@windres $< -O coff -o $@

# make clean
clean:
	@printf "\\033[92mRemoving .o files\\033[0m\\n"
	@rm $(OBJ) $(RES)
