#pragma once
#include "game.hpp"

class devided : public game {
    private:
        int selection;
        int result;
    public:
        void set_Selection();
        void get_Selection();
        void set_result();
        void get_result();
        void notification();
        void control();
};