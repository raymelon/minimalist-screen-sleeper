/* Program Description: This command line program turns all your active monitors off.
   Program Name: Minimalist Screen Sleeper
   Version: 1.2 beta
   Developer: Raymel Francisco
   Date Written: Monday, August 18, 2014 10 pm - 1 am of Tuesday, August 19, 2014, GMT+8, PST
   Written in: C
   IDE used: Orwell Dev-C++ 5.7.1
   Compiler used: MinGW GCC 4.8.1 32-bit Release
   Icon information:
   		License: Creative Commons (Attribution 3.0 United States)
   		Creator: FatCow Web Hosting
   		Host: Iconfinder
   		Icon site: https://www.iconfinder.com/icons/36212/delete_monitor_icon
*/
//---------------- preprocessor directives -------------------------------------------
#include <windows.h> // SendMessage(), SetConsoleTitle()
#include <stdio.h> // printf()
#include <conio.h> // getch()
#include <stdlib.h> // system("cls")
#include <time.h> // ctime()

//--------------- function prototypes ------------------------------------------------
void info ();
void currentTime (void);
void statusBar ();
int trialBox (int acptX);
void prog();
//--------------- global variables ---------------------------------------------------
int trial; // shows how many tries

int main () {
	SetConsoleTitle("Minimalist Screen Sleeper v1.2 beta by Raymel Francisco"); // program title bar string display
	system("color F"); // Set console's text color to bright white.
	do { prog(); } while (getch()); // end do while loop
	system("cls"); // clears screen for new input
	return 0; // shows 0 if there is zero errors, shows a non-zero integer if there is any error
} // end main()

void info () {
	printf(" ABOUT\n ---------------------------------------------------------------");
	printf("\n Software Name: Minimalist Screen Sleeper\n Version: 1.2 beta\n Developer: Raymel Francisco\n Icon Creator: FatCow Web Hosting");
	printf(" \n Icon License: Creative Commons (Attribution 3.0 United States)");
	printf("\n Copyright (c) 2014. All rights reserved. ");
} // end info ()

void currentTime () {
	time_t t;
	time(&t);
	printf("\t\t%s", ctime(&t));
} // end currentTime()

void statusBar () {
	trialBox(trial); // function call
	printf("\n\n ---------------------------------------------------------------");
	printf("\n Tries: %d", trial);
} // end statusBar ()

int trialBox (int acptX) { return trial ++; /* shortcut for x = trial ++; return x; */ } // end trialBox ()

void prog () {
	int s; // s as for loop counter, s for seconds
	// Automatically turns off monitor after 5 seconds.
	system("cls");
	for (s = 5; s > 0; s --) {
		printf("\n All active monitor/s will be automatically turned off in %d s.", s);
		Sleep(1000); // sleep(int ms), 1000 ms = 1 s, acts as the timer
		system("cls"); // clears screen after 1 s, clears the old second value
	} // end for
	printf("\n Turning off monitor..."); Sleep(500); system("cls");
	// Turns off the monitor and turns on the monitor with any key press or mouse click
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2); Sleep(1000);
	printf("\n\n All inactive monitor/s now turned on.");
	printf("\n\n\n\n Turned off at:"); currentTime(); // function call
	printf("\n Press any key to RETRY. Click close button to close.\n\n\n\n");
	info(); statusBar(); // function calls
} // end prog ()
