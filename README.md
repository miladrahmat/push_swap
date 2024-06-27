# push_swap
<p align="center">
<img src="https://github.com/miladrahmat/42-badges/blob/master/badges/push_swapm.png"><img width="144" alt="Screen Shot 2024-06-26 at 13 04 08 PM" src="https://github.com/miladrahmat/push_swap/assets/159012803/dfac9ae1-0ae6-4309-9d82-215982eafd8c">
</p>
<p align="center">
<b>A C program that sorts integers from input arguments, showcasing a minimal-action sorting algorithm and displaying the sequence of operations used.</b>

## Content

- [Introduction](#introduction)
- [Actions](#actions)
- [Limits](#limits)
- [Bonus](#bonus)
- [Examples](#examples)

## Introduction

This project is about writing a program that uses an algorithm which will sort a stack of integers by using the minimal amount of actions. The learning objectives of this project are rigor, use of C and use of basic algorithms. Especially focusing on their complexity.

The challenge was to sort integers provided as input using two stacks and a set of predefined operations. To facilitate this, I chose to implement the operations using vectors for ease of manipulation, despite vectors not being a built-in feature in C. This required me to create a custom vector implementation, a skill I anticipate leveraging in future projects.

The algorithm that I implemented is [The Turk algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) since that was the most efficient solution for this specific project.

## Actions

To do the sorting I could use the following operations:


| Action | Description                                                                                                       |
|--------|-------------------------------------------------------------------------------------------------------------------|
| `sa`   | (swap a): Swap the first to elements at the top of stack `a`.                                                     |
| `sb`   | (swap b): Swap the first to elements at the top of stack `b`.                                                     |
| `ss`   | `sa` and `sb` at the same time.                                                                                   |
| `pa`   | (push a): Take the first element at the top of stack `b` and put it at the top of stack `a`.                      |
| `pb`   | (push b): Take the first element at the top of stack `a` and put it at the top of stack `b`.                      |
| `ra`   | (rotate a): Shift up all elements of stack `a` by 1 so that the first element becomes the last element.           |
| `rb`   | (rotate b): Shift  up all elements of stack `b` by 1 so that the first element becomes the last element.          |
| `rr`   | `ra` and `rb` at the same time.                                                                                   |
| `rra`  | (reverse rotate a): Shift down all elements of stack `a` by 1 so that the last element becomes the first element. |
| `rrb`  | (reverse rotate b): Shift down all elements of stack `b` by 1 so that the last element becomes the first element. |
| `rrr`  | `rra` and `rrb` at the same time.                                                                                 |
## Limits

For you to get the maximum points for the project, there are some limits to how many actions can the program make.

- For 3 integers: 3 actions.
- For 5 integers: 12 actions.
- For 100 integers: 700 actions.
- For 500 integers: 5500 actions.

## Bonus

In the bonus part of the project I had to write a program called `checker` that takes as an argument the stack `a` formatted as a list of integers. It will wait and read instructions on the standard input. Once all the instructions are read, the program has to execute them on the stack received as an argument.

If after executing those instructions, the stack `a` is actually sorted and the stack `b` is empty, then the program will display "OK" on the standard output, otherwise it displays "KO" on the standard output. In case of an error it displays "Error" on the standard error.

## Examples

For the `push_swap` program:

```
$> ./push_swap 2 1 3 5 4
pb
pb
sb
sa
ra
pa
pa
```
```
$> ./push_swap "9 8 1 2 5 4 3 0 7"
pb
pb
sb
pb
pb
pb
rb
pb
sa
rra
pa
rra
pa
pa
rra
pa
pa
rra
pa
ra
ra
ra
ra
```

For the `checker` program:

```
$> ARG="9 0 1 2 3 8 4 5 7 6"; ./push_swap $ARG | ./checker $ARG
OK
```
```
$> ./checker 5 4 3 2 1
pb
pb
sb
sa
rra
pa
pa
ra
ra
OK
```
```
$> ./checker 5 4 3 2 1
sa
ra
pb
ra
pa
KO
```
