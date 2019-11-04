#ifndef QUATERNIONTEST_H
#define QUATERNIONTEST_H

#include <cmath>

class QuaterionTest{
    private:
        float x;
        float y;
        float z; //x,y,z represent the axis about which rotation will occur
        float w; //amount of rotation
    public:
        QuaterionTest();
        QuaterionTest(float x_, float y_, float z_, float w_);
        float getX();
        void setX(float newX);

        float getY();
        void setY(float newY);

        float getZ();
        void setZ(float newZ);

        float getW();
        void setW(float newW);

        float getMagnitude();
};
#endif