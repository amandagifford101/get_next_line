# get_next_line
get next line

What is Get Next Line?

Get Next Line is a 42 project that takes any valid file as input and prints it line by line. 

How is this project useful?

This project is useful if you are working in the C language because it will help you to learn
more about static variables, pointers, arrays, dynamic memory allocation and file manipulation.

How do I use it?

I have added a main2.c that takes a file, opens it, and passes a file descriptor to Get_Next_line, which runs
until it is able to return a 0, or in case of error -1.

So in order to test this program, clone the repo below:

git clone https://github.com/amandagifford33/get_next_line.git get_next_line

Get into it and build Library:

cd get_next_line
make -C libft                               

Compile executable with:

gcc -Wall -Werror -Wextra main.c libft/libft.a get_next_line.c

Run executable with:

./a.out test.txt

This should automatically read the whole file for you, just as if you had used the cat() function. 






