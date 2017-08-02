:loop
::valac -X -mwindows --pkg gtk+-3.0 gui.vala turn_off.c -o bin/minScreenSleeper-gui
valac --pkg gtk+-3.0 gui.vala turn_off.c -o bin/minScreenSleeper-gui
pause
cls
goto loop
