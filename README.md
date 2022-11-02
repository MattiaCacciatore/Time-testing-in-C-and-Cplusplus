# Algorithm/Functions/Programs time testing

How to check the total time of execution for single algorithm, function or program (useful for unit testing)
or the total time of execution for multiple algorithms, functions or programs (useful for system testing)

## Usage

<details><summary><b>Show instructions</b></summary>
  
1. Download and compile
  
 1.1 C++ compile flags (c++11 or newer):

  ```sh
  $ g++ -std=c++11 TimeTesting.cpp -o TimeTesting
  
  $ ./TimeTesting
  ```
 1.2 C compile flags (any C standard version with the recent glibc version):
  
  ```sh
  $ gcc -std=c17 -D_POSIX_SOURCE -D_GNU_SOURCE -D_POSIX_C_SOURCE=199309L TimeTesting.cpp -o TimeTesting
  
  $ ./TimeTesting
  ```

2. For the programs variant (once compiled), an example:

  ```sh
  $ ./TimeTesting ./a.out
  ```
PLEASE NOTE: Be assure that the second argument is passed with the correct path.

## Motivation

I needed a simple program in C/C++ to test the time complexity of my functions and programs and
i wanted to study in deep the time counting, similar to the `time` command in Unix.

## Why

So i (and you) can test easily any program (in any language) or function (in C/C++).

## Problem solved

The limit of utility of `time` command in the case you have to test single functions in your code
(limited for C/C++, for now). If you're interested for the C part, just comment che C++ includes 
and the dotest_cpp() function.

## Knowledge

How to count the time passing in C (clock_gettime() from the time library) and C++ (high_resolution_clock
from the chrono library).
