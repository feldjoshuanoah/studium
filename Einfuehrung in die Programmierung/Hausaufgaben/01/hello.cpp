// joshua.feld@rwth-aachen.de, 406718

#include <iostream> // standard library (stdlib) support for i/o

using namespace std;

// main function required for executable
int main() // signature
{ // begin function body
	string name; // initializes memory to hold value of string
	cout << "Name? "; // prints prompt to the standard output
	cin >> name; // stores input from keyboard in variable
	cout << "Hallo " << name
         << ", willkommen zur Einfuehrung in die Programmierung!"
         << endl; // prints text followed by new line to the standard output
	return 0; // mission completed (successfully)
} // end function body
