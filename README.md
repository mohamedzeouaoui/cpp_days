<h1 align="center">CPP Modules</h1>

<p align="center">
  <em>From C to C++98: classes, polymorphism, templates and the STL.</em><br>
  All the C++ modules (00 to 09) of the 42 curriculum.
</p>

<p align="center">
  <img alt="Language" src="https://img.shields.io/badge/language-C%2B%2B98-blue">
  <img alt="Modules" src="https://img.shields.io/badge/modules-00--09-success">
  <img alt="42" src="https://img.shields.io/badge/school-42-black">
</p>

---

## Table of Contents

- [About](#about)
- [Modules Overview](#modules-overview)
- [Compilation](#compilation)
- [Project Structure](#project-structure)
- [Rules and Constraints](#rules-and-constraints)
- [Module Details](#module-details)
- [Author](#author)
- [Acknowledgments](#acknowledgments)

---

## About

This repository contains my solutions to the **C++ modules** of the 42 curriculum. Each module introduces a new set of concepts of the language, building from the basics of classes up to templates and the Standard Template Library.

All the code is written in **C++98** and compiled with strict flags.

## Modules Overview

| Module | Topic                                              | Main concepts                                                  |
|--------|----------------------------------------------------|----------------------------------------------------------------|
| 00     | Namespaces, classes, member functions, stdio streams | Classes, initialization lists, `static`, `const`              |
| 01     | Memory allocation, pointers to members, references | `new` / `delete`, references, file streams, `switch`           |
| 02     | Ad-hoc polymorphism, operator overloading          | Orthodox Canonical Form, fixed-point numbers                   |
| 03     | Inheritance                                        | Base and derived classes, multiple inheritance, diamond problem|
| 04     | Subtype polymorphism, abstract classes, interfaces | `virtual`, abstract classes, deep copy                         |
| 05     | Repetition and exceptions                          | `try` / `catch`, custom exceptions                             |
| 06     | C++ casts                                          | `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`|
| 07     | C++ templates                                      | Function and class templates                                   |
| 08     | Templated containers, iterators, algorithms        | STL containers, iterators, `<algorithm>`                       |
| 09     | STL                                                | Containers, algorithms, parsing, sorting                       |

## Compilation

Each exercise has its own `Makefile`. Go into the exercise folder and run:

```bash
cd cpp00/ex00
make
./megaphone
```

### Makefile rules

| Rule          | Description                              |
|---------------|------------------------------------------|
| `make`        | Compile the exercise                     |
| `make clean`  | Remove object files                      |
| `make fclean` | Remove object files and the executable   |
| `make re`     | Recompile from scratch                   |

### Compiler flags

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## Project Structure

```text
cpp/
├── .vscode/
├── cpp00/
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── cpp01/
├── cpp02/
├── cpp03/
├── cpp04/
├── cpp05/
├── cpp06/
├── cpp07/
├── cpp08/
└── cpp09/
```

Each exercise folder contains its own `Makefile`, header files (`.hpp`) and source files (`.cpp`).

## Rules and Constraints

- Compiled with `c++` and the flags `-Wall -Wextra -Werror -std=c++98`
- No `printf`, `malloc`, `free` or C-style memory management: use `new` and `delete`
- No `using namespace` and no `friend` (unless allowed by the subject)
- No STL containers or `<algorithm>` before Modules 08 and 09
- Classes follow the **Orthodox Canonical Form** from Module 02
- Header files are protected against multiple inclusion
- No memory leaks

## Module Details

### Module 00: Basics

- **ex00 Megaphone**: a program that prints its arguments in uppercase
- **ex01 PhoneBook**: a small contact manager with `Contact` and `PhoneBook` classes
- **ex02 The Job Of Your Dreams**: rebuild the missing source file of an `Account` class from its header and logs

### Module 01: Memory, references and pointers

- **ex00 BraiiiiiiinnnzzzZ**: `Zombie` class, stack vs heap allocation
- **ex01 Moar brainz!**: creating a horde of zombies
- **ex02 HI THIS IS BRAIN**: pointers vs references
- **ex03 Unnecessary violence**: `Weapon`, `HumanA` and `HumanB`
- **ex04 Sed is for losers**: a file search-and-replace program
- **ex05 Harl 2.0**: pointers to member functions
- **ex06 Harl filter**: filtering log levels with a `switch`

### Module 02: Fixed-point numbers

- **ex00 My First Class in Orthodox Canonical Form**: the `Fixed` class
- **ex01 Towards a more useful fixed-point class**: conversions from `int` and `float`
- **ex02 Now we're talking**: operator overloading (comparison, arithmetic, increment, `min` / `max`)
- **ex03 BSP**: point inside a triangle, using `Fixed`

### Module 03: Inheritance

- **ex00 Aaaaand... OPEN!**: the `ClapTrap` class
- **ex01 Serena, my love!**: `ScavTrap` inherits from `ClapTrap`
- **ex02 Repetitive work**: `FragTrap`
- **ex03 Now it's weird!**: `DiamondTrap` and the diamond problem

### Module 04: Polymorphism and abstract classes

- **ex00 Polymorphism**: `Animal`, `Dog`, `Cat` and `virtual` functions
- **ex01 I don't want to set the world on fire**: `Brain` and deep copies
- **ex02 Abstract class**: making `Animal` abstract
- **ex03 Interface and recap**: `AMateria`, `Ice`, `Cure`, `Character` and `MateriaSource`

### Module 05: Exceptions

- **ex00 Mommy, when I grow up, I want to be a bureaucrat!**: the `Bureaucrat` class and its grades
- **ex01 Form up, maggots!**: the `Form` class
- **ex02 No, you need form 28B, not 28C...**: abstract `AForm` and concrete forms
- **ex03 At least this beats coffee-making**: the `Intern` class

### Module 06: C++ casts

- **ex00 Conversion of scalar types**: `ScalarConverter`
- **ex01 Serialization**: `uintptr_t` and `reinterpret_cast`
- **ex02 Identify real type**: `dynamic_cast` on a base class

### Module 07: Templates

- **ex00 Start with a few functions**: templated `swap`, `min` and `max`
- **ex01 Iter**: a templated `iter` function
- **ex02 Array**: a templated `Array` class

### Module 08: Templated containers, iterators, algorithms

- **ex00 Easy find**: `easyfind` in an STL container
- **ex01 Span**: the `Span` class with shortest and longest span
- **ex02 Mutated abomination**: `MutantStack`, an iterable `std::stack`

### Module 09: STL

- **ex00 Bitcoin Exchange**: price lookup from a CSV database
- **ex01 Reverse Polish Notation**: an RPN calculator
- **ex02 PmergeMe**: the merge-insert (Ford-Johnson) sort with two containers

## Author

- **Mohamed Zeouaoui**: [@mohamedzeouaoui](https://github.com/mohamedzeouaoui)

## Acknowledgments

- The 42 network for the subjects and the peer-learning environment
- [cppreference.com](https://en.cppreference.com/)
- The C++98 standard documentation
