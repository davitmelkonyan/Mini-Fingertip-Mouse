#ifndef MOTION_H
#define MOTION_H

#include <vector>
#include "QuaternionTest.h"

class Motion{
    private:
        std::vector<QuaterionTest> ourMovement;
    public:
        void init();
        bool compareAxis();
        bool compareRotationAmount();
        bool compareMAgnitude();
};
#endif