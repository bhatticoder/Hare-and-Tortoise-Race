#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <fcntl.h>
#include <io.h>
using namespace std;
void moveTortoise(int* position);
void moveHare(int* position);
void displayRaceTrack(int tortoisePosition, int harePosition);
void printInstructions();
const int RACE_LENGTH = 70; // Length of the race track
int main()
{
    srand(time(0));
    int tortoisePosition, harePosition, choice;
    do
    {
        tortoisePosition = 1;
        harePosition = 1;

        cout << "\n-------------------------------\n";
        cout << "Choose an option:" << endl;
        cout << "1. Start the game" << endl;
        cout << "2. Read instructions" << endl;
        cout << "3. Exit the game" << endl;
        cout << "Enter your choice: ";
        cout << "\n-------------------------------\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // Start the game
            do
            {
                moveTortoise(&tortoisePosition);
                moveHare(&harePosition);
                displayRaceTrack(tortoisePosition, harePosition);
                Sleep(1000);
            } while (tortoisePosition < RACE_LENGTH && harePosition < RACE_LENGTH);
            // Display the final positions
            cout << "Tortoise: " << tortoisePosition << "\tHare: " << harePosition << endl;
            // Check and declare the winner
            if (tortoisePosition >= RACE_LENGTH && harePosition >= RACE_LENGTH)
            {
                cout << "It's a tie! What an epic race!" << endl;
            }
            else if (tortoisePosition >= RACE_LENGTH)
            {
                cout << "TORTOISE WINS!!! YAY!!! Carrots and lettuce!" << endl;
            }
            else
            {
                cout << "Hare wins. Yuck!" << endl;
            }
            break;

        case 2:
            // Read instructions
            printInstructions();
            break;

        case 3:
            // Exit the game
            cout << "Exiting the game. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}
void moveTortoise(int* position)
{
    int torPer = rand() % 50 + 1; // Random integer between 1 and 50
    if (torPer >= 1 && torPer <= 50)
    {
        // 50% chance: Fast plod (4 squares to right)
        // 20% chance: Slip (5 squares to left)
        // 30% chance: Slow plod (1 square to right)
        if (torPer <= 25)
        {
            *position += 4; // Fast plod
        }
        else if (torPer <= 35)
        {
            *position -= 5; // Slip
        }
        else
        {
            *position += 1; // Slow plod
        }
    }
    // Reset the position if tortoise goes below 1
    if (*position < 1)
    {
        *position = 1;
    }
}
void moveHare(int* position)
{
    int harePer = rand() % 50 + 1; // Random integer between 1 and 50
    if (harePer >= 1 && harePer <= 50)
    {
        // 38% chance: Sleep (no move)
        // 20% chance: Big hop (11 squares to right)
        // 20% chance: Big slip (9 squares to left)
        // 22% chance: Small hop (1 square to right)
        if (harePer <= 38)
        {
            // Sleep - do nothing
        }
        else if (harePer <= 58)
        {
            *position += 11; // Big hop
        }
        else if (harePer <= 78)
        {
            *position -= 9; // Big slip
        }
        else
        {
            *position += 1; // Small hop
        }
    }
    // Reset the position if hare goes below 1
    if (*position < 1)
    {
        *position = 1;
    }
}
void displayRaceTrack(int tortoisePosition, int harePosition)
{
    // Clear the screen for a clean display on each tick
    system("cls");
    // Set the mode for Unicode characters
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"Let's start the epic race of the century: ";
    wcout << L"\n-----------------------------------------------------------------------\n";
    // Display the race track with T, H, or OUCH!!!
    for (int i = 1; i <= RACE_LENGTH; ++i)
    {
        if (i == 1)
        {
            // Starting gate
            wcout << L"S";
        }
        else if (i == RACE_LENGTH)
        {
            // Finish line
            wcout << L"F";
        }
        else if (i == tortoisePosition && i == harePosition)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Red color
            wcout << L"OUCH!!!";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Reset to white
        }
        else if (i == tortoisePosition)
        {
            wcout << L"🐢";
        }
        else if (i == harePosition)
        {
            wcout << L"🐇";
        }
        else
        {
            wcout << L" ";
        }
    }
    wcout << L"\n-----------------------------------------------------------------------\n";
    // Reset the mode to standard output
    _setmode(_fileno(stdout), _O_TEXT);
}
void printInstructions()
{
    cout << "This is the race of the centuary between Hare and Tortoise. " << endl;
    cout << "Hare sleeps during the game at some points. " << endl;
    cout << "Hare and Tortoise hit with each other at some points of the game. " << endl;
    cout << "Just Watch and enjoy the game. " << endl;
}