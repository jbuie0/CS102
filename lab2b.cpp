// lab2b.cpp
// Jalen Buie
// 2/22/2021
// This code tells the user if a interstate is primary/auxilary, whether it runs east/west or north/south, and if it above 100 what primary highway it serves. It will loop until 0 is entered.

#include <iostream>
#include <limits>
#include <stdio.h>

using namespace std;
int main()

{
	// Stores interstate as an integer

	int interstate;

	do
	{
		// Ask user for interstate number and loops forever until 0 is inputted. If 0 is inputted, code will stop.

		cout << "Enter an interstatetate number:";
		while (!(cin >> interstate))
		{
			// Serves as error checker. Any non-numerical value inputted is invalid and prompts user for valid integer.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input, try again:";
		}

		if (interstate == 0)
			break;

		//If else statement for highway numbers. If between 1-99 it is primary. If it is between 101-999 it is auxiliary. Odd numbers go north/south. Even go east/west.
		if (interstate > 0 && interstate < 100 && interstate % 2 == 0)
			cout << "I-" << interstate << " "
				 << "is a primary interstate, going east/west.\n";

		else if (interstate > 0 && interstate < 100 && interstate % 2 == 1)
		{
			cout << "I-" << interstate << " "
				 << "is a primary interstate, going north/south.\n";
		}

		// Test whether or not interstate is between 101-1000. Divides by 2 to determine if it is odd/even. Anything divisible by 100 with remainder of 0 does not compute.
		else if (interstate > 100 && interstate < 1000 && interstate % 2 == 0 && interstate % 100 != 0)
		{
			cout << "I-" << interstate << " "
				 << "is an auxiliary hig hway, serving I-" << interstate % 100 << ", going east/west.\n";
		}

		else if (interstate > 100 && interstate < 1000 && interstate % 2 == 1 && interstate % 100 != 0)
		{
			cout << "I-" << interstate << " "
				 << "is an auxiliary highway, serving I-" << interstate % 100 << ", going north/south.\n";
		}

		// Integers that are negative, not between range of 1-99 and 101-999, and can be divided by 100 with remainder of 0 are all not valid.

		else
		{
			cout << interstate << " "
				 << "is not a valid interstate number. \n";
		}
	}

	// Loop will continue as long as integers are not 0

	while (interstate != 0);

	return 0;
}
