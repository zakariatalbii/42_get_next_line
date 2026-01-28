# get_next_line

A C function that reads a line from a file descriptor, part of the 42 school curriculum.

## Description

`get_next_line` is a function that returns a line read from a file descriptor. This project teaches important concepts about static variables, memory allocation, and file manipulation in C.

## Mandatory Features

The mandatory part requires implementing a function that:
- Reads and returns one line at a time from a file descriptor
- Returns the line including the terminating `\n` character (except at EOF)
- Returns `NULL` when there's nothing left to read or an error occurs
- Works with a defined buffer size (BUFFER_SIZE) set at compilation
- Handles reading from files and standard input
- Uses only one static variable
- Must be memory leak-free

## Bonus Features

The bonus implementation adds:
- **Multiple file descriptor management**: The function can handle multiple file descriptors simultaneously without losing the reading position of each
- **Single static variable**: Manages all file descriptors using only one static variable

This allows code like:
```c
line1 = get_next_line(fd1);
line2 = get_next_line(fd2);
line3 = get_next_line(fd1); // Continues from where fd1 left off
```

## Function Prototype

```c
char	*get_next_line(int fd);
```

## Compilation

The project includes a Makefile with the following rules:

```bash
make		# Compile mandatory part and create a libftgnl.a library
make bonus	# Compile with bonus features
make clean	# Remove object files
make fclean	# Remove object files and library
make re		# Recompile
```

You can also specify the buffer size:

```bash
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

## Usage

1. Clone the repository:
```bash
git clone git@github.com:zakariatalbii/42_get_next_line.git
cd 42_get_next_line
```

2. Compile the library:
```bash
make		# For mandatory
make bonus	# For bonus
```

3. Include in your project:
```c
#include "get_next_line.h"
#include "get_next_line_bonus.h" // bonus header
```

4. Compile your project with the library:
```bash
cc your_file.c -L. -lftgnl -Iinclude -Ibonus/include -o your_program
```

### Example usage:

```c
#include "get_next_line.h"
#include <stdio.h> // for printf()

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
	    printf("%s", line);
	    free(line);
	}
	close(fd);
	return (0);
}
```

## Project Structure

- **Makefile** - Build configuration
- **src/** - Mandatory source files
- **include/** - Mandatory header file
- **bonus/** - Bonus implementation
- **en.subject.pdf** - Project subject

## Author

**Zakaria Talbi**
- GitHub: [@zakariatalbii](https://github.com/zakariatalbii)

## License

This project is part of the 42 School curriculum.