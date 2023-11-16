#include "big_small.h"
#include "menu.h"

void big_small::set_Selection() {
    gotoxy(30,12);
    std::cout << "Mời bạn chọn lớn / nhỏ: " << std::endl;
    gotoxy(30,14);
    std::cout << "1. Lớn (>= 11)           2. Nhỏ (<= 10)  <  1 : 2 > ";
    std::cin >> selection;
}

void big_small::get_Selection() {
    gotoxy(30,15);
    switch (selection)
    {
    case 1:
        std::cout << "Bạn đã chọn lớn." << std::endl;
        break;
    case 2:
        std::cout << "Bạn đã chọn nhỏ." << std::endl;
        break;
    default:
        std::cout << "Bạn đã chọn bậy và mất điểm nhé !" << std::endl;
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
    std::cout << "Kết quả là: ";
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
        std::cout << "Bạn đã thắng" << std::endl;
        win_lose = true;
    }
    else if(sum() > 10 && selection == 1) {
        std::cout << "Bạn đã thắng" << std::endl;
        win_lose = true;
    }
    else {
        std::cout << "Bạn đã thua và mất điểm :)) " << std::endl;
        win_lose = false;
    }
}

void big_small::control() {
    createBorder();
    setName("Chọn số lớn nhỏ");
    getName();
    setVersion("Beta 2.0");
    getVersion();
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