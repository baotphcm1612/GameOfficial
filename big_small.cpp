#include "big_small.h"
#include "menu.h"

void big_small::set_Selection() {
    gotoxy(30,12);
    if(language == 1)
        std::cout << "Mời bạn chọn lớn / nhỏ: " << std::endl;
    else std::cout << "Please choose Big / Small" << std::endl;

    gotoxy(30,14);
    if(language == 1)
        std::cout << "1. Lớn (>= 11)           2. Nhỏ (<= 10)  <  1 : 2 > ";
    else std::cout << "1. Big (>= 11)          2. Small (<= 10)  <  1 : 2 >";
    
    std::cin >> selection;
}

void big_small::get_Selection() {
    gotoxy(30,15);
    switch (selection)
    {
    case 1:
        if(language == 1)
            std::cout << "Bạn đã chọn lớn." << std::endl;
        else std::cout << "You have chosen Big. " << std::endl;
        break;
    case 2:
        if(language == 1)
            std::cout << "Bạn đã chọn nhỏ." << std::endl;
        else std::cout << "You have chosen Small. " << std::endl;
        break;
    default:
        if(language == 1)
            std::cout << "Bạn đã chọn bậy và mất điểm nhé !" << std::endl;
        else std::cout << "You have chosen wrongly and lost points!" << std::endl;
        break;
    }
}

void big_small::set_result() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> ran(1,6);
    for(int i = 0; i < 3;i++) {
        result[i] = ran(gen);
    }
}

void big_small::get_result() {
    gotoxy(50,18);
    if(language == 1)
        std::cout << "Kết quả là: ";
    else std::cout << "Result: ";

    for(int i = 0; i < 3;i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

int big_small::sum() {
    int res = 0;
    for(int i = 0; i < 3; i++) {
        res += result[i];
    }
    return res;
}

void big_small::notification() {
    gotoxy(30,21);
    if(sum() <= 10 && selection == 2) {
        if(language == 1)
            std::cout << "Bạn đã thắng" << std::endl;
        else std::cout << "You won !" << std::endl;
        win_lose = true;
    }
    else if(sum() > 10 && selection == 1) {
        if(language == 1)
            std::cout << "Bạn đã thắng" << std::endl;
        else std::cout << "You won !" << std::endl;
        win_lose = true;
    }
    else {
        if(language == 1)
            std::cout << "Bạn đã thua " << std::endl;
        else std::cout << "You lose !" << std::endl;
        win_lose = false;
    }
}

void big_small::control() {
    createBorder();

    if(language == 1)
        setName("Chọn số lớn nhỏ");
    else setName("Sic Bo");

    getName();
    show_money();
    bet();
    refreshMoney;
    show_money();
    set_Selection();
    get_Selection();
    set_result();
    get_result();
    notification();
    updateMoney();
    refreshMoney;
    show_money();
    gotoMenu();
}