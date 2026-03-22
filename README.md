# Linux-Commands

## Linux Command Implementation in C

This repository contains implementations of commonly used Linux commands written in C. The goal of this project is to understand how basic Unix utilities work at a low level.

## Commands Implemented

1. **grep**: Searches for a specified pattern in one or more files
2. **cat**: Concatenates files and prints them to standard output
3. **echo**: Prints its arguments to standard output
4. **wc**: Counts lines, words, and characters in a file

## Project Structure

```
.
├── bin/
├── include/
├── src/
├── Makefile
└── README.md
```

## How to Use

1. Clone the repository:

```
git clone https://github.com/rafailsialakis/Linux-Commands
cd Linux-Commands
```

2. Compile the project using Make:

```
make
```

This will generate the executables inside the `bin/` directory.

3. Run the commands:

* grep:

```
./bin/grep <pattern> <file1> ...
```

* cat:

```
./bin/cat <file1> ...
```

* echo:

```
./bin/echo <message>
```

* wc:

```
./bin/wc <file>
```

## Examples

```
./bin/grep example text.txt
./bin/cat file.txt
./bin/echo "Hello, world!"
./bin/wc file.txt
```

## Clean

To remove compiled files:

```
make clean
```
