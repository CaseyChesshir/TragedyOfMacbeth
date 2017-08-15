CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp,obj/%.o,$(CPP_FILES))

TragedyOfMacbeth: $(OBJ_FILES)
	g++ -o $@ $(OBJ_FILES) -std=c++11

obj/%.o: src/%.cpp
	g++ -c $< -o $@ -std=c++11

clean:
	rm obj/* TragedyOfMacbeth

test:
	./TragedyOfMacbeth
