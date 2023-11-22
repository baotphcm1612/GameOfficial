#include "menu.hpp"

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
    gotoxy(35,26);
    if(language == 1)
        std::cout << "Game này tạo ra dành cho mục đích học tập và nghiên cứu!";
    else std::cout << "This game is for learning and research purposes!";
    gotoxy(45,8);
    textcolor(9);
    std::cout << "Leader: Nguyen Quoc Bao";
    textcolor(7);
    gotoxy(45,10);
    std::cout << "Kieu Thi Thao";
    gotoxy(45,12);
    std::cout << "Nguyen Huynh Anh Thu";
    gotoxy(45,14);
    std::cout << "Tran Nguyen Vinh Quang";
    gotoxy(45,16);
    std::cout << "Nguyen Le Thanh Tuyen";
    gotoxy(45,20);
    std::cout << "Donate: MBBANK 625012008 ";
    gotoxy(35,28);
    if(language == 1)
        std::cout << "Ấn phím bất kỳ để tiếp tục...";
    else std::cout << "Press any key to continue... ";
    _getch();
    clearScreen();

    /////////////////////////////////////////////////////////////////////////
    
    play();
    _getch();
    return 0;
}