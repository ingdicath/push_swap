# push_swap

CODAM project Curriculum 2019, added to common core in March 2021.

❗ _Important:_ The subject was changed in May 2021. This project was based on the previous subject.

- **Project type**: Algorithm implementation.
- **Objective**: Sorting data on a stack with a limited set of instructions, using
the lowest possible number of actions, through manipulating various types of algorithms and choosing the one most appropriate solution for an optimized data sorting.

---

## Requirements

Write 2 programs in C:

- The first, named **checker** which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.

- The second one called **push_swap** which calculates and displays on the standard
output the smallest progam using _Push_swap_ instruction language that sorts integer arguments received.

### Allowed functions

write, read, malloc, free, exit


### Movements allowed

#### _Swap_ : Do nothing if there is only one or no nodes.

- **sa** -> swap a - swap the first 2 nodes at the top of stack a.
- **sb** -> swap b - swap the first 2 nodes at the top of stack b.
- **ss** -> sa and sb at the same time.

#### _Push_

- **pa** -> push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- **pb** -> push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.

#### _Rotate_ : The first element becomes the last one.

- **ra** -> rotate a - shift up all nodes of stack a by 1.
- **rb** -> rotate b - shift up all nodes of stack b by 1.
- **rr** -> ra and rb at the same time.

#### _Reverse_ : The last element becomes the first one.

- **rra** -> reverse rotate a - shift down all nodes of stack a by 1.
- **rrb** -> reverse rotate b - shift down all nodes of stack b by 1.
- **rrr** -> rra and rrb at the same time

---

## Strategy

The approach for solving this project was using the circular doubly linked list to make rotate and reverse operations more efficient and, therefore, use fewer movements. An example of this is shown in the following image:

<p align="center"><img src="https://github.com/ingdicath/images_md/blob/main/CDLL.png" width="70%" height="70%"></p>

Basically, the sorting algorithm used for checker was _merge-sort_ and for push_swap was an _insertion sort_ modified.





---
## How to use :hammer:

1. Clone the repository and go to folder ```cd push_swap```
2. Type in the terminal ```make```

### Usage of checker and push_swap

1. They can be used separately using spaces and double quotes:

`./checker 4 2 8 1 3`

`./checker "4 2 8 1 3"`

`./checker "4" "2" "8" "1" "3"`

2. They can be used together:

`ARG="4 2 8 1 3"`

`./push_swap $ARG | ./checker $ARG`

3. They can be used together with an extra flag "-v" to show every sorting step

`./push_swap $ARG | ./checker -v $ARG`

---
## Resources :books:

More info in the Wiki!

----
## Outputs 😎

