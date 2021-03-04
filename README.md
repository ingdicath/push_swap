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

---
## Terms

- [Complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms)
- [Stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))


## Useful links
- [Data structures and Algorithms with their complexities](https://www.hackerearth.com/practice/notes/big-o-cheatsheet-series-data-structures-and-algorithms-with-thier-complexities-1/)
- [Big O notation](https://www.youtube.com/watch?v=v4cd1O4zkGw&list=PLX6IKgS15Ue02WDPRCmYKuZicQHit9kFt&index=5)
- [Introduction to Big O Notation and Time Complexity](https://www.youtube.com/watch?v=D6xkbGLQesk)


https://www.youtube.com/watch?v=GKgAVjJxh9w&list=PLX6IKgS15Ue02WDPRCmYKuZicQHit9kFt&index=1
https://www.youtube.com/watch?v=6Gv8vg0kcHc&list=PLX6IKgS15Ue02WDPRCmYKuZicQHit9kFt&index=17

ver de ultimas
https://www.youtube.com/watch?v=7ArHz8jPglw&list=PLX6IKgS15Ue02WDPRCmYKuZicQHit9kFt&index=31

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