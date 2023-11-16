#pragma once
#include "game.h"

class guess_number : public game {
    private:
        int result;
        int selection;
        static int count;
    public:
        void set_Selection();
        void set_result();
        void get_result();
        void control();
        void notification();
};