// lab4b.cpp
// Jalen Buie
// 3/26/2021
// This code is an authoring assistant. It will ask the user for a line of text to enter and then prompt them with different menu options.

#include <iostream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

// Defines functions used in code.

int NumWords(const string &);
int NumNonWSCharacters(const string &);
void CharReplace(string &, char, char);
char PrintMenu();

int main() // Main Function in which the menu and other functions are called. Error checking also is included

{
    string text;
    char a;

    char oldCharacter;
    char newCharacter;
    string words;

    cout << "Enter a line of text: ";
    getline(cin, text);

    cout << "\n";

    cout << "You entered: " << text << "\n";
    do // Code will loop until q is entered.
    {
        cout << "\n";
        a = PrintMenu(); //Outputs menu

        switch (a) // Switch statement. Checks cases for different menu options and executes codes in the specific function.
        {

            do // Error Check
            {

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

            } while (a != 'q' || a != 'w' || a != 'c' || a != 'r');

        case 'w': // Case c. Counts number of words.

            cout << "\n";
            cout << "Number of words:"
                 << " " << NumWords(text);
            cout << "\n";
            break;

        case 'c': // Case c. Counts numbers of non-white space characters.

            cout << "\n";
            cout << "Number of non-whitespace characters:"
                 << " " << NumNonWSCharacters(text);
            cout << "\n";
            break;

        case 'r': // Case r. Replaces characters

            cout << "Enter a character to find: ";

            cin >> oldCharacter;

            cout << "Enter a character to replace: ";

            cin >> newCharacter;

            CharReplace(text, oldCharacter, newCharacter);
            cout << "New string:"
                 << " " << text;
            cout << "\n";
            break;

        case 'q': // Once q is entered code breaks.
            break;
        }
    } while (a != 'q');
}
char PrintMenu() // Menu options
{

    char selection;

    cout
        << "Options"
        << "\n";
    cout << "w - Number of words"
         << "\n";
    cout << "c - Number of non-whitespace characters"
         << "\n";
    cout << "r - Replace a character"
         << "\n";
    cout << "q - Quit"
         << "\n";

    cout << "\n";

    cout << "Choose an option: ";
    cin >> selection;

    return selection;
}

int NumWords(const string &words) // Word Counter
{

    stringstream t;
    string words_temp;
    t << words;
    words_temp = "";

    int wordCount = 0;
    while (t >> words_temp)
    {
        ++wordCount;
    }

    return wordCount;
}

int NumNonWSCharacters(const string &text) // Outputs non whitespace characters
{

    stringstream t;
    string remove;
    string text_temp;
    t << text;
    text_temp = text;
    text_temp = "";
    while (t >> remove)
    {

        text_temp = text_temp + remove;
    }

    string character = text_temp;

    return character.length();
}

void CharReplace(string &text, char oldCharacter, char newCharacter) // Replaces characters within text
{

    stringstream t;
    string replace;
    string replace_temp;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == oldCharacter)
        {

            text[i] = newCharacter;
        }
    }
}
