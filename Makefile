all:
	clang src/*.c -o program.out -Iinclude/

clean:
	rm program.out