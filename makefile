CPP_MAC=$(wildcard src/*.cpp)
CPP_MAC_SRC=$(CPP_MAC)
CPP_WIN=$(wildcard src\\*.cpp)
CPP_WIN_SRC=$(CPP_WIN)

mac:
	echo "Compiled for mac"
	g++ $(CPP_MAC_SRC) -o bin/wurst

win:
	echo "Compiled for win"
	g++ $(CPP_WIN_SRC) -o bin/wurst
