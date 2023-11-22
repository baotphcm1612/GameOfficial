#include "devided.hpp"
#include "menu.hpp"

void devided::set_Selection() {
    gotoxy(30,12);
    if(language == 1)
        std::cout << "Nhập số bạn muốn chọn: " << std::endl;
    else std::cout << "Enter the number you choose: " << std::endl;

    gotoxy(30,13);
    std::cout << "| 2  :  3  :  5  :  7  :  9 |  : ";
    std::cin >> selection;
}

void devided::get_Selection() {
    gotoxy(30,15);
    switch (selection) 
    {
    case 2:
        if(language == 1)
            std::cout << "Bạn đã chọn 2 ! " << std::endl;
        else std::cout << "You chosen 2 ! " << std::endl;
        break;
    case 3:
        if(language == 1)
            std::cout << "Bạn đã chọn 3 ! " << std::endl;
        else std::cout << "You chosen 3 ! " << std::endl;
        break;
    case 5:
        if(language == 1)
            std::cout << "Bạn đã chọn 5 ! " << std::endl;
        else std::cout << "You chosen 5 ! " << std::endl;
        break;
    case 7:
        if(language == 1)
            std::cout << "Bạn đã chọn 7 ! " << std::endl;
        else std::cout << "You chosen 7 ! " << std::endl;
        break;
    case 9:
        if(language == 1)
            std::cout << "Bạn đã chọn 7 ! " << std::endl;
        else std::cout << "You chosen 9 ! " << std::endl;
        break;
    default:
        if(language == 1)
            std::cout << "Bạn đã chọn bậy và mất điểm nhé !" << std::endl;
        else std::cout << "You have chosen wrongly and lost points!" << std::endl;
        break;
    }
}

void devided::set_result() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> ran(1,1000);
    result = ran(gen);
}

void devided::get_result() {
    gotoxy(50,18);
    if(language == 1)
        std::cout << "Kết quả là số: " << result << std::endl;
    else std::cout << "Result: " << result << std::endl;
}

void devided::notification() {
    gotoxy(30,21);
    if(selection != 2 && selection != 3 && selection != 5 && selection != 7 && selection != 9) {
        win_lose = false;
        if(language == 1)
            std::cout << "Bạn đã thua do chọn sai số!" << std::endl;
        else std::cout << "You lost because you chose the wrong number!" << std::endl;
    }
    else if(selection == 2 && result % 2 == 0) {
        win_lose = true;
        if(language == 1)
            std::cout << "Bạn đã thắng !" << std::endl;
        else std::cout << "You won !" << std::endl;
    }
    else {
        if((result % 3 == 0 && result % 5 == 0) && (selection == 3 || selection == 5)) {
            win_lose = false;
            if(language == 1)
                std::cout << "Bạn đã thua do số này chia hết cho cả 3 và 5 !" << std::endl;
            else std::cout << "You lost because this number is divisible by both 3 and 5 !" << std::endl;
            
        }
        else if((result % 3 == 0 && result % 7 == 0) && (selection == 3 || selection == 7)) {
            win_lose = false;
            if(language == 1)
                std::cout << "Bạn đã thua do số này chia hết cho cả 3 và 7 !" << std::endl;
            else std::cout << "You lost because this number is divisible by both 3 and 7 !" << std::endl;
            
        }
        else if((result % 3 == 0 && result % 9 == 0) && (selection == 3 || selection == 9)) {
            win_lose = false;
            if(language == 1)
                std::cout << "Bạn đã thua do số này chia hết cho cả 3 và 9 !" << std::endl;
            else std::cout << "You lost because this number is divisible by both 3 and 9 !" << std::endl;
            
        }
        else if((result % 5 == 0 && result % 7 == 0) && (selection == 5 || selection == 7)) {
            win_lose = false;
            if(language == 1)
                std::cout << "Bạn đã thua do số này chia hết cho cả 5 và 7 !" << std::endl;
            else std::cout << "You lost because this number is divisible by both 5 and 7 !" << std::endl;
            
        }
        else if((result % 5 == 0 && result % 9 == 0) && (selection == 5 || selection == 9)) {
            win_lose = false;
            if(language == 1)
                std::cout << "Bạn đã thua do số này chia hết cho cả 5 và 9 !" << std::endl;
            else std::cout << "You lost because this number is divisible by both 5 and 9 !" << std::endl;
        }
        else if((result % 7 == 0 && result % 9 == 0) && (selection == 7 || selection == 9)) {
            win_lose = false;
            if(language == 1)
                std::cout << "Bạn đã thua do số này chia hết cho cả 7 và 9 !" << std::endl;
            else std::cout << "You lost because this number is divisible by both 7 and 9 !" << std::endl;
        }
        else if(result % 3 == 0 && selection == 3) {
            bonus(4);
            win_lose = true;
            if(language == 1)
                std::cout << "Bạn đã thắng !" << std::endl;
            else std::cout << "You won !" << std::endl;
        }
        else if(result % 5 == 0 && selection == 5) {
            bonus(6);
            win_lose = true;
            if(language == 1)
                std::cout << "Bạn đã thắng !" << std::endl;
            else std::cout << "You won !" << std::endl;
        }
        else if(result % 7 == 0 && selection == 7) {
            bonus(8);
            win_lose = true;
            if(language == 1)
                std::cout << "Bạn đã thắng !" << std::endl;
            else std::cout << "You won !" << std::endl;
        }
        else if(result % 9 == 0 && selection == 9) {
            bonus(9);
            win_lose = true;
            if(language == 1)
                std::cout << "Bạn đã thắng !" << std::endl;
            else std::cout << "You won !" << std::endl;
        }
        else {
            win_lose = false;
            if(language == 1)
                std::cout << "Bạn đã thua do xui xẻo ! " << std::endl;
            else std::cout << "You lose due to bad luck !" << std::endl;
        }
    }
}

void devided::control() {
    createBorder();

    if(language == 1)
        setName("Số chia may mắn ");
    else setName("Luckily divisor");

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