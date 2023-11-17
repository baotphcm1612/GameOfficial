#pragma once
#include <Windows.h>
#include <conio.h>

static int language = 0;

inline void setLanguage() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD cNumRead;
    INPUT_RECORD irInBuf[128];
    bool isExit = false;
    while(true) {
        if (GetNumberOfConsoleInputEvents(hInput, &cNumRead) > 0) {
            ReadConsoleInputA(hInput, irInBuf, cNumRead, &cNumRead);
            for (DWORD i = 0; i < cNumRead; ++i) {
                if (irInBuf[i].EventType == KEY_EVENT && irInBuf[i].Event.KeyEvent.bKeyDown) {
                    switch (irInBuf[i].Event.KeyEvent.wVirtualKeyCode) {
                        case 0x31:  // Phím 1
							language = 1;
                            isExit = true;
                            break;
                        case 0x32:  // Phím 2
							language = 2;
                            isExit = true;
                            break;
                        case 0x33:  // Phím 3
							exit(0);
                        default:
                            break;
                    }
                }
            }
            if(isExit) break;
        }
    }
}