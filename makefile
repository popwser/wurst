CPP=src/main.cpp
CPP_SRC=$(CPP_MAC)

all:
	echo "Compiled for mac"
	g++ $(CPP_SRC) -o bin/wurst
