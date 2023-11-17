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
    if(language == 1)
        std::cout << "Kết quả là: " << result << std::endl;
    else std::cout << "Result: " << result << std::endl;
}

void guess_number::set_Selection() {
    count = 1;
    for(; count <= 3;count++) {
        gotoxy(30,12);
        if(language == 1)
            std::cout << "Lượt thứ " << count <<" (1 - 20): ";
        else std::cout << "Turn: " << count << "(1 - 20): ";
        std::cin >> selection;
        if(selection == result) {
            clearCharacter(30,70,14);
            gotoxy(30,14);
            if(language == 1)
                std::cout << "Bạn đã thắng !" << std::endl;
            else std::cout << "You won ! " << std::endl;
            win_lose = true;
            bonus(7 - count);
            break;
        }
        else if(count != 3){
            clearCharacter(30,70,12);
            clearCharacter(30,70,14);
            gotoxy(30,14);
            if(selection > result) {
                if(language == 1)
                    std::cout << "Giảm số xuống đi bạn ơi ! " << std::endl;
                else std::cout << "Please decrease the number ! " << std::endl;
            }
            if(selection < result) {
                if(language == 1)
                    std::cout << "Tăng số lên đi bạn ! " << std::endl;
                else std::cout << "Please increase the number !" << std::endl;
            }
        }
        win_lose = false;
    }
    bonus(7 - count);
}

void guess_number::notification() {
    gotoxy(30,21);
    if(win_lose) {
        if(language == 1)
            std::cout << "Bạn đã thắng ở lần chọn thứ " << count << std::endl;
        else std::cout << "You won on turn " << count << std::endl;
    }
    else {
        if(language == 1)
            std::cout << "Bạn đã thua !" << std::endl;
        else std::cout << "You lose !" << std::endl;
    }
}

void guess_number::control() {
    createBorder();
    if(language == 1)
        setName("Con số may mắn ");
    else setName("Guess the number ");
    getName();
    setVersion("1.2");
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
