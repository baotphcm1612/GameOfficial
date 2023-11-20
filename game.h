#pragma once
#include <iostream>
#include <string>
#include <random>
#include "DoHoa.h"
#include "language.h"

#define refreshMoney clearCharacter(65,105,7)

class game {
    private:
        std::string name;
        static long long int money;
        static long long int money_bet;
        static long long int reward;
    protected:
        static bool win_lose;
        void setName(std::string name);
        void getName();
        static void bet();
        static void show_money();
        static void updateMoney();
        void bonus(int set);
    public:
        static void cheatMoney();
};