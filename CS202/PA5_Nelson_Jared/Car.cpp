
#include <cstring>
#include "Car.h"
#include <iostream>
using namespace std;

	Car::Car(){
		std::cout << "Car #" << m_vin << ": Default-ctor" << std::endl;
		m_throttle = 0;
	}


	Car::Car(char *license, int vin, float *lla) : Vehicle(vin, lla) {
		std::cout << "Car #" << m_vin << ": Parameterized-ctor" << std::endl;
		set_plates(license);
	}


	Car::Car(Car &car) : Vehicle(car) {
   		std::cout << "Car #" << m_vin << ": Copy-ctor" << std::endl;
    	set_plates(car.m_plates);
	}

	//DESTRUCTOR
	Car::~Car(){
    	std::cout << "Car #" << m_vin << ": Dtor" << std::endl;
	}


	Car &Car::operator=(Car &veh) {
    	std::cout << "Car #" << m_vin << ": Assignment" << std::endl;
    	if (this != &veh) {
        	set_lla(veh.m_lla);
        	set_plates(veh.m_plates);
   		}
    	return *this;
	}

	//GETTERS
	char Car::get_plates(){
    	return *m_plates;
	}


	int Car::get_throttle(){
    	return m_throttle;
	}

	//SETTERS
	void Car::set_plates(char *plates) {
    	strcpy(m_plates, plates);
	}


	void Car::set_throttle(int throttle) {
   		m_throttle = throttle;
	}


	void Car::drive(int throttle) {
		set_throttle(throttle);
	}

	//OTHER
	void Car::move(float *lla) {
		std::cout << "Car #" << m_vin << ": DRIVE to destination, with throttle @ 75" << std::endl;
		drive(75);
	};


	ostream &operator<<(ostream &os, Car &car) {
		int i = 0;
		os << "Vehicle #" << car.get_vin();
		os << " Plates: " << car.get_plates();
		os << ", Throttle: " << car.get_throttle();
		os << " @ [";
		os << car.get_lla() << "]" << endl;
		
		return os;
	}


