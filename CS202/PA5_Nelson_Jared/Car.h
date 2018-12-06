#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"




	class Car : public Vehicle {

    	friend std::ostream &operator<<(std::ostream &os, Car &car);
		private:
    	char m_plates[256];
    	int m_throttle;

		public:
    	// Constructors
    	Car();
    	Car(char *license, int vin, float *lla);
    	Car(Car &car);
    	//Destructor
    	~Car();
   	 	//Setters
    	void set_plates(char *plates);
    	void set_throttle(int throttle);
   		//Getters
    	char get_plates();
    	int get_throttle();
    	//Operator overload
   		Car &operator=(Car &veh);
    	//Other
    	void drive(int throttle);
    	void move(float *lla);

	};


#endif
