OUTPUT = Crispy.exe
FLAGS_RELEASE = -O3
FLAGS_DEBUG = -g
SOURCES = src/main.cpp src/uci.cpp

build:
	g++ $(SOURCES) $(FLAGS_RELEASE) -o $(OUTPUT)
build-debug:
	g++ $(SOURCES) $(FLAGS_DEBUG) -o $(OUTPUT)