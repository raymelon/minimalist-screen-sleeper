
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** args)
{
	int until = 3; // seconds before turning off
	printf("Turning off in...");
	fflush(stdout);
	printf("\033[3D");

	int sec = until;
	for(; sec >= 0; sec--) {
		printf(" %d (s)...", sec);
		fflush(stdout);
		printf("\033[9D");

		sleep(1);
	}
	fflush(stdout);
	system("clear");
	fflush(stdout);
	printf("Turning off...\n");

	system("xset dpms force off");
}
