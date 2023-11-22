#pragma once
#include "game.hpp"

class big_small : public game {
    private:
        int selection;
        int result[3];
        int sum();
    public:
        void set_Selection();
        void get_Selection();
        void set_result();
        void get_result();
        void notification();
        void control();
};