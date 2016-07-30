CPP=src/main.cpp

mac:
	echo "Compiled for mac"
	g++ $(CPP) -o bin/wurst

win:
	echo "Compiled for win"
	g++ $(CPP) -o bin/wurst.exe
