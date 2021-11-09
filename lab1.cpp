// lab1.cpp
// Jalen Buie
// 1/24/2021
// This code asks for the user for their name, street information, and property value of this and last month. It then computes the change of property value and average monthly mortgage..

#include <iostream>
#include <string>

using namespace std;
int main()
{
	string name;
	// Prompts user for name and outputs
	cout << "What is your name? ";
	cin >> name;
	cout << "Hi there, " << name << ".\n";
	
	//Prompts user for street information and last+this month's property values.
	string street;
	string block;
	string type;
    
	cout << "Enter the property street number, name, and type: ";
	cin >> street >> block >>type;
    double i;
	cout <<"Last month's property value: $ ";
	cin >> i;
    double j;
	cout << "This month's property value: $ ";
	cin >> j;
	cout << endl;

	// This informs user of street location, est. monthly mortgage, and value change.
	cout << "This property is located at: " << street <<' '<<  block << ' ' <<  type << ".\n";
	cout << "It's value has changed by $"<< j-i <<' ' << "since last month." << "\n";
    cout << "The average monthly mortgage is $" << double (j * 0.050)/12 << ".\n";
    cout << "Last month's average monthly value is $" << double (i * 0.050)/12 << ".\n";
	cout << "The average monthly mortgage is $"<< double ((j+i)/ 2) * 0.050/12 << ".\n";
			
	


    return 0; 
}

