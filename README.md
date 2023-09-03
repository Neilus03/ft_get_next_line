# ft get next line

Welcome to my "Get Next Line" (GnL) project from 42 Coding School! 🚀

This repository contains my implementation of the "Get Next Line" project, a fundamental C programming challenge that focuses on file I/O, memory management, and string manipulation. 


| Contents                                             |     
|-----------------------------------------------------|   
| [Result](#result)                                  |  
| [Key Objectives](#key-objectives)                  |        
| [Execution](#execution)                            | 
| [Clarifying Common Doubts about the Buffer Size](#clarifying-common-doubts-about-the-buffer-size)  |
| [Disclaimer about Tests](#disclaimer-about-tests)  |
| [Contributions](#contributions)                    |
| [Feedback](#feedback)                              |
| [Thank You](#thank-you)                            |



![-42-_-nde-la-f](https://user-images.githubusercontent.com/87651732/235460785-6127a6ab-9f43-4b99-a43e-ea90040dab67.svg)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)


## [Result](<img width="198" alt="Screen Shot 2023-07-23 at 12 20 53 PM" src="https://github.com/Neilus03/ft_get_next_line/assets/87651732/857a5cb8-8c63-469b-ab88-c2fcd4b19e30">)
<img width="198" alt="Screen Shot 2023-07-23 at 12 20 53 PM" src="https://github.com/Neilus03/ft_get_next_line/assets/87651732/857a5cb8-8c63-469b-ab88-c2fcd4b19e30">

## Key Objectives:

- Mastering file input/output (I/O) operations in C.
- Effectively managing memory allocation and deallocation.
- Handling different file descriptors and reading from them independently.
- Properly manipulating character strings to parse and store lines.

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
## Clarifying common doubts about the buffer size:

For any BUFFER_SIZE bigger than or equal to 1 the program must work perfectly.

At the end, the BUFFER_SIZE is no more than the size of the buffer used for reading data from a file descriptor into the remaining_str string (which acts as a big static container) in the get_next_line function. Buffer size only determines how many characters can be read at a time from the file into memory.

- A smaller BUFFER_SIZE, such as 10, means that the get_next_line function will read the file in smaller chunks of 10 characters at a time.
- A larger BUFFER_SIZE, such as 1000, allows the get_next_line function to read a larger portion of the file into memory with each iteration, reducing the number of system calls needed to read the file.

## Disclaimer about tests: 

PD: By default I set as the read file a text about mathematics called `fd_math.txt` , you can change it to any other file you have or one of the ones I propose (inside tests folder). You just need to change the path of the txt inside the `get_next_line.c` file, concretely in the main function at the end of the file.

## Contributions:

I completed this project as part of my coursework at 42 Coding School. While I don't actively maintain it, feel free to fork the repository, make improvements, and submit pull requests.

## Feedback:

I'm open to feedback and suggestions for improving my implementation. If you have any ideas or spot any issues, please create an issue or reach out to me!

## Thank You
Thank you for visiting my repository and exploring the "Get Next Line" project. I hope you find it informative and useful for your own coding journey. Happy coding! 🌟
