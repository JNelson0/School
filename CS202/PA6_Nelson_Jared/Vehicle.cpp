#include <iostream>
#include "Vehicle.h"
using namespace std;

int lla_size = 3;
//DEFAULT CONSTRUCTOR
Vehicle::Vehicle() {
    std::cout << "Vehicle:Default-ctor" << std::endl;
}

//PARAMETERIZED CONSTRUCTOR
Vehicle::Vehicle(float *lla) {
    std::cout << "Vehicle:Parameterized-ctor" << std::endl;
    SetLLA(lla);
}

//COPY CONSTRUCTOR
Vehicle::Vehicle(Vehicle &v) {
    std::cout << "Vehicle:Copy-ctor" << std::endl;
    SetLLA(v.m_lla);
}

//VIRTUAL DESTRUCTOR
Vehicle::~Vehicle() {
    std::cout << "Vehicle: Dtor" << std::endl;
}

//ASSIGNMENT OPERATOR 
Vehicle &Vehicle::operator=(Vehicle &other) {
   std::cout << "Vehicle: Assignment" << std::endl;
    if (this != &other) {
        SetLLA(other.m_lla);
    }
    return *this;
}

//GETTERS
float *Vehicle::get_lla(){
    return m_lla;
}

//SETTERS
void Vehicle::SetLLA(float *lla) {
    arrayCopy(m_lla, lla, lla_size);
}

//PRINTS DATA
void Vehicle::serialize(std::ostream &os) {
    os << "Vehicle @ [";
    arrayPrint(os, m_lla, lla_size);
    os << "]" << std::endl;
}

//SERIALIZE
std::ostream &operator<<(std::ostream &os, Vehicle &v) {
    v.serialize(os);
    return os;
}

//COPY ARRAY
void arrayCopy(float *dest, float *src, int len) {
    for (int i = 0; i < len; i++) {
        *dest++ = *src++;
    }
}

//PRINT ARRAY
void arrayPrint(std::ostream &os, float *arr, int len) {
    for (int i = 0; i < len; i++) {
        os << arr[i];

        
        if (i != len -1) {
            os << ", ";
        }
    }
}
