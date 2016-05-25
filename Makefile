CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp,obj/%.o,$(CPP_FILES))

TragedyOfMacbeth: $(OBJ_FILES)
	g++ -o $@ $(OBJ_FILES)
obj/%.o: src/%.cpp
	g++ -c -o $@ $<

clean:
	rm obj/* TragedyOfMacbeth
