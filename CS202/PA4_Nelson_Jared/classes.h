

#ifndef CLASSES_H
#define ClASSES_H
//#include<iostream>
#include "mainfunctions.h"
//using namespace std;

	const int string_size = 256;
	const float gps_cost = 5.0;
	const float camer_cost = 10.0;
	const float lidar_cost = 15.0;
	const float radar_cost = 20.0;
	const float no_sensor_cost = 0.0;

	class Sensor{
		//DECLARING PRIVATE VARIABLES		
		private:
		char m_type[256];
		float m_extracost;
		int gps_cnt;
		int camera_cnt;
		int lidar_cnt;
		int radar_cnt;
		//DECLARING PUBLIC VARIABLES
		public:
		//CONSTRUCTORS
		Sensor();
		Sensor(char *type, float extracost, int gps, int camera, int lidar, int radar);
		void copy(int sensor);

		//SETTERS
		void set_type(char *type);
		void set_extracost(float extracost);
		

		//RE-SETTERS
		void set_gps(int gps);
		void set_camera(int camera);
		void set_lidar(int lidar);
		void set_radar(int radar);

		//GETTERS
		char get_type();
		float get_extracost();
		int get_gps();
		int get_camera();
		int get_lidar();
		int get_radar();
		
		
	};

	
	class Car{
		private:
		char m_make[256];
		char m_model[256];
		int m_year;
		
		float m_baseprice;
		float m_finalprice;
		bool m_available;
		char m_owner[256];
	
		public:
		Car();
		Car(char *make, char *model, int year, float baseprice, float finalprice, bool available, char *owner);

		//SETTERS
		void set_make(char *make);
		void set_model(char *model);
		void set_year(int year);
		void set_baseprice(float baseprice);
		void set_finalprice(float finalprice);
		void set_available(bool available);
		void set_owner(char *owner);
		
		//GETTERS
		char get_make();
		char get_model();
		int get_year();
		float get_baseprice();
		float get_finalprice();
		bool get_available();
		char get_owner();
		
		//OTHERS
		void estimateCost(int days);
	};





	class Agency{
		private:
		char m_name[256];
		int m_zipcode;
		int m_inventory[5];
		
		public:
		Agency();
		Agency(char *name, int zipcode, int *inventory);
		
		//SETTERS
		void set_name(char *name);
		void set_zipcode(int zipcode);
		
		//GETTERS
		char get_name();
		int get_zipcode();



	};
	


#endif
