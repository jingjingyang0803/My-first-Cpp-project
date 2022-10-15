#include "grade counter.h"

/*******************-----Main Function-----*********************************/

int main()
{
	   
	//Variable Declarations
	StuList stulist;		//define structure variable "stulist" in the program
	stulist.percentA = 40;  //initialize emphasis of weekly exercises as 40%, but the user can reset its value from "6.Reset emphasis"
	stulist.percentB = 60;  //initialize emphasis of final assignment as 60%, but its value will change if percentA is reset
	stulist.size = 0;		//initialize amount of student input is 0,add the value will increase 1 everytime a new student added

	int select = 0;

	while (1)//the user can continue choosing another subfunction from the menu, as long as "0. Exit" is not chosen yet
	{
		showMenu();//to call function "showMenu()"
		
		//check non-numeric input
		bool error;
		do
		{
			error = false;
			cin >> select;//read input of grade for final assignment
			if (cin.fail())
			{
				cout << "Error! Please enter a number between 0-6: ";
				error = true;
				cin.clear();
				cin.ignore(80, '\n');
			}
		} while (error);
		
		switch (select)
		{
			//Function Calls for different user choice
			//using reference parameter to modify contents of structure variable
		case 1://to add a student
			addStudent(&stulist);
			break;
		case 2://to print the student list based on name Alphabetically
			countGrade(&stulist);
			sortByAlphabet(&stulist);
			printStudent(&stulist);
			break;
		case 3://to print the student list based on final precise grade
			countGrade(&stulist);
			sortByGrade(&stulist);
			printStudent(&stulist);
			break;
		case 4://to find a student by his/her name
			searchByName(&stulist);
			break;
		case 5://to search students with certain fianl score
			searchByGrade(&stulist);
			break;
		case 6://to reset emphasis of exercise and assignment
			settings(&stulist);
			break;
		case 0://to exit program
			system("pause");
			return 0;
			break;
		default:
			cout << "Invaid input! Try again." << endl;//if the user input is outside 0-6
			break;
		}
	}
	system("pause");
	return 0;
}


