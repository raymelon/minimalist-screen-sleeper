/* Program Description: This command line program turns all your active monitors off.
   Program Name: Minimalist Screen Sleeper
   Version: 1.2 beta
   Developer: Raymel Francisco
   Date Written: Friday, September 19, 2014 5 pm - 6 pm GMT+8, PST
   Written in: C, C++
   IDE used: Orwell Dev-C++ 5.7.1
   Compiler used: MinGW GCC 4.8.1 32-bit Release
   Icon information:
   		License: Creative Commons (Attribution 3.0 United States)
   		Creator: FatCow Web Hosting
   		Host: Iconfinder
   		Icon site: https://www.iconfinder.com/icons/36212/delete_monitor_icon
*/
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int s, i, ctr = 1; // counters

void about () {

	char str2[500];

	sprintf(
		str2,
		"ABOUT\n ---------------------------------------------------------------",
		"\n\nSoftware Name:\tMinimalist Screen Sleeper",
		"\nVersion:\t1.3 beta (32-bit)",
		"\nDeveloper:\tRaymel Francisco",
		"\nIcon Designer:\tFatCow Web Hosting",
		"\nIcon License:\tCreative Commons (Attribution 3.0 United States)",
		"\n\nCopyright (c) 2014. All rights reserved.",
		"\n\n\nDeveloped in Orwell Dev-C++ 5.7.1"
	);
	MessageBox(NULL, str2, "ABOUT", MB_OK | MB_ICONASTERISK);
}
void main2 () {

	system("cls");

	for (s = 3; s > 0; s --) {

		printf("\n All active monitor(s) will be turned off in %d s.", s);
		Sleep(1000); // Sleep(int ms), 1000 ms = 1 s, acts as timer
		system("cls");

	} // for

	printf("\n Turning off monitor...");
	system("cls");
	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);

/*	while (SC_MONITORPOWER == 0) {

		Sleep(1000);
		i ++;

	} // while */

	char str[500];

	time_t t;
	time(&t);

	sprintf(
		str,
		"All inactive monitor(s) are now turned on.\nTurned off at:\t%s\n\nClick 'Retry' or Press enter to retry.\n\nTries: %d",
		ctime(&t),
		ctr
	);

	MessageBox(NULL, str, "Success!", MB_RETRYCANCEL | MB_ICONASTERISK);

} // main2

int main () {

	SetConsoleTitle("Minimalist Screen Sleeper v1.3 beta by Raymel Francisco");
	//system("color F"); // console text color to bright white

	do {

		if (IDRETRY) {
			main2 ();
			ctr ++;
		}

		else if (IDCANCEL) {
			exit(0);
		}

	} while (1);

} // main
