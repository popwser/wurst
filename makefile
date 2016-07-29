CPP=$(wildcard src/*.cpp)
CPP_SRC=$(CPP)

#all build (for windows you need MinGW and gcc installed, for mac and linux only gcc is needed)
all:
	g++ $(CPP_SRC) -o bin/wurst
	echo "Compiled"
