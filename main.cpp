#include "menu.h"

int main() {
    gotoxy(35,24);
    std::cout << "Game này tạo ra dành cho mục đích học tập và nghiên cứu !";
    gotoxy(35,26);
    std::cout << "Ấn phím bất kỳ để tiếp tục... ";
    _getch();
    clearScreen();

    /////////////////////////////////////////////////////////////////////////
    
    play();
    _getch();
    return 0;
}