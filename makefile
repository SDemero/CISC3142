lab1:
    g++ ./lab11/file_in.cpp -o ./lab1/file_in.o -std=c++98
    cd lab1 && ./file_in.o
clean: rm *.o
