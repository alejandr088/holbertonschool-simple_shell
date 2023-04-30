<div id="header" align="center">
<h1>Simple Shell</h1>
</div>

---
<details>
<summary><h3>Project Description</h3></summary>
This is a simple UNIX command line interpreter, also known as a shell, developed as part of the holbertonschool-simple_shell project. The shell is designed to be used in a terminal environment and provides basic functionality for executing commands entered by the user.
</details>

<details>
<summary><h3>Requirements</h3></summary>
 *Allowed editors: vi, vim, emac* s.
 
 You are not allowed to use global* variables.
 
 No more than 5 functions per file* .
 
 It is not necessary to upload the test network to * your repository.
 
 The prototypes of all your functions should be included in your header file called main.h.
 
 Note that we will not provide the putchar function for this project.
</details>

<details>
<summary><h3>Usage</h3></summary>
To use the simple shell, compile the source files using the provided gcc command:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Once compiled, run the shell using the following command (basic mandatory shell):
./hsh

The shell will display a prompt and wait for the user to enter a command. Commands should consist of a single word and should be followed by a new line. After a command has been executed, the prompt will be displayed again, ready for the next command.
</details>

<details>
<summary><h3>Features</h3></summary>
The simple shell provides the following features:
Displaying a prompt and waiting for the user to enter a command
Executing commands entered by the user
Handling errors, such as command not found
Handling the EOF "end of file" condition (Ctrl+D)

The following features are not implemented in the simple shell:
Handling special characters such as ", ', `, , *, &, #
Moving the cursor
</details>

<details>
<summary><h3>Files</h3></summary>
The following files are included in this repository:

[README.md](#README.md): This file, providing documentation for the simple shell
man_1_simple_shell: A manual page for the simple shell, detailing its usage and features
[AUTHORS](#AUTHORS): A file listing all individuals who have contributed content to the repository, following the format specified in Docker
[main.h](#main.h): A header file containing all function prototypes, macros, definintions/includes and global variables.
[main.c](#main.c): An entry point program for the custom shell.
[hell.c](#hell.h): A set of functions needed to execute and tokenize the user input.
[find_path.c](#find_path.c): A function to handle the PATH and FORK.
</details>

<details>
<summary><h3>Contributors</h3></summary>
The following individuals have contributed to the development of the simple shell:
Alejandro Rivello: Implemented basic command execution logic, implemented built-ins, handled error conditions.
Alan Garcia: Handled error conditions and "end of file" condition.
</details>

<details>
<summary><h3>Contact</h3></summary>
For any inquiries or issues regarding the simple shell, please contact the project maintainers:
Alejandro Rivello (jrivello21@gmail.com)
Alan Garcia (avillafan868@gmail.com)
</details>