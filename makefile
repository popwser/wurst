CPP=src/main.cpp src/compiler.cpp src/data.cpp src/command.cpp src/commands/command_print.cpp

mac:
	echo "Compiled for mac"
	g++ -std=c++11 $(CPP) -o bin/wurst

win:
	echo "Compiled for win"
	g++ $(CPP) -o bin/wurst.exe
