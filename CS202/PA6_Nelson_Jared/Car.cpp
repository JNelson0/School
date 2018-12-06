//
#include <iostream>
#include "Car.h"
using namespace std;
int default_throttle = 0;
//DEFAULT CONSTRUCTOR
Car::Car(){
    std::cout << "Car: Default-ctor" << std::endl;
    set_throttle(default_throttle);
}

//PARAMETRIZED CONSTRUCTOR
Car::Car(float *lla) : Vehicle(lla){
    std::cout << "Car: Parameterized-ctor" << std::endl;
    set_throttle(default_throttle);
}

//COPY CONSTRUCTOR
Car::Car(Car &c){
    std::cout << "Car: Copy-ctor" << std::endl;
    set_throttle(c.m_throttle);
    SetLLA(c.get_lla());
}

//VIRTUAL DESTRUCTOR
Car::~Car(){
    std::cout << "Car: Dtor" << std::endl;
}

//ASSIGNMENT OPPERATOR
Car &Car::operator=(Car &other){
    std::cout << "Car: Assignment" << std::endl;
    if (this != &other) {
        SetLLA(other.get_lla());
        set_throttle(other.m_throttle);
    }
    return *this;
}

//GET THROTTLE
int Car::get_throttle(){
    return m_throttle;
}

//SET THROTTLE
void Car::set_throttle(int throttle){
    m_throttle = throttle;
}

//DRIVER
void Car::drive(int throttle){
    set_throttle(throttle);
}

void Car::Move(float *lla){
    std::cout << "Car: DRIVE to destination, with throttle @ 75" << std::endl;
    drive(75);
}




