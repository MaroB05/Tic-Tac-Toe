compile:
	mkdir -p build
	g++ -W src/main.cpp -o ./build/xo.out

run:
	./build/xo.out

debug:
	g++ src/main.cpp -go ./build/xo.out
	gdb ./build/xo.out

memdebug:
	g++ src/main.cpp -go ./build/xo.out
	valgrind ./build/xo.out
