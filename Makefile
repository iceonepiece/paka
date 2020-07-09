build:
	g++ -w -std=c++14 \
	./src/*.cpp \
	./src/*/*.cpp \
	-lSDL2 -lSDL2_image \
	-o game \

clean:
	rm ./game

run:
	./game
