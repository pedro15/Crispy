OUTPUT = Crispy.exe
FLAGS_GLOBAL = -std=c++20
FLAGS_RELEASE = -O3
FLAGS_DEBUG = -g
SOURCES = src/Main.cpp src/Uci.cpp src/commands/CommandBase.cpp src/commands/HelpCommand.cpp

build:
	g++ $(SOURCES) $(FLAGS_GLOBAL) $(FLAGS_RELEASE) -o $(OUTPUT)
build-debug:
	g++ $(SOURCES) $(FLAGS_GLOBAL) $(FLAGS_DEBUG) -o $(OUTPUT)