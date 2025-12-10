# C++ Module 09 - STL

[![C++](https://img.shields.io/badge/Language-C++98-blue)](https://isocpp.org/)
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen)](#)
[![Makefile](https://img.shields.io/badge/Build%20System-Makefile-orange)](#)

This repository contains the exercises for **Module 09** of the C++ curriculum at 42, focusing on the **Standard Template Library (STL)**.

---

## Table of Contents
- [Introduction](#introduction)
- [General Rules](#general-rules)
- [Important Guidelines](#important-guidelines)
- [Exercises](#exercises)
    - [Exercise 00: Bitcoin Exchange](#exercise-00-bitcoin-exchange)
    - [Exercise 01: Reverse Polish Notation](#exercise-01-reverse-polish-notation)
    - [Exercise 02: PmergeMe](#exercise-02-pmergeme)
- [Compilation](#compilation)
- [Usage](#usage)
- [Notes](#notes)
- [Author](#author)

---

## Introduction
C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of C.  
This module introduces the **Standard Template Library (STL)** to handle data efficiently using containers and algorithms.

The focus is on:
- Using containers appropriately
- Implementing algorithms like merge-insert sort
- Applying good C++98 practices

---

## General Rules
- Compile your code with:  
    ```bash
    c++ -Wall -Wextra -Werror -std=c++98
    ```
- Makefile follows the same rules as C projects

---

## Important Guidelines
- You may add additional files if needed to split your code
- Read each module completely before starting
- Examples may contain implicit requirements not stated explicitly
- Use your brain and think critically about the problems
- You will implement many classes; consider scripting your editor for efficiency
- Follow mandatory rules and don't be lazy with the learning process
- Read theoretical concepts to deepen understanding

---

## Exercises

### Exercise 00: Bitcoin Exchange
Implement a program that reads historical Bitcoin exchange rates and outputs the value of a Bitcoin amount on a given date.

### Exercise 01: Reverse Polish Notation
Develop a calculator using Reverse Polish Notation (RPN) to evaluate mathematical expressions.

### Exercise 02: PmergeMe
Implement the merge-insert sort algorithm using two different STL containers.

---

## Compilation
```bash
make
```

---

## Usage
```bash
./btc data.csv input.txt
./RPN "10 5 + 2 *"
./PmergeMe 3 1 2 5 4
```

---

## Notes
- All exercises require proper error handling
- Use STL containers like `std::map`, `std::deque`, `std::vector`
- Follow C++98 standard conventions

---

## Author
mzeouaou
