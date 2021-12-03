all:
	g++ src/main.cpp -o main `cat compile_flags.txt`

clean:
	rm -rf main *.o
