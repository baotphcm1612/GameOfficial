#include "guess_number.h"
#include "menu.h"

int guess_number::count = 0;

void guess_number::set_result() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> ran(1,20);
    result = ran(gen);
}

void guess_number::get_result() {
    gotoxy(50,18);
    std::cout << "Kết quả là: " << result << std::endl;
}

void guess_number::set_Selection() {
    count = 1;
    for(; count <= 3;count++) {
        gotoxy(30,12);
        std::cout << "Lượt thứ " << count <<" (1 - 20): ";
        std::cin >> selection;
        if(selection == result) {
            clearCharacter(30,70,14);
            gotoxy(30,14);
            std::cout << "Bạn đã thắng !" << std::endl;
            win_lose = true;
            bonus(7 - count);
            break;
        }
        else if(count != 3){
            clearCharacter(30,70,12);
            clearCharacter(30,70,14);
            gotoxy(30,14);
            if(selection > result) {
                std::cout << "Giảm số xuống đi bạn ơi ! " << std::endl;
            }
            if(selection < result) {
                std::cout << "Tăng số lên đi bạn ! " << std::endl;
            }
        }
        win_lose = false;
    }
    bonus(7 - count);
}

void guess_number::notification() {
    gotoxy(30,21);
    if(win_lose) {
        std::cout << "Bạn đã thắng ở lần chọn thứ " << count << std::endl;
    }
    else {
        std::cout << "Bạn đã thua !" << std::endl;
    }
}

void guess_number::control() {
    createBorder();
    setName("Con số may mắn ! ");
    getName();
    setVersion("Beta 1.0");
    getVersion();
    show_money();
    bet();
    refreshMoney;
    show_money();
    set_result();
    set_Selection();
    get_result();
    notification();
    updateMoney();
    refreshMoney;
    show_money();
    gotoMenu();
}
