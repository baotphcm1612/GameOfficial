#include "game.h"

int language;

long long int game::money = 100000000;
long long int game::money_bet = 0;
long long int game::reward = 0;

void game::setName(std::string name) {
    this->name = name;
}

void game::setVersion(std::string version) {
    this->version = version;
}

void game::getName() {
    gotoxy(46,5);
    textcolor(10);
    std::cout << "Game: " << name << std::endl;
}

void game::getVersion() {
    gotoxy(20,7);
    textcolor(10);
    std::cout << "Version: " << version << std::endl;
}

void game::bet() {
    money_bet = 0;
    textcolor(7);
    gotoxy(15,8);
    if(language == 1)
        std::cout << "Nhập số điểm cược: ";
    else std::cout << "Enter the number of points to bet: ";
    std::cin >> money_bet;
    if(money_bet > money) {
        money_bet = 0;
        gotoxy(15,10);
        if(language == 1)
            std::cout << "Bạn không đủ điểm cược ! Không được thưởng dù thắng !" << std::endl;
        else std::cout << "You don't have enough betting points! No reward even if you win! " << std::endl;
    }
    else {
        money -= money_bet;
        gotoxy(15,10);
        if(language == 1)
            std::cout << "Cược thành công !" << std::endl;
        else std::cout << "Successful bet !" << std::endl;
    }
}

void game::show_money() {
    if(money >= 70000000) textcolor(10);
    else if(money >= 20000000) textcolor(14);
    else textcolor(12);
    gotoxy(65,7);
    if(language == 1)
        std::cout << "Số điểm hiện tại bạn có là: " << money;
    else std::cout << "Available points: " << money;
    textcolor(7);
}

void game::updateMoney() {
    if(win_lose) {
        money += money_bet + money_bet * 0.9 + reward;
        money_bet = 0;
    }
    money_bet = 0;
}

void game::bonus(int set) {
    reward = set * money_bet;
}

void game::cheatMoney() {
    money += 100000000;
}
