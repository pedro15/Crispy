OUTPUT = Crispy.exe
FLAGS_GLOBAL = -std=c++20
FLAGS_RELEASE = -O3
FLAGS_DEBUG = -g
SOURCES = src/*.cpp src/commands/*.cpp

build:
	g++ $(SOURCES) $(FLAGS_GLOBAL) $(FLAGS_RELEASE) -o $(OUTPUT)
debug:
	g++ $(SOURCES) $(FLAGS_GLOBAL) $(FLAGS_DEBUG) -o $(OUTPUT)