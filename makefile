OUTPUT = Crispy.exe
FLAGS_GLOBAL = -std=c++20
FLAGS_RELEASE = -O3
FLAGS_DEBUG = -g -DDEBUG
SOURCES = src/*.cpp src/commands/*.cpp src/magics/*.cpp
SOURCES_TESTS = src/commands/tests/*.cpp

build:
	g++ $(SOURCES) $(FLAGS_GLOBAL) $(FLAGS_RELEASE) -o $(OUTPUT)
debug:
	g++ $(SOURCES) $(SOURCES_TESTS) $(FLAGS_GLOBAL) $(FLAGS_DEBUG) -o $(OUTPUT)