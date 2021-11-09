// lab3b.cpp
// Jalen Buie
// 3/5/2021
// This code is a slot machine! It asks the user for a seed and outputs 3 random values. It allows the  user to bet coins and give a summary at the very end. User starts with 100 coins.

#include <iostream>
#include <limits>
#include <random>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{

    // Asks user for seed. Error checks if non-integer is input.

    int seed;
    int coins = 100;
    int wager;
    int coins_won;

    do
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Input a seed: ";
        cin >> seed;
    } while (!cin);
    
	cout << '\n';
		
    //Set up for random number generator between values of 2-7.
    uniform_int_distribution<int> dist(2, 7);
    default_random_engine dre(seed);

    // Stores wagers and coins_wons into vectors.

    vector<int> wagers;
    vector<int> coins_wons;

    // Loops and tells user how many coins they currently possess and how many they want to bet. Error checks as well.

    nclude <iostream>
#include <limits>
#include <random>
#include <stdio.h>
#include <vector>
		
		using namespace std;
	
	int main()
	{
		
		    // Ask user for seed. Error checks if non-integer is input.
			//
			//     int seed;
			//         int coins = 100;
			//             int wager;
			//                 int coins_won;
			//
			//                     do
			//                         {
			//                                 if (!cin)
			//                                         {
			//                                                     cin.clear();
			//                                                                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//                                                                         }
			//
			//                                                                                 cout << "Input a seed: ";
			//                                                                                         cin >> seed;
			//                                                                                             } while (!cin);
			//
			//                                                                                                 cout << '\n';
			//
			//                                                                                                     //Set up for random number generator between values of 2-7.
			//                                                                                                         uniform_int_distribution<int> dist(2, 7);
			//                                                                                                             default_random_engine dre(seed);
			//
			//                                                                                                                 // Stores wagers and coins_wons into vectors.
			//
			//                                                                                                                     vector<int> wagers;
			//                                                                                                                         vector<int> coins_wons;
			//
			//                                                                                                                             // Loops and tells user how many coins they currently possess and how many they want to bet. Error checks as well.
			//
			//                                                                                                                                 do
			//                                                                                                                                     {
			//
			//                                                                                                                                             cout << "You currently possess:" << ' ' << coins << ' ' << "coins." << '\n';
			//
			//                                                                                                                                                     do
			//                                                                                                                                                             {
			//
			//                                                                                                                                                                         cin.clear();
			//                                                                                                                                                                                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//                                                                                                                                                                                                 cout << "Bet how many coins?" << ' ';
			//
			//                                                                                                                                                                                                         } while (!(cin >> wager) || wager < 0 || wager > coins);
			//
			//                                                                                                                                                                                                                 if (wager == 0)
			//                                                                                                                                                                                                                         {
			//                                                                                                                                                                                                                                     break;
			//                                                                                                                                                                                                                                             }
			//
			//                                                                                                                                                                                                                                                     // Subtracts coin amount from wager and stores it as total amount of current coins.
			//
			//                                                                                                                                                                                                                                                             int total_coins;
			//                                                                                                                                                                                                                                                                     total_coins = coins - wager;
			//
			//                                                                                                                                                                                                                                                                             // Stores random numbers into array of 3.
			//
			//                                                                                                                                                                                                                                                                                     int arr[3];
			//                                                                                                                                                                                                                                                                                             for (int i = 0; i < 3; ++i)
			//                                                                                                                                                                                                                                                                                                     {
			//                                                                                                                                                                                                                                                                                                                 arr[i] = dist(dre);
			//                                                                                                                                                                                                                                                                                                                             cout << arr[i] << ' ';
			//                                                                                                                                                                                                                                                                                                                                     }
			//
			//                                                                                                                                                                                                                                                                                                                                             cout << endl;
			//
			//                                                                                                                                                                                                                                                                                                                                                     // If and if else loops. Supposed to test if array values are equal to one another but that isn't happening for some reason.
			//
			//                                                                                                                                                                                                                                                                                                                                                             if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0] == arr[2] && arr[0] == 7) // If all numbers 7 then wager will be multiplied by 10 and added onto total coins.
			//
			//                                                                                                                                                                                                                                                                                                                                                                     {
			//
			//                                                                                                                                                                                                                                                                                                                                                                                 coins_won = wager * 10;
			//                                                                                                                                                                                                                                                                                                                                                                                             coins = coins_won + total_coins;
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                         cout << "You won" << ' ' << coins_won << ' ' << "coins!" << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                     cout << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                             }
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                     else if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0] == arr[2]) // If all numbers equal but not 7 then wager will be multiplied by 5 and added onto total coins.
			//                                                                                                                                                                                                                                                                                                                                                                                                                                             {
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                         coins_won = wager * 5;
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                     coins = coins_won + total_coins;
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 cout << "You won" << ' ' << coins_won << ' ' << "coins!" << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             cout << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     }
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) // If only two numbers are equal wager will be multiplied by two and added onto total coins.
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     {
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 coins_won = wager * 2;
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             coins = coins_won + total_coins;
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         cout
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         << "You won" << ' ' << coins_won << ' ' << "coins!" << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     cout << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             }
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     // If none of the array values match up with one another then nothing is won.
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             else if (arr[0] != arr[1] && arr[1] != arr[2] && arr[0] != arr[2])
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     {
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 coins = total_coins;
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             coins_won = 0;
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         cout << "You did not win." << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     cout << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             }
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     // Push backs the vector to the first value within the loop.
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             wagers.push_back(wager);
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     coins_wons.push_back(coins_won);
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         } while (coins != 0);
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             // Sets up vector summary. Summarizes min,max, and the bets made in the current seed.
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 int max;
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     int min;
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         int min1;
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             int max1;
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 max = wagers[0];
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     min = wagers[0];
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         min1 = coins_wons[0];
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             max1 = coins_wons[0];
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 cout << "Play Summary:" << '\n';
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     for (int i = 0; i < wagers.size(); i++)
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         {
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 cout << "You wagered" << ' ' << wagers.at(i) << ' ' << "coins" << ' ' << "and won" << ' ' << coins_wons.at(i) << ' ' << "coins." << '\n';
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         if (wagers.at(i) < min)
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 {
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             min = wagers.at(i);
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     }
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             if (wagers.at(i) > max)
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     {
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 max = wagers.at(i);
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         }
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 if (coins_wons.at(i) < min1)
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         {
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     min1 = coins_wons.at(i);
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             }
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     if (coins_wons.at(i) > max1)
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             {
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         max1 = coins_wons.at(i);
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 }
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     }
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         cout << '\n';
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             cout << "Your minimum wager was" << ' ' << min << ' ' << "coins." << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 cout << "Your maximum wager was" << ' ' << max << ' ' << "coins." << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     cout << "Your minimum prize was" << ' ' << min1 << ' ' << "coins." << '\n';
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         cout << "Your maximum prize was" << ' ' << max1 << ' ' << "coins." << '\n';
			//
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             return 0;
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             }d
    {

        cout << "You currently possess:" << ' ' << coins << ' ' << "coins." << '\n';

        do
        {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bet how many coins?" << ' ';
        } while (!(cin >> wager) || wager < 0 || wager > coins);

        if (wager == 0)
        {
            break;
        }

        // Subtracts coin amount from wager and stores it as total amount of current coins.

        int total_coins;
        total_coins = coins - wager;

        // Stores random numbers into array of 3.

        int arr[3];
        for (int i = 0; i < 3; ++i)
        {
            arr[i] = dist(dre);
            cout << arr[i] << ' ';
        }

        cout << endl;

        // If and if else loops. Supposed to test if array values are equal to one another but that isn't happening for some reason.

        if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0] == arr[2] && arr[0] == 7) // If all numbers 7 then wager will be multiplied by 10 and added onto total coins.

        {

            coins_won = wager * 10;
            coins = coins_won + total_coins;

            cout << "You won" << ' ' << coins_won << ' ' << "coins!" << '\n';
			cout << '\n';
        }

        else if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0] == arr[2]) // If all numbers equal but not 7 then wager will be multiplied by 5 and added onto total coins.
        {

            coins_won = wager * 5;
            coins = coins_won + total_coins;

            cout << "You won" << ' ' << coins_won << ' ' << "coins!" << '\n';
			cout << '\n';
        }

        else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) // If only two numbers are equal wager will be multiplied by two and added onto total coins.
        {

            coins_won = wager * 2;
            coins = coins_won + total_coins;

            cout
                << "You won" << ' ' << coins_won << ' ' << "coins!" << '\n';
			cout << '\n';
        }

        // If none of the array values match up with one another then nothing is won.

        else if (arr[0] != arr[1] && arr[1] != arr[2] && arr[0] != arr[2])
        {

            coins = total_coins;
            coins_won = 0;

            cout << "You did not win." << '\n';
			cout << '\n';
        }

        // Push backs the vector to the first value within the loop.

        wagers.push_back(wager);
        coins_wons.push_back(coins_won);

    } while (coins != 0);

    // Sets up vector summary. Summarizes min,max, and the bets made in the current seed.

    int max;
    int min;
    int min1;
    int max1;

    max = wagers[0];
    min = wagers[0];
    min1 = coins_wons[0];
    max1 = coins_wons[0];

    cout << "Play Summary:" << '\n';

    for (int i = 0; i < wagers.size(); i++)
    {
        cout << "You wagered" << ' ' << wagers.at(i) << ' ' << "coins" << ' ' << "and won" << ' ' << coins_wons.at(i) << ' ' << "coins." << '\n';

        if (wagers.at(i) < min) // Lowest wager
        {

            min = wagers.at(i);
        }

        if (wagers.at(i) > max) // Highest wager
        {

            max = wagers.at(i);
        }

        if (coins_wons.at(i) < min1) // Lowest amount of coins won
        {

            min1 = coins_wons.at(i);
        }

        if (coins_wons.at(i) > max1) // Highest amount of coins won
        {

            max1 = coins_wons.at(i);
        }
    }
    
	cout << '\n';
	
    cout << "Your minimum wager was" << ' ' << min << ' ' << "coins." << '\n';
    cout << "Your maximum wager was" << ' ' << max << ' ' << "coins." << '\n';
    cout << "Your minimum prize was" << ' ' << min1 << ' ' << "coins." << '\n';
    cout << "Your maximum prize was" << ' ' << max1 << ' ' << "coins." << '\n';

    return 0;
}
