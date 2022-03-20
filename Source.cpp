// Monticia Dunn
// CS 210 Project One
#include <iostream>
using namespace std;
#include <string>
#include <ctime>
#include <time.h>
#include <windows.h>
#pragma warning(disable: 4996)

// outputs menu display format
void displayMenu() {
    cout << "***************************" << endl;
    cout << "* 1 - Add One Hour        *" << endl;
    cout << "* 2 - Add One Minute      *" << endl;
    cout << "* 3 - Add One Second      *" << endl;
    cout << "* 4 - Exit Program        *" << endl;
    cout << "***************************" << endl;
}

// takes in current hr, min and sec, then increments hr accordingly
void addHour(int* hr, int* min, int* sec) {
    if (*hr == 12) {
        *hr = 01;
    }
    else {
        *hr += 1;
    }
}

// takes in current hr, min and sec, then increments min accordingly and hr if needbe
void addMinute(int* hr, int* min, int* sec) {
    if (*min == 59) {
        *min = 0;
        addHour(hr, min, sec);
    }
    else {
        *min += 1;
    }
}

// takes in current hr, min and sec, then increments sec accordingly and min if needbe
void addSecond(int* hr, int* min, int* sec) {
    if (*sec == 59) {
        *sec = 00;
        addMinute(hr, min, sec);
    }
    else {
        *sec += 1;
    }
}

int main() {
	time_t t = time(NULL);
	tm* timePtr = localtime(&t); // stores the local time of the computer.

    boolean exit = false;
    int choice;
	int seconds = (timePtr->tm_sec);
	int minutes = (timePtr->tm_min);
	int hrs = (timePtr->tm_hour);
	
    while (exit == false) {
        system("cls");
        // display 24 hr clock
        cout << "***************************" << "     " << "***************************" << endl;
        cout << "*      12-Hour Clock      *" << "     " << "*      24-Hour Clock      *" << endl;
        cout << "*      " <<
            (hrs - 12 < 10 ? "0" : "") << (hrs > 12 ? hrs - 12 : hrs) << " : " <<
            (minutes < 10 ? "0" : "") << minutes << " : " <<
            (seconds < 10 ? "0" : "") << seconds << 
            (hrs > 12 ? " PM" : " AM") <<
            "    *" << 
            "     "
            "*      " << 
            (hrs < 10 ? "0" : "") << hrs << " : " << 
            (minutes < 10 ? "0" : "") << minutes << " : " << 
            (seconds < 10 ? "0" : "") << seconds << "      *" << endl;
        cout << "***************************" << "     " << "***************************" << endl;

        // Display option menu
        displayMenu();

        // increment sec
        seconds++;

        // increases the seconds
        if (seconds >= 60) {
            seconds = 1;
            minutes++;
        }
        // increases the minutes
        if (minutes >= 60) {
            minutes = 0;
            hrs++;
        }
        // increases the hours
        if (hrs > 24) {
            hrs = 00;
        }

        // take in user input choice
        cin >> choice;

        // based on user input follows option menu
        switch (choice) {
            case 1:
                // if choice == 1, call addHour function
                addHour(&hrs, &minutes, &seconds);
                // clear screen
                system("CLS");
                break;
            case 2:
                // if choice == 2, call addMinute function
                addMinute(&hrs, &minutes, &seconds);
                system("CLS");
                break;
            case 3:
                // if choice == 3, call addSecond function
                addSecond(&hrs, &minutes, &seconds);
                system("CLS");
                break;
            case 4:
                // if choice == 4, break loop and exit program
                exit = true;
                break;
            default:
                // accepts no other numbers
                break;
        }
    }

    return 0;
}

