CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp,obj/%.o,$(CPP_FILES))

all: $(OBJ_FILES)
	g++ -o TragedyOfMacbeth $(OBJ_FILES)
obj/%.o: src/%.cpp
	g++ -c -o $@ $<
