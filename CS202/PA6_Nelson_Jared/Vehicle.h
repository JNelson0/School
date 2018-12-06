//VEHICLE.H CLASS

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>



class Vehicle {

    friend std::ostream &operator<<(std::ostream &os, Vehicle &v);
	
	private:
    float m_lla[3];

	public:
    Vehicle();
    Vehicle(float *lla);
    Vehicle(Vehicle &v);

    virtual ~Vehicle();

    Vehicle &operator=(Vehicle &other);

    float *get_lla();
    void SetLLA(float *lla);

    virtual void Move(float *lla) = 0;
    virtual void serialize(std::ostream& os);

	
};


void arrayCopy(float *dest, float *src, int len);
void arrayPrint(std::ostream &os, float * arr, int len);


#endif 
