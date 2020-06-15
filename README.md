# mergesort-quicksort
My implementation of mergesort & quicksort in C. 

### Description
This program takes a binary file of long integers and sorts it in ascending order using the Quicksort or Mergesort algorithm.
Some optimizations have been made to improve the performance of the algorithms such as using shell sort for smaller subarrays
(n <= 25). <br /> <br />
The program takes 3 arguments. <br /> 
arg 1: `-q` - Quicksort OR `-m` - Mergesort <br />
arg 2: Input file path <br />
arg 3: Output file path <br /> <br />
Example command line to run program:
<br />
`make pa5` <br />
`./pa5 -q ./inputs/10.b 10_s.b` <br />
Some input files have been included in the './inputs' directory.

### Makefile Instructions

`make pa2` - Compiles the program <br />
`make clean` - Removes all temporary files <br />
`make testN` - N corresponds to testcase 1-5 <br />

