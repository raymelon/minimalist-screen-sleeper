
#include <windows.h>
#include <stdbool.h>

 #ifndef TITLE_BAR_TEXT
    #define TITLE_BAR_TEXT "Minimalist Screen Sleeper 1.5"
 #endif
 
 #ifndef WINDOW_SIZE
    #define WINDOW_SIZE "mode 65, 6"
 #endif

 #ifndef DEFAULT_SECONDS_VALUE
    #define DEFAULT_SECONDS_VALUE 5
 #endif

 #ifndef SETTINGS_FILENAME
    #define SETTINGS_FILENAME "settings.ini"
 #endif

 #ifndef NON_EXISTING
    #define NON_EXISTING -1
 #endif

 #ifndef IS_EXISTING
    #define IS_EXISTING F_OK 
 #endif

 #ifndef ONE_SECOND
    #define ONE_SECOND 1000
 #endif

 #ifndef TURN_OFF
    #define TURN_OFF 2
 #endif

 #ifndef TURN_ON
    #define TURN_ON -1
 #endif

bool turn_off()
{
	return SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) TURN_OFF);
}