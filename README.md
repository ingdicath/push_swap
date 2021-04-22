# push_swap

CODAM project Curriculum 2019, added  to common core in March 2021

- **Project type**: Algorithm implementation.
- **Objective**: Sorting data on a stack with a limited set of instructions, using
the lowest possible number of actions, through manipulating various types of algorithms and choosing the one most appropriate solution for an optimized data sorting.

---

## Requirements

Write 2 programs in C:

- The first, named **checker** which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.

- The second one called **push_swap** which calculates and displays on the standard
output the smallest progam using _Push_swap_ instruction language that sorts integer arguments received.

### Movements allowed

#### _Swap_

Do nothing if there is only one or no nodes.

- **sa** -> swap a - swap the first 2 nodes at the top of stack a.
- **sb** -> swap b - swap the first 2 nodes at the top of stack b.
- **ss** -> sa and sb at the same time.

#### _Push_

- **pa** -> push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- **pb** -> push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.

#### _Rotate_

The first element becomes the last one.

- **ra** -> rotate a - shift up all nodes of stack a by 1.
- **rb** -> rotate b - shift up all nodes of stack b by 1.
- **rr** -> ra and rb at the same time.

#### _Reverse_

The last element becomes the first one.

- **rra** -> reverse rotate a - shift down all nodes of stack a by 1.
- **rrb** -> reverse rotate b - shift down all nodes of stack b by 1.
- **rrr** -> rra and rrb at the same time

---

## Terms

- [Complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms)
- [Stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))


## Useful links

- [Data structures and Algorithms with their complexities](https://www.hackerearth.com/practice/notes/big-o-cheatsheet-series-data-structures-and-algorithms-with-thier-complexities-1/)
- [Big O notation](https://www.youtube.com/watch?v=v4cd1O4zkGw&list=PLX6IKgS15Ue02WDPRCmYKuZicQHit9kFt&index=5)
- [Introduction to Big O Notation and Time Complexity](https://www.youtube.com/watch?v=D6xkbGLQesk)
- [Medium article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Seven steps to solve algorithms](https://www.youtube.com/watch?v=GKgAVjJxh9w&list=PLX6IKgS15Ue02WDPRCmYKuZicQHit9kFt&index=1)
- [Data structures - series](https://www.youtube.com/watch?v=92S4zgXN17o&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=2)

ver de ultimas

---

## To do

### Allowed functions

◦ write
◦ read
◦ malloc
◦ free
◦ exit

### Program structure

Build stacks: The game is composed of 2 stacks named a and b

1) CHECKER PROGRAM (manual)

- Input Validation

	- No duplicates
	- random number integer of either positive or negative
	- name of the executable: ./checker ./push_swap
	- no bigger number
	- numbers separated by spaces

- Data structure

	- Check stacks
		- stack a have numbers
		- stack b starts empty
	- Define movements
		- swap: sa, sb, ss
		- push: pa, pb
		- rotate: ra, rb, rr
		- reverse rotate: rra, rrb, rrr
	- Define sorting algorithm

	- Starts: stack 'a' with numbers in desorder and stack 'b' empty
	- Ends: stack 'a' with sorting numbers and stack 'b' empty

Study: List, linked list, double linked list, stack, queue,

2) PUSH SWAP (automatic)

- Algorithm (push_swap)

Study:  review sorting algorithm (bubble ), binary tree (could be)

### Learnings

- We build 3 stacks: a, b, sorted
- When sorting the stack, we also identify duplicates
- Stack a store input data as requested
- In sorted stack we apply merge sort.
- sorted stack is just double linked, a and b are circular double linked list


porque escogi el merge sort???


