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
    Name: configParser.h
    Use in the project: Used to scan config files in the project.
**/
 
 #include <limits.h>
 #include <stdio.h>

 #ifndef MATCH
    #define MATCH 0
 #endif

 #ifndef NOT_SUCCESS
    #define NOT_SUCCESS -1
 #endif
 
 #ifndef CONFIGPARSER_H_
    #define CONFIGPARSER_H_
 	const long parseLong (	FILE *iniFile,
	 						const char *fileName, 
	 						const char *section, 
	 						const int sectionSize, 
	 						const char *key, 
	 						const int keySize );
 #endif
