#include <iostream>     // for cin and cout streams
using namespace std;
#include <string>		 //for string data type
#include <iomanip>		 //for stream manipulator setw(x) setprecision(x)
#include <cmath>		 //for round()

/****************************************************************************
 *                          struct Student{}                                *
 *    Declaration of structure "Student"									*
 *    To group 5 variables related to a student together.			        *
 ***************************************************************************/
struct Student
{
	string stuName;			 //student name
	int numExercise;	     //amount of acceepted weekly exercises(0-40)
	double gradeAssignment;  //grade of the final assignemnt(0-5)

	double gradeExercise;	 //grade from the exercises(0-5)
	double preciseGrade;	 //precise final grade precise grade based on emphasis of exercises and assignment
	int roundGrade;			 //rounded final grade 0-5
};

/****************************************************************************
 *                          struct StuList{}                                *
 *    Declaration of structure "StuList"									*
 *    To group multiple variables related to the list together.				*
 ***************************************************************************/
struct StuList
{
	struct Student stuArray[1000];  //array of students in the program, using nested structure,allowing maximum 1000 elements
	int percentA;					//emphasis of the weekly exercises to the final grade
	int percentB;					//emphasis of the final assignment to the final grade
	int size;						//amount of students that have been put in the program
};
/*******************-----Function Protoypes-----****************************/
void showMenu();
void addStudent(StuList* stulist);
void countGrade(StuList* stulist);
void sortByAlphabet(StuList* stulist);
void sortByGrade(StuList* stulist);
void printStudent(StuList* stulist);
void searchByName(StuList* stulist);
void searchByGrade(StuList* stulist);
void settings(StuList* stulist);
