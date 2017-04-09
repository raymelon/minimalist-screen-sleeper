/* Program Description: This command line program turns all your active monitors off.
   Program Name: Minimalist Screen Sleeper
   Version: 1.2 beta
   Developer: Raymel Francisco
   Date Written: Saturday, October 18, 2014 9 pm GMT+8, PST
   Written in: C++
   IDE used: Code::Blocks 13.12
   Compiler used: GNU GCC Compiler
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
#include <fstream>
#include <winable.h>

int trial_counter = 1; // global counter

void about () {

    puts("\n ABOUT\n ---------------------------------------------------------------");
	puts("\n Software Name\t:\tMinimalist Screen Sleeper");
	puts(" Version\t:\t1.3 beta (32-bit)");
    puts(" Developer\t:\tRaymel Francisco");
	puts(" Icon Designer\t:\tFatCow Web Hosting");
	puts(" Icon License\t:\tCreative Commons (Attribution 3.0 United States)");
	puts("\n\n Copyright (c) 2014. All rights reserved.");
	puts(" Developed in Code::Blocks 13.12");
} // about

void main2 () {

    std::ifstream setting_file ("settings.txt");

    char setted_second_char [256];
    setting_file >> setted_second_char;

    int setted_second_int = atoi(setted_second_char);

	system("cls");

    int seconds_counter;
	for (seconds_counter = setted_second_int; seconds_counter > 0; seconds_counter --) {

		printf("\n All active monitor(s) will be turned off in %d s.", seconds_counter);
		Sleep(1000); // Sleep(int ms), 1000 ms = 1 s, acts as timer
		system("cls");

	} // for

	printf("\n Turning off monitor...");
	Sleep(1000);
	system("cls");

	clock_t start = clock(), difference;

    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);

    Sleep(1000);

    difference = clock() - start;
    int millisecond = difference * 1000 / CLOCKS_PER_SEC;

	printf("\n\n Time taken: %d seconds %d milliseconds", millisecond / 1000, millisecond % 1000);

	char messagebox_string [500];

	time_t timer;
	time(&timer);

	sprintf(
		messagebox_string,
		"All inactive monitor(s) are now turned on.\nTurned off at:\t%s\n\nClick 'OK' or Press enter to retry.\n\nTries: %d",
		ctime(&timer),
		trial_counter
	);
    about ();

	MessageBox(NULL, messagebox_string, "Success!", MB_OK | MB_ICONASTERISK | MB_APPLMODAL | MB_SETFOREGROUND);

} // main2

int main () {

	SetConsoleTitle("Minimalist Screen Sleeper v1.4 beta by Raymel Francisco");
	system("color F"); // console text color to bright white

	do {
		if (IDOK) {
			main2 ();
			trial_counter ++;
		}
    } while (1);

} // main
