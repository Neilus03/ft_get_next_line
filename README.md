# ft get next line


Reading from a file descriptor (FD) is way too tedious

- Actual Status : finished.
- Result        : 104.

[](file:///Users/nde-la-f/.TemporaryItems/folders.102352/TemporaryItems/(A%20Document%20Being%20Saved%20By%20screencaptureui)/Screen%20Shot%202023-07-23%20at%2012.20.53%20PM.png)

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)



![-42-_-nde-la-f](https://user-images.githubusercontent.com/87651732/235460785-6127a6ab-9f43-4b99-a43e-ea90040dab67.svg)


## Execution:

To easily execute the code copy the ssh link:
```
git clone git@github.com:Neilus03/ft_get_next_line.git gnl_neil
```
then access the folder:
```
cd gnl_neil
```
and execute the following command (you can change the BUFFER_SIZE to any number you want ( >=1 )
```
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 *.c *.h
```
then to see the result:
```
./a.out
```
For any BUFFER_SIZE bigger than or equal to 1 the program must work perfectly.

At the end, the BUFFER_SIZE is no more than the size of the buffer used for reading data from a file descriptor into the remaining_str string (which acts as a big static container) in the get_next_line function. Buffer size only determines how many characters can be read at a time from the file into memory.

- A smaller BUFFER_SIZE, such as 10, means that the get_next_line function will read the file in smaller chunks of 10 characters at a time.
- A larger BUFFER_SIZE, such as 1000, allows the get_next_line function to read a larger portion of the file into memory with each iteration, reducing the number of system calls needed to read the file.


PD: By default I set as the read file a text about mathematics called `fd_math.txt` , you can change it to any other file you have or one of the ones I propose (inside tests folder). You just need to change the path of the txt inside the `get_next_line.c` file, concretely in the main function at the end of the file.
