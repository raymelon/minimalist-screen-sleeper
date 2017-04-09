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

#include <stdio.h>
#include <fstream.h>
#include <string.h>
#include <conio.h>

int main () {

    do {
        char seconds [256];

        puts(" \n How long do you want to wait before your screen blacks out ?");
        printf(" (In seconds, integer only.)\n [DEFAULT VALUE: 3]\n\n > ");
        gets(seconds);

        if (strncmp(seconds, "-", 1) == 0 ||
            strncmp(seconds, ".", 1) == 0) {

                printf(" \n Invalid!");
                puts(" \n Press any key to retry...\n");
        }

        else {

            ofstream setting_file;
            setting_file.open ("settings.txt");
            setting_file << seconds;
            setting_file.close();

            puts(" \n Setting changed successfully!");
            puts(" Press any key to retry...\n");
        }

    } while (getch());

}
