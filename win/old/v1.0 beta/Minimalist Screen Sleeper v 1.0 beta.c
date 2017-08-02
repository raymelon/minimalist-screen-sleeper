/* Program Description: A C program that turns all your active monitors off.
   Program Name: Minimalist Screen Sleeper
   Version: 1.0 beta
   Developer: Raymel Francisco
   Date Written: Friday, August 15, 2014 3-4 pm, GMT+8, PST
   Written in: C
   IDE used: Orwell Dev-C++ 5.7.1
   Compiler used: MinGW GCC 4.8.1 32-bit Release
*/
#include <windows.h> // SendMessage(), SetConsoleTitle()
#include <stdio.h> // printf()
#include <conio.h> // getch()
#include <stdlib.h> // system("cls")
int main () {
	int s; // s as for loop counter, s for seconds
	SetConsoleTitle("Minimalist Screen Sleeper v1.0 beta by Raymel Francisco");
	system("color F"); // Set console's text color to bright white.
	// Automatically turns off monitor after 5 seconds.
	for (s = 5; s > 0; s --) {
		printf("All active monitor/s will be automatically turned off in %d s.\n", s);
		Sleep(1000); // sleep(int ms), 1000 ms = 1 s, acts as the timer.
		system("cls"); // clears screen after 1 s, clears the old second value
	} // end for
	// Turns on monitor with any key press or mouse click
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
	Sleep(500);
	printf("\nAll inactive monitor/s turned on. Press any key to end the program...");
	getch(); return 0; // shows 0 if there is zero errors, shows a non-zero integer if there is any error
} // end main()
