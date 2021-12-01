# get_next_line

### Implement a function that outputs the contents of files by the file descriptor fd
The function is implemented using a singly linked list in C, where each element of the list is a file descriptor.
The function should output the first line of the file before the end of line character \n

#### The main part
1. Download the git clone repository https://github.com/venera111/get_next_line.git
2. Compilation of files indicating the size of the read buffer:
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c get_next_line.h
3. Run the executable file ./a.out
The program outputs the first line of the file
4. Checking for memory leaks:
- uncomment a line in the main.c: sleep(10000) file
- enter a command in another terminal with the name of the executable file: leaks a.out
The command outputs the number of bytes that are faces.

#### Bonus part
1. Download the git clone repository https://github.com/venera111/get_next_line .git
2. Compilation of files indicating the size of the read buffer:
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c get_next_line.h
3. Run the executable file ./a.out
The program outputs the first lines of files text.txt , text1.txt , text2.txt
4. Checking for memory leaks:
- uncomment a line in the main.c: sleep(10000) file
- enter a command in another terminal with the name of the executable file: leaks a.out
The command outputs the number of bytes that are memory leaks.


Get_next_line (42cursus) 2021-2022

Actual Status : finished.
Result : 112%
