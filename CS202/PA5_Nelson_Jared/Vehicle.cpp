#include "Vehicle.h"
#include <iostream>

using namespace std;

		int Vehicle::s_idgen = 0;

		Vehicle::Vehicle() : m_vin(s_idgen++){
    std::cout << "Vehicle #" << m_vin << ": Default-ctor" << std::endl;
	}


		Vehicle::Vehicle(const int vin, float *lla) : m_vin(validate_vin(vin) ? vin : s_idgen++){
    	std::cout << "Vehicle #" << m_vin << ": Parameterized-ctor" << std::endl;
   		set_lla(lla);
 	}

	
		Vehicle::Vehicle(Vehicle &vehicle) : m_vin(s_idgen++){
    		std::cout << "Vehicle #" << m_vin << ": Copy-ctor" << std::endl;
    		set_lla(vehicle.m_lla);
		}


		Vehicle::~Vehicle(){
    		std::cout << "Vehicle #" << m_vin << ": Dtor" << std::endl;
		}


		Vehicle &Vehicle::operator=(Vehicle &veh){
    		std::cout << "Vehicle #" << m_vin << ": Assignment" << std::endl;
    			if (this != &veh) {
        		set_lla(veh.m_lla);
    			}
    		return *this;
		}

		//GETTERS
		float Vehicle::get_lla(){
   			return *m_lla;
		}


		int Vehicle::get_vin()const{
    		return m_vin;
		}


		int Vehicle::getIdgen(){
    		return s_idgen;
		}

		//VALIDATE VIN
		bool Vehicle::validate_vin(const int vin){
       		if (vin >= s_idgen) {
       			s_idgen = vin;
        		s_idgen++;      
        		return true;
    		}
    		return false;
		}

		//SETTERS
		void Vehicle::set_lla(float *lla){
    		for (int i = 0; i < 3; i++) {
       		m_lla[i] = lla[i];
   			}
		}


		void Vehicle::set_lla(int latitude, int longitude, int altitude){
   			m_lla[0] = latitude;
    		m_lla[1] = longitude;
    		m_lla[2] = altitude;
		}

		//OTHER
		void Vehicle::move(float *lla){
    		std::cout << "Vehicle #" << m_vin << ": CANNOT MOVE - I DON'T KNOW HOW" << std::endl;
		}


		ostream &operator<<(ostream &os, Vehicle &vehicle){
    		os << "Vehicle #" << vehicle.m_vin;
			os << " @ [" << vehicle.m_lla[0];
			os << ", " << vehicle.m_lla[1];
			os << ", " << vehicle.m_lla[2];
			os << "]" << endl;
   			return os;
		}
