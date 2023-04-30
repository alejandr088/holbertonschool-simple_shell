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

* Allowed editors: vi, vim, emac* s.
* You are not allowed to use global* variables.
* No more than 5 functions per file* .
* It is not necessary to upload the test network to * your repository.
* The prototypes of all your functions should be included in your header file called main.h.
* Note that we will not provide the putchar function for this project.
</details>

<details>
<summary><h3>Authorized functions and system calls+</h3></summary>
  
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* printf (man 3 printf)
* fprintf (man 3 fprintf)
* vfprintf (man 3 vfprintf)
* sprintf (man 3 sprintf)
* putchar (man 3 putchar)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)
</details>

<details>
<summary><h3>Usage</h3></summary>
<b>To use the simple shell, compile the source files using the provided gcc command: </b>

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

<b>Once compiled, run the shell using the following command (basic mandatory shell): </b>
./hsh

The shell will display a prompt and wait for the user to enter a command. Commands should consist of a single word and should be followed by a new line. After a command has been executed, the prompt will be displayed again, ready for the next command.
</details>

<details>
<summary><h3>Features</h3></summary>
<b>The simple shell provides the following features: </b>
Displaying a prompt and waiting for the user to enter a command.
Executing commands entered by the user.
Handling errors, such as command not found.
Handling the EOF "end of file" condition (Ctrl+D).

<b>The following features are not implemented in the simple shell:</b>
Handling special characters such as ", ', `, , *, &, #.
Handling exit function.
Moving the cursor.
Some other advanced functions.
</details>

<details>
<summary><h3>Files</h3></summary>
<b>The following files are included in this repository:</b>

[README.md](#README.md): This file, providing documentation for the simple shell.

[AUTHORS](#AUTHORS): A file listing all individuals who have contributed content to the repository, following the format specified in Docker.

[main.h](#main.h): A header file containing all function prototypes, macros, definintions/includes and global variables.

[main.c](#main.c): An entry point program for the custom shell.

[hell.c](#hell.h): A set of functions needed to execute and tokenize the user input.

[find_path.c](#find_path.c): A function to handle the PATH and FORK.
</details>

<details>
<summary><h3>Installation</h3></summary>

  // clone the repository
  
  $ git clone https://github.com/alejandr088/holbertonschool-simple_shell.git
  
  $ cd holbertonschool-simple_shell

</details>

<details>
<summary> <h3>Compilation</h3> </summary>

<b>Your shell will be compiled this way:</b>

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

</details>



<details>
<summary><h3>Contributors</h3></summary>
<b>The following individuals have contributed to the development of the simple shell:</b>

Alejandro Rivello: Implemented basic command execution logic, implemented built-ins, handled error conditions.
Alan Garcia: Handled error conditions and "end of file" condition.
</details>

<details>
<summary><h3>Contact</h3></summary>
<b>For any inquiries or issues regarding the simple shell, please contact the project maintainers:</b>

Alejandro Rivello (jrivello21@gmail.com)
Alan Garcia (avillafan868@gmail.com)
</details>