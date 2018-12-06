

#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>





	class Vehicle{
		
		friend std::ostream & operator<<(std::ostream & os, Vehicle & vehicle);
			
		protected:
		float m_lla[3];	
		const int m_vin;

		private:
		static int s_idgen;
		
		public:
		//CONSTRUCTORS
		Vehicle();
		Vehicle(const int vin, float *lla);
		Vehicle(Vehicle &vehicle);
		//DESTRUCTOR
		~Vehicle();
		//SETTERS
		void set_lla(int latitude, int longitude, int altitude);
		void set_lla(float *lla);
		void set_vin(int vin);
		void move(float *lla);
		//GETTERS
		float get_lla();
		int get_vin() const;
		static int getIdgen();

		//CHECK VIN
		static bool validate_vin(const int vin);

		//OPERATOR OVERLOADER		
		Vehicle &operator=(Vehicle &veh);

		
	};



#endif
