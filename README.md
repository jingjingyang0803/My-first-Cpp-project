# **Grade Counter Application**

## **Overview**

The Grade Counter Application is developed as a part of TAMK course *****5G00DL96 Programming Languages 1*****.  It is a C++ program designed to manage and analyze student grades. This application offers functionalities such as adding student details, calculating grades, sorting students alphabetically or by grade, searching for students by name or grade, and adjusting grading emphasis.

## **Features**

1. **Add Student**: Input student name, weekly exercise scores, and final assignment grade.
2. **Print Students Alphabetically**: Display students in alphabetical order.
3. **Print Students by Grade**: List students based on their final grades.
4. **Search Student by Name**: Find a student's details using their name.
5. **Search Student by Grade**: Search for students with a specific grade in the final assignment.
6. **Reset Emphasis**: Adjust the weighting of weekly exercises and final assignment in the final grade calculation.
7. **Exit**: Terminate the program.

## **Technical Details**

- Language: C++
- Data Structures: Arrays, Structs

## **How to Run**

1. Clone the project and navigate to its folder.
2. Compile your files using the command `g++ -o grade_counter grade_counter.cpp grade_counter_definition.cpp`.
3. Run the compiled program with the command `./grade_counter`.
4. Follow the on-screen menu and select an option by entering a number (0-6). 

## **Structure**

- **`Student`**: Struct to store individual student details.
- **`StuList`**: Struct to manage a list of students.
- Functions for each feature listed above.

## **Limitations**

- The program handles a maximum of 1000 students.
- The data is not persistent (it is lost when the program exits).
