#include "QuaternionTest.h"

QuaterionTest::QuaterionTest(){//no rotation
    x=0.0;
    y=0.0;
    z=0.0;
    w=0.0;
}

QuaterionTest::QuaterionTest(float x_, float y_, float z_, float w_){
    x = x_;
    y = y_;
    z = z_;
    w = w_;
}

float QuaterionTest::getX()        {return x;}
void QuaterionTest::setX(float x_) {x = x_;}

float QuaterionTest::getY()        {return y;}
void QuaterionTest::setY(float y_) {y = y_;}

float QuaterionTest::getZ()        {return z;}
void QuaterionTest::setZ(float z_) {z = z_;}

float QuaterionTest::getW()        {return w;}
void QuaterionTest::setW(float w_) {w = w_;}

float QuaterionTest::getMagnitude(){
    return sqrt(x*x + y*y + z*z + w*w);
}