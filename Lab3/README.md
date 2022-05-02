
## How to Run this Program
Clone the repository with the recursive flag (the recursive flag is necessary in order to clone the data submodule): 

``git clone https://github.com/SDemero/CISC3142.git``

If you forget to include the --recursive flag, you can update the cloned repository with the submodule by running: 

`git submodule update --init`

Next, move into the respository's lab3 directory:

`cd lab3`

Build the program using the provided Makefile by running: 

`make lab3`


## What the program does and is expected to output
The following types of reports are available:

1. Rates by Instructor / Course number
2. Rates by Course
3. Rates by Course & Semester

Data files are in the data submodule

### Input File Format

The input file have same headers and all types will be data type string:
- EMPLID : Student ID Numeber
- COURSENO : course number
- INSTRUCTORID : instructor id number
- TERMID: term is number
- SECTIONID: section id number
- GRADE*: grade for course


*Only the following grades are allowed:
- A+
- A
- A-
- B+
- B
- B-
- C+
- C
- C-
- D+
- D
- D-
- F
- WD
- W
- WN
- WU
- INC
- FIN
- CR
- P
- NC
- AUD
