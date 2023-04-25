This is a simple UNIX command line interpreter, also known as a shell, developed as part of the holbertonschool-simple_shell project. The shell is designed to be used in a terminal environment and provides basic functionality for executing commands entered by the user.

Usage
To use the simple shell, compile the source files using the provided gcc command:

c
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Once compiled, run the shell using the following command:

bash
Copy code
./hsh
The shell will display a prompt and wait for the user to enter a command. Commands should consist of a single word and should be followed by a new line. After a command has been executed, the prompt will be displayed again, ready for the next command.

Features
The simple shell provides the following features:

Displaying a prompt and waiting for the user to enter a command
Executing commands entered by the user
Handling errors, such as command not found
Handling the "end of file" condition (Ctrl+D)
The following features are not implemented in the simple shell:

Using the PATH to search for executables
Implementing built-in commands
Handling special characters such as ", ', `, , *, &, #
Moving the cursor
Handling commands with arguments
Files
The following files are included in this repository:

README.md: This file, providing documentation for the simple shell
man_1_simple_shell: A manual page for the simple shell, detailing its usage and features
AUTHORS: A file listing all individuals who have contributed content to the repository, following the format specified in Docker
Contributors
The following individuals have contributed to the development of the simple shell:

Alejandro Rivello: Implemented basic command execution logic
Alan Garcia: Handled error conditions and "end of file" condition

Contact
For any inquiries or issues regarding the simple shell, please contact the project maintainers:

Alejandro Rivello (jrivello21@gmail.com)
Alan Garcia (avillafan868@gmail.com)
License
The simple shell is open-source software released under the MIT License. You are free to use, modify, and distribute the software in accordance with the terms and conditions of the license.