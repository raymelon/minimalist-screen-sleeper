/** Program Description:
	Program Name: Minimalist Screen Sleeper
    Version: 1.5
    Developer: Raymel Francisco
    Development: 	Monday, March 30, 2015 
    					4:43 PM to 7:00 PM
    					8:52 PM to 9:57 PM
    					11:15 PM to 12:01 AM
    				Tuesday, March 31, 2015
    					10:56 AM
					
    Written in: C, Windows Resoucrce Script, Vala
    Compiler Used: GNU GCC 3.4.5 (MinGW Special)
    Text editor: Sublime Text 2 (2.0.2 build 2221)
	
	File Details:
    Name: configParser.c
    Use in the project: Used to scan config files in the project.
**/
#include "configParser.h"

const long parseLong (	FILE *iniFile,
 						const char *fileName, 
 						const char *section, 
 						const int sectionSize, 
 						const char *key, 
 						const int keySize ) {
 	
 	char lineStorage [70];
 	char formatString [7];
 	long returnVal;

    rewind(iniFile);
 	while (fgets(lineStorage, sizeof(lineStorage), iniFile) != NULL) {
 		if (strncmp(lineStorage, section, sectionSize) == MATCH) {

 			while (fgets(lineStorage, sizeof(lineStorage), iniFile) != NULL) {
 				if (strncmp(lineStorage, key, keySize) == MATCH) {
 					
 					sprintf(formatString, "%s%ds%s", "%*", keySize + 1, "%d");
 					sscanf(lineStorage, formatString, &returnVal);

 					if (returnVal > LONG_MAX) {
 						fprintf(stdout, " ERROR: \"%s\" key on %s is greater than usual.\
	 						\n Please change to non negative value.\n Limits: 0 to %ld\n", key, fileName, LONG_MAX);
 						// if (getch()) {
 						// 	return NOT_SUCCESS;
 						// } // if (getch())
                        getch();
                        return NOT_SUCCESS;
 					} else {
 						if (returnVal < 0) {
 							fprintf(stdout, " ERROR: \"%s\" key on %s is negative.\
	 							\n Please change to non negative value.\n Limits: 0 to %ld\n", key, fileName, LONG_MAX);
 							// if (getch()) {
 							// 	return NOT_SUCCESS;
 							// } // if (getch())
                            getch();
                            return NOT_SUCCESS;
 						} else {
 							return returnVal;
 						} // if (returnVal < 0)
 					} // if (returnVal > LONG_MAX)
 				} // if (strncmp(lineStorage, keySize, key) == MATCH)
 			} // if (strncmp(lineStorage, keySize, key) == MATCH)
 		} // while (fgets(lineStorage, sizeof(lineStorage), iniFile) != NULL)
 	} // if (strncmp(lineStorage, sectionSize, section) == MATCH)
 } // const long parseLong (FILE *iniFile, const char *fileName, const char *section, const int sectionSize, const char *key, const int keySize )
