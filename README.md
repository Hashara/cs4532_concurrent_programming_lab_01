# cs4532_concurrent_programming_lab_01 - 170311U, 170328D

## Description

The program has a linked list implemented with Member, Insert and Delete functions and the program can be run as a,
- serial program
- Parallel program with one mutex for the entire linked list
- Parallel program with read-write locks for the entire linked list

Before the experiments are carried out, the linked list is populated with 1000 elements between 0 and 2^16 - 1 every time the program runs. 

 
Before running the program using an IDE, the following variables need to be set in the `main.c` file accordingly.
- `thread_num` - the number of threads to be created
- `fraction` - to select a case out of case 1, 2, or 3. Assign 1 for case 1, 2 for case 2 and 3 for case 3
- `run_type` - to select the mode of the program. Assign 1 to run as a serial program, 2 to run with mutex and 3 to run with read-write lock. 
