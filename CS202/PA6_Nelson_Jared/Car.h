//CAR.H CLASS

#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"



class Car : public Vehicle {
	//DECLARE PRIVATE VARIABLES
	private:
    int m_throttle;
	//DECLARE PUBLIC VARIABLES
	public:
    Car();
    Car(float *lla);
    Car(Car &c);

    virtual ~Car();

    Car &operator=(Car &other);
	//GETTERS
    int get_throttle();
	//SETTERS
    void set_throttle(int throttle);

    void drive(int throttle);
    virtual void Move(float *lla);


};


#endif 
