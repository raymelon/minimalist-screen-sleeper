:loop
@echo off
windres res/min_screen_sleeper_rc_1.5.rc -O coff -o res/min_screen_sleeper_rc_1.5.res
gcc -m32 -o bin/minScreenSleeper.exe src/min_screen_sleeper_source_1.5.c src/configParser.c res/min_screen_sleeper_rc_1.5.res
pause
cls
goto loop
