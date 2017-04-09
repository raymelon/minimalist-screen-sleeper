/* Program Description: This command line program turns all your active monitors off.
   Program Name: Minimalist Screen Sleeper
   Version: 1.1 beta
   Developer: Raymel Francisco
   Date Written: Saturday, August 16, 2014 5-7 pm, GMT+8, PST
   Written in: C
   IDE used: Orwell Dev-C++ 5.7.1
   Compiler used: MinGW GCC 4.8.1 32-bit Release
   Icon information:
   		License: Creative Commons (Attribution 3.0 United States)
   		Creator: FatCow Web Hosting
   		Host: Iconfinder
   		Icon site: https://www.iconfinder.com/icons/36212/delete_monitor_icon
*/
#include <windows.h> // SendMessage(), SetConsoleTitle()
#include <stdio.h> // printf()
#include <conio.h> // getch()
#include <stdlib.h> // system("cls")
int main () {
	int s; // s as for loop counter, s for seconds
	SetConsoleTitle("Minimalist Screen Sleeper v1.1 beta by Raymel Francisco");
	system("color F"); // Set console's text color to bright white.
	// Automatically turns off monitor after 5 seconds.
	for (s = 5; s > 0; s --) {
		printf("\n All active monitor/s will be automatically turned off in %d s.\n ", s);
		Sleep(1000); // sleep(int ms), 1000 ms = 1 s, acts as the timer.
		system("cls"); // clears screen after 1 s, clears the old second value
	} // end for
	// Turns off the monitor and turns on the monitor with any key press or mouse click
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2); Sleep(500);
	printf("\n All inactive monitor/s turned on.\n\n Press any key to EXIT.\n\n\n\n\n\n\n");
	printf(" ABOUT\n ----------------------------------------");
	printf("\n Software Name: Minimalist Screen Sleeper\n Version: 1.1 beta\n Developer: Raymel Francisco\n Icon Creator: FatCow Web Hosting");
	printf(" \n Icon License: Creative Commons (Attribution 3.0 United States)");
	printf("\n Copyright (c) 2014. All rights reserved.\n\n ");
	getch(); // gets any character before terminating the program
	return 0; // shows 0 if there is zero errors, shows a non-zero integer if there is any error
} // end main()
