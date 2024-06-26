# push_swap
<p align="center">
<img src="https://github.com/miladrahmat/42-badges/blob/master/badges/push_swapm.png"><img width="144" alt="Screen Shot 2024-06-26 at 13 04 08 PM" src="https://github.com/miladrahmat/push_swap/assets/159012803/dfac9ae1-0ae6-4309-9d82-215982eafd8c">
</p>
<p align="center">
<b>C program that calculates and displays on the standard output the list of instructions, that sorts the integed received as arguments</b>

## Content

- [Introduction](#introduction)

## Introduction

This project is about writing a program that uses an algorithm which will sort a stack of integers by using the minimal amount of actions. The learning objectives of this project are rigor, use of C and use of basic algorithms. Especially focusing on their complexity.

So the we have to sort the integers given as arguments, using 2 stacks and only using the pre-given actions. I decided to use vectors since it was easier for me to implement the actions that can be made. The algorithm that I used is called [The Turk algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) since that was the most efficient algorithm to use for this project.

## Actions

To do the sorting I could use the following operations:


| Action | Description                                                                                         |
|--------|-----------------------------------------------------------------------------------------------------|
| `sa`   | (swap a): Swap the first to elements at the top of stack `a`.                                       |
| `sb`   | (swap b): Swap the first to elements at the top of stack `b`.                                       |
| `ss`   | `sa` and `sb` at the same time.                                                                     |
| `pa`   | (push a): Take the first element at the top of stack `b` and put it at the top of stack `a`.        |
| `pb`   | (push b): Take the first element at the top of stack `a` and put it at the top of stack `b`.        |
| `ra`   | (rotate a): Shift up all elements of stack `a` by 1 so that the first element becomes the last element |
| `rb`   | (rotate b): Shift  up all elements of stack `b` by 1 so that the first element becomes the last element |
| `rr`   | `ra` and `rb` at the same time.                                                                     |
| `rra`  | (reverse rotate a): Shift down all elements of stack `a` by 1 so that the last element becomes the first element |
| `rrb`  | (reverse rotate b): Shift down all elements of stack `b` by 1 so that the last element becomes the first element |
| `rrr`  | `rra` and `rrb` at the same time.                                                                   |
