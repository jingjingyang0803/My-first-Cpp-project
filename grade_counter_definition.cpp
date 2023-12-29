#include "grade_counter.h"

/*******************-----Function Definitions-----**************************/

/****************************************************************************
 *                          showMenu()                                      *
 *    To show 7 different sub-functions in this program.                    *
 ***************************************************************************/
void showMenu()
{
	cout << "\t***|========== ******** ===========|***" << endl;
	cout << "\t***| 1.Add student                 |***" << endl;
	cout << "\t***| 2.Print students Alphabeticaly|***" << endl;
	cout << "\t***| 3.Print students by grade     |***" << endl;
	cout << "\t***| 4.Search student by name      |***" << endl;
	cout << "\t***| 5.Search student by grade     |***" << endl;
	cout << "\t***| 6.Reset emphasis              |***" << endl;
	cout << "\t***| 0.Exit                        |***" << endl;
	cout << "\t***|===============================|***" << endl;

	cout << "\t   Welcome to Grade Mangement System! " << endl;//welcome message
	cout << " Please select a Function from the menu by entering a number 0-6: " << endl;//a prompt to insturct the user to choose a subfunction
}

/****************************************************************************
 *                          addStudent()                                    *
 *    To  get input of student name, amount of accepted weekly exercises,	*
 *     and grade for the final assignment.							        *
 ***************************************************************************/
void addStudent(StuList* stulist)
{
	string name;
	cout << "\nPlese enter student name: ";// display a prompt to insturct the user to enter data
	cin.ignore();
	getline(cin, name);//read input of student name
	stulist->stuArray[stulist->size].stuName = name;

	int exercise;
	cout << "Please enter score from weekly exercises(0-100 inclusive): ";

	//check non-numeric input
	bool error;
	do
	{
		error = false;
		cin >> exercise;//read input of amount of accepted weekly exercises
		if (cin.fail())
		{
			cout << "Error! Please enter a number between 0-40: ";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error);

	//to limit input between 0-40
	while (exercise < 0 || exercise>40)
	{
		cout << "Error! Please enter a number between 0-40: ";
		cin >> exercise;
	}
	stulist->stuArray[stulist->size].numExercise = exercise;

	double assignment;
	cout << "Please enter grade for the final assignment(0-5 inclusive): ";

	//check non-numeric input
	do
	{
		error = false;
		cin >> assignment;//read input of grade for final assignment
		if (cin.fail())
		{
			cout << "Error! Please enter a number between 0-5: ";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error);

	//to limit input between 0-5
	while (assignment < 0 || assignment> 5)
	{
		cout << "Error! Please enter a number between 0-5: " << endl;
		cin >> assignment;
	}
	stulist->stuArray[stulist->size].gradeAssignment = assignment;

	//update amount of students in the program after a new adding
	stulist->size++;

	cout << "\nStudent added!" << endl;

	system("pause");//press any key to continue
	system("cls");  //clear the screen
}

/****************************************************************************
 *                          countGrade()                                    *
 *    To calculate final precise grade and rounded grade.					*
 *    0-19 exercises -> grading for week exercises 0                        *
 *    20-23 exercises -> grading for week exercises 1                       *
 *    24-27 exercises -> grading for week exercises 2                       *
 *    28-32 exercises -> grading for week exercises 3                       *
 *    33-36 exercises -> grading for week exercises 4                       *
 *    37-40 exercises -> grading for week exercises 5                       *
 ***************************************************************************/
void countGrade(StuList* stulist)
{
	for (int i = 0; i < stulist->size; i++)
	{
		//rules for grade level 0-5 based on amount of accepted exercises
		if (stulist->stuArray[i].numExercise >= 0 && stulist->stuArray[i].numExercise <= 19)
			stulist->stuArray[i].gradeExercise = 0;
		else if (stulist->stuArray[i].numExercise >= 20 && stulist->stuArray[i].numExercise <= 23)
			stulist->stuArray[i].gradeExercise = 1;
		else if (stulist->stuArray[i].numExercise >= 24 && stulist->stuArray[i].numExercise <= 27)
			stulist->stuArray[i].gradeExercise = 2;
		else if (stulist->stuArray[i].numExercise >= 28 && stulist->stuArray[i].numExercise <= 32)
			stulist->stuArray[i].gradeExercise = 3;
		else if (stulist->stuArray[i].numExercise >= 33 && stulist->stuArray[i].numExercise <= 36)
			stulist->stuArray[i].gradeExercise = 4;
		else if (stulist->stuArray[i].numExercise >= 37 && stulist->stuArray[i].numExercise <= 40)
			stulist->stuArray[i].gradeExercise = 5;

		//final precise grade based on grade and emphasis of exercises and assignment
		stulist->stuArray[i].preciseGrade = stulist->stuArray[i].gradeExercise * stulist->percentA / 100 + stulist->stuArray[i].gradeAssignment * stulist->percentB / 100;

		//using static_cast<int> to convert float to int
		stulist->stuArray[i].roundGrade = round((stulist->stuArray[i].preciseGrade));
	}
}

/****************************************************************************
 *                          printStudent()                                  *
 *    To print list of students that have been inputted to the program.		*
 *    Each row shows name of the student, amount of accepted weekly         *
 *     exercises, grade of final assignment, 		                        *
 *     precise grade as well as rounded grade. 			                    *
 ***************************************************************************/
void printStudent(StuList* stulist)
{
	if (stulist->size == 0)
	{
		cout << "\nNo student added yet!" << endl;
	}
	else
	{
		cout << "\n>>>>>>>>>> " << stulist->size << " student(s) have been added to the list <<<<<<<<<<" << endl;

		cout << "     " << "Name:\t" << "Excercises:\t" << "Assignment:\t" << "Precise grade:\t" << "Rounded grade:" << endl;

		for (int i = 0; i < stulist->size; i++)
		{
			cout << i + 1 << "  " << stulist->stuArray[i].stuName << "\t" <<
				stulist->stuArray[i].numExercise << "\t\t" <<
				static_cast<int>(stulist->stuArray[i].gradeAssignment) << "\t\t" <<
				setprecision(1) << fixed << showpoint << stulist->stuArray[i].preciseGrade << "\t\t" <<
				stulist->stuArray[i].roundGrade << endl;
		}
	}
	system("pause");//press any key to continue
	system("cls");  //clear the screen
}

/****************************************************************************
 *                          sortByGrade()									*
 *    To sort the students on the list, basing on precise grade ascending.  *
 ***************************************************************************/
void sortByGrade(StuList* stulist)
{
	for (int i = 0; i < stulist->size - 1; i++)//bubble sorting
	{
		for (int j = 0; j < stulist->size - i - 1; j++)
		{
			if (stulist->stuArray[j].preciseGrade > stulist->stuArray[j + 1].preciseGrade)
			{
				struct Student temp = stulist->stuArray[j];
				stulist->stuArray[j] = stulist->stuArray[j + 1];
				stulist->stuArray[j + 1] = temp;
			}
		}
	}
}

/****************************************************************************
 *                          sortByAlphabet()								*
 *    the list is sorted based on student names alphabetically.				*
 ***************************************************************************/
void sortByAlphabet(StuList* stulist)
{
	for (int i = 0; i < stulist->size - 1; i++)//bubble sorting
	{
		for (int j = 0; j < stulist->size - i - 1; j++)
		{
			if (stulist->stuArray[j].stuName > stulist->stuArray[j + 1].stuName)
			{
				struct Student temp = stulist->stuArray[j];
				stulist->stuArray[j] = stulist->stuArray[j + 1];
				stulist->stuArray[j + 1] = temp;
			}
		}
	}
}


/****************************************************************************
 *                          searchByName()								    *
 *         To find a student by his/her name.						        *
 ***************************************************************************/
void searchByName(StuList* stulist)
{
	cout << "\nPlease enter the name of the student you are searching: ";
	string name;
	cin.ignore();
	getline(cin, name);

	bool isExist = false;//set a flag

	//check first if the student is in the list
	for (int i = 0; i < stulist->size - 1; i++)
	{
		if (stulist->stuArray[i].stuName == name)
		{
			isExist = true;
			cout << "Name:\t" << "Excercises:\t" << "Assignment:\t" << "Precise grade:\t" << "Rounded grade:" << endl;
			cout << stulist->stuArray[i].stuName << "\t" <<
				stulist->stuArray[i].numExercise << "\t\t" <<
				static_cast<int>(stulist->stuArray[i].gradeAssignment) << "\t\t" <<
				setprecision(1) << fixed << showpoint << stulist->stuArray[i].preciseGrade << "\t\t" <<
				stulist->stuArray[i].roundGrade << endl;
		}
	}
	if (isExist == false)
	{
		cout << "Can not find the student!" << endl;
	}

	system("pause");//press any key to continue
	system("cls");  //clear the screen
}

/****************************************************************************
 *                          searchByGrade()								    *
 *        To find students with certain final assignment grade.				*
 ***************************************************************************/
void searchByGrade(StuList* stulist)
{
	cout << "\nPlease enter the grade of the student's final assignment: ";
	double score;
	
	//check non-numeric input
	bool error;
	do
	{
		error = false;
		cin >> score;//read input of grade for final assignment
		if (cin.fail())
		{
			cout << "Error! Please enter a number between 0-5: ";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error);

	bool isExist = false;//set a flag

	//check first if the student is in the list
	for (int i = 0; i < stulist->size - 1; i++)
	{
		if (stulist->stuArray[i].gradeAssignment == score)
		{
			isExist = true;
			cout << "Name:\t" << "Excercises:\t" << "Assignment:\t" << "Precise grade:\t" << "Rounded grade:" << endl;
			cout << stulist->stuArray[i].stuName << "\t" <<
				stulist->stuArray[i].numExercise << "\t\t" <<
				static_cast<int>(stulist->stuArray[i].gradeAssignment) << "\t\t" <<
				setprecision(1) << fixed << showpoint << stulist->stuArray[i].preciseGrade << "\t\t" <<
				stulist->stuArray[i].roundGrade << endl;
		}
	}
	if (isExist == false)
	{
		cout << "Can not find the student!" << endl;
	}

	system("pause");//press any key to continue
	system("cls");  //clear the screen
}

/****************************************************************************
 *                          settings()                                      *
 *        To allow the user reset the emphasis of scores from               *
		  the weekly exercises and final assignment	to the final score	    *
 ***************************************************************************/
void settings(StuList* stulist)
{
	int a;
	cout << "\nPlease choose emphasis of the weekly exercises(1-100): ";

	//check non-numeric input
	bool error;
	do
	{
		error = false;
		cin >> a;//read input of grade for final assignment
		if (cin.fail())
		{
			cout << "Error! Please enter a number between 0-100: ";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error);

	//to limit value between 1-100
	while (a < 0 || a >100)
	{
		cout << "Error! Please enter a number between 1-100: ";
		cin >> a;
	}
	stulist->percentA = a;
	int b = 100 - a;//total percentage is 100%
	stulist->percentB = b;
	cout << "\n\tThe emphasis of the weekly exercises is now set to be " << a << "%." << endl;
	cout << "\n\tThe emphasis of the final assignment is then " << b << " %." << endl;

	system("pause");//press any key to continue
	system("cls");  //clear the screen
}
