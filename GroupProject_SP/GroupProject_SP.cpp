/*
	SOFTWARE DEVELOPMENT YEAR 1 GROUP B
	MEMBERS:
		NATHAN | K00252751
		MARCELLO | K00253266
		ROBIN | K00252501
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
/*
Prototypes
*/
int ShowMenu(void);// Displays menu options and returns the option chosen
void Dispay(int[], int);// Displays all items within the array
int GetTotal(int[], int);// returns the sum of all array integers
double GetAverage(int[], int);// returns the average of all array integers
int GetLargest(int[], int);// returns the largest array integer
int GetSmallest(int[], int);// returns the smallest array integer
int GetNumOccurrences(int[], int, int);// returns the number of occurences for any given integer within the array
void ScaleUp(int[], int, double);// scales the values of the array by a given parameter - returns nothing - call the display function to show result
void Reverse(int[], int);// reverse the array - return nothing - call the display function to show result 
void ZeroBase(int[], int);// zero base (i.e make the smallest value 0 and subtract the smallest value from all array items - return nothing - call the display function to show result 
void MaxBase(int[], int);// max base (i.e add the max value to all array items making the max value the min value) - return nothing - call the display function to show result 
bool InputList(int[], int, string); // this function has been modified to fit the new requirement of taking input from a file (Input.dat) - populates a given array - returns false if the file could not be accessed
void OutputList(int[], int, string); // outputs the values of a given array to a file (Output.dat) - returns nothing
bool CompareList(int[], int, string); // compares the values of an array to the file source (Input.dat) to check if the values have been modified - returns true if the values have been modified - returns false if not

int main()
{
	// Dynamic array that has a max size of 50
	cout << "Please enter array the size: ";
	unsigned int size;// used as input for the pointer array size
	cin >> size;
	// must be 50 or less to run program
	if (size <= 50)
	{
		int* A = { new int[size] };// set up the array if the value meets the requirement of being 50 or less
		bool menu = InputList(A, size, "./Input.dat");
		// Menu runs until the boolean value "menu" is false (that occurs when the option = 0)
		do {
			int option = ShowMenu();
			switch (option)
			{
			case 0:
				// This option did not need a function as it simple required a variable reassignment to end the program
				cout << "Exit selected." << endl;
				menu = false;
				break;
			case 1:
				Dispay(A, size);
				break;
			case 2:
				cout << "Total  is " << GetTotal(A, size) << endl;
				break;
			case 3:
				cout << "Average (rounded to 2 decimal places) is " << setprecision(3) << GetAverage(A, size) << endl;
				break;
			case 4:
				cout << "Largest is " << GetLargest(A, size) << endl;
				break;
			case 5:
				cout << "Smallest is " << GetSmallest(A, size) << endl;
				break;
			case 6:
				int num;
				cout << "Enter number to find occurences: ";
				cin >> num;
				cout << "Occurences = " << GetNumOccurrences(A, size, num) << endl;
				break;
			case 7:
				int scale;
				cout << "Enter scale value: ";
				cin >> scale;
				ScaleUp(A, size, scale);
				cout << "Array has been modified - enter the display option to see results (1)." << endl;
				break;
			case 8:
				Reverse(A, size);
				cout << "Array has been modified - enter the display option to see results (1)." << endl;
				break;
			case 9:
				ZeroBase(A, size);
				cout << "Array has been modified - enter the display option to see results (1)." << endl;
				break;
			case 10:
				MaxBase(A, size);
				cout << "Array has been modified - enter the display option to see results (1)." << endl;
				break;
			default:
				break;
			}
		} while (menu);
		bool hasChanged = CompareList(A, size, "./Input.dat");
		if (!hasChanged)
		{
			char option;
			cout << "Would you like to save this list? (y/n): ";
			cin >> option;
			if (option == 'y')
			{
				OutputList(A, size, "./Output.dat");
				cout << "List saved." << endl;
			}
			else if (option == 'n')
				cout << "List has not changed." << endl;
			else
				cout << "Invalid option." << endl;
		}
		else
			cout << "List has not changed." << endl;
	}
	else
		cout << "Max size is 50.";
	return 0;
}


// definitions
int ShowMenu(void)
{
	int option;
	cout << "Menu\n"
		<< endl
		<< "\n\t 1 - DISPLAY"
		<< "\n\t 2 - TOTAL"
		<< "\n\t 3 - AVERAGE"
		<< "\n\t 4 - LARGEST"
		<< "\n\t 5 - SMALLEST"
		<< "\n\t 6 - OCCURRENCES OF VALUE:"
		<< "\n\t 7 - SCALE UP:"
		<< "\n\t 8 - REVERSE"
		<< "\n\t 9 - ZERO BASE"
		<< "\n\t 10 - MAX BASE"
		<< "\n\t 0 - Exit\n"
		<< endl
		<< "\nEnter option: ";
	cin >> option;
	system("CLS");
	return option;
}
void Dispay(int list[], int size)
{
	cout << "\n Displays all of the values in the collection to the computer screen.\n";
	for (int i = 0; i < size; i++)
		cout << list[i] << endl;
}
int GetTotal(int list[], int size)
{
	int total = 0;
	// get sum of array
	for (int i = 0; i < size; i++)
		total += list[i];
	return total;
}
double GetAverage(int list[], int size)
{
	int total = 0;
	for (int i = 0; i < size; i++)
		total += list[i];
	return (double)total / (double)size;
}
int GetLargest(int list[], int size)
{
	int largest = list[0];
	for (int i = 0; i < size; i++)
		// compare current value to previous
		if (list[i] > largest)
			largest = list[i];
	return largest;
}
int GetSmallest(int list[], int size)
{
	int smallest = list[0];
	for (int i = 0; i < size; i++)
		// compare current value to previous
		if (smallest > list[i])
			smallest = list[i];
	return smallest;
}
int GetNumOccurrences(int list[], int size, int num)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
		if (num == list[i])
			counter++;
	return counter;
}
void ScaleUp(int list[], int size, double scale)
{
	for (int i = 0; i < size; i++)
		list[i] = list[i] * scale;
}
void Reverse(int list[], int size)
{
	int j = size - 1, temp;
	for (int i = 0; i < size / 2; i++)
	{
		temp = list[i];
		list[i] = list[j];
		list[j] = temp;
		j--;
	}
}
void ZeroBase(int list[], int size)
{
	int smallest = GetSmallest(list, size);
	for (int i = 0; i < size; i++)
		list[i] = list[i] - smallest;
}
void MaxBase(int list[], int size)
{
	int largest = GetLargest(list, size);
	for (int i = 0; i < size; i++)
		if (list[i] != largest)
			list[i] = list[i] + largest;
}

bool InputList(int list[], int size, string reference)
{
	int temp;
	ifstream file_;
	file_.open(reference);
	if (!file_.is_open())
	{
		cout << "Could not open file " << reference << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			file_ >> temp;
			list[i] = temp;
		}
	}
	file_.close();
	return 1;
}
void OutputList(int list[], int size, string reference)
{
	ofstream file_;
	file_.open(reference);
	if (!file_.is_open())
		cout << "Could not open file";
	else
		for (int i = 0; i < size; i++)
			file_ << list[i] << endl;
	file_.close();
}
/*
This function will loop up to the second last element of the array - comparing values to the array source
The reason for this is that when calling the max base function the final item of the loop will be the same thus affecting the result
By not comparing the final item this issue is solved without affecting function
*/
bool CompareList(int list[], int size, string reference)
{
	bool modified = false; // assuming that the array has not been changed
	int temp;
	ifstream file_;
	file_.open(reference);
	for (int i = 0; i < size-1; i++)
	{
		file_ >> temp;
		modified = list[i] == temp;
	}
	file_.close();
	return modified;
}