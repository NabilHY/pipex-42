# Pipex

Pipex is a C program designed to mimic the behavior of shell commands involving pipes (`|`) and redirection (`<`, `>`). It allows for efficient inter-process communication and file manipulation in a Unix-like environment.

## Overview

The project implements a program called `pipex` that takes a series of commands and file names as arguments. It processes these commands as if they were entered in a shell, using pipes to transfer data between processes and redirection to handle input and output files.

### Usage

The basic usage of `pipex` is as follows:

```
$> ./pipex infile "cmd1" "cmd2" outfile
```

This behaves similarly to the shell command:

```
< infile cmd1 | cmd2 > outfile
```

Additionally, `pipex` supports handling multiple pipes:

```
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

Which behaves like:

```
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

### Advanced Features

In addition to the basic functionality, `pipex` supports the following advanced features:

- **Error Handling**: Thorough error handling ensures the program does not quit unexpectedly and provides informative error messages.
- **Memory Management**: The program is designed to avoid memory leaks, ensuring efficient resource usage.
- **Here Documents**: When the first parameter is `"here_doc"`, `pipex` supports input redirection using `<<` and output redirection using `>>`:

```
$> ./pipex here_doc LIMITER cmd cmd1 file
```

Behaves like:

```
cmd << LIMITER | cmd1 >> file
```

## Requirements

To build and use `pipex`, make sure to comply with the following rules:

- **Makefile**: Provide a Makefile that compiles the source files without relinking.
- **Error Handling**: Thoroughly handle errors to prevent unexpected program termination.
- **Memory Management**: Ensure there are no memory leaks in the program.
- **Input-Output Behavior**: Follow the behavior of the shell command `< file1 cmd1 | cmd2 > file2`.

## Extra Points

To earn extra points, consider implementing the following features:

- **Multiple Pipes**: Support multiple pipes, as described above.
- **Here Documents**: Support input and output redirection using `<<` and `>>` when the first parameter is `"here_doc"`.


Certainly! Here's an updated section in the README to include instructions for building and testing the project:

## Building and Testing

To build and test the project, follow these steps:

### Building

1. Clone the repository to your local machine:

```
git clone https://github.com/NabilHY/pipex-42.git
```

2. Navigate to the project directory:

```
cd pipex-42
```

3. To compile the basic version of the project, run:

```
make
```

This will compile the source files and generate the executable `pipex`.

4. If you want to compile the bonus part with additional features, run:

```
make bonus
```

### Testing

After compiling the project, you can test it using the provided test cases or by creating your own.

1. Run the basic test case:

```
./pipex infile "ls -l" "wc -l" outfile
```

This should behave like:

```
< infile ls -l | wc -l > outfile
```

2. Test the bonus features, such as multiple pipes or here documents, if applicable.

### Cleaning Up

To clean up the generated object files and executables, run:

```
make clean && make fclean
```

This will remove all compiled files from the project directory.

### Notes

- Make sure to have a compatible C compiler installed on your system, such as GCC.
- If you encounter any issues during compilation or testing, refer to the error messages for troubleshooting or consult the project documentation.

## Authors

This project was developed by NabilHY for 42 common core's.
