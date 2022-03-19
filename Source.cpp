// Monticia Dunn
// CS 210 Project One
#include <iostream>
using namespace std;
#include <string>
#include <ctime>
#include <time.h>
#include <conio.h>

int main() {
	//Current time
	time_t now = time(0);
}

// takes in hour, minute or second and increments it
int incrementTime(int currUnit) {
	currUnit = currUnit + 1;
	return currUnit;
}