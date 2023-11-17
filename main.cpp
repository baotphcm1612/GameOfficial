#include "menu.h"

int main() {
    gotoxy(30,10);
    std::cout << "Vui lòng chọn ngôn ngữ / Please select your language:  ";
    gotoxy(50,12);
    std::cout << "1. Tiếng Việt ";
    gotoxy(50,14);
    std::cout << "2. English ";
    gotoxy(50,16);
    std::cout << "3. Thoát / Quit ";
    gotoxy(50,20);
    setLanguage();
    clearScreen();
    gotoxy(35,24);
    std::cout << "This game is for learning and research purposes!";
    gotoxy(35,26);
    std::cout << "Game này tạo ra dành cho mục đích học tập và nghiên cứu!";
    gotoxy(35,28);
    std::cout << "Ấn phím bất kỳ để tiếp tục... ";
    _getch();
    clearScreen();

    /////////////////////////////////////////////////////////////////////////
    
    play();
    _getch();
    return 0;
}