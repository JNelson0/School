#include<iostream>
#include "classes.h"
using namespace std;




		//CONSTRUCTORS
		Sensor::Sensor(){
			*m_type = '\0';
			m_extracost = 0;
			gps_cnt = 0;
			camera_cnt = 0;
			lidar_cnt = 0;
			radar_cnt = 0;
		}
		//SETTERS
		void Sensor::set_type(char *type){
			StringCopy(m_type, type);
		}
		void Sensor::set_extracost(float extracost){
			m_extracost = extracost;
		}

		//RE-SETTERS		
		void Sensor::set_gps(int gps){
			gps_cnt = gps;
		}
		void Sensor::set_camera(int camera){
			camera_cnt = camera;
		}
		void Sensor::set_lidar(int lidar){
			lidar_cnt = lidar;
		}
		void Sensor::set_radar(int radar){
			radar_cnt = radar;
		}

		//GETTERS
		char Sensor::get_type(){
			return *m_type;
		}
		float Sensor::get_extracost(){
			return m_extracost;
		}
		int Sensor::get_gps(){
			return gps_cnt;
		}
		int Sensor::get_camera(){
			return camera_cnt;
		}
		int Sensor::get_lidar(){
			return lidar_cnt;
		}
		int Sensor::get_radar(){
			return radar_cnt;
		}

		//CONSTRUCTORS
		Car::Car(){
			*m_make = '\0';
			*m_model = '\0';
			m_year = 0;
			m_baseprice = 0;
			m_finalprice = 0;
			m_available = false;
			*m_owner = '\0';
		}
		
		//SETTERS
		void Car::set_make(char *make){
			StringCopy(m_make, make);
		}
		void Car::set_model(char *model){
			StringCopy(m_model, model);
		}
		void Car::set_year(int year){
			m_year = year;
		}
		void Car::set_baseprice(float baseprice){
			m_baseprice = baseprice;
		}
		void Car::set_available(bool available){
			m_available = available;
		}
		
		//GETTERS
		char Car::get_make(){
			return *m_make;
		}
		char Car::get_model(){
			return *m_model;
		}
		int Car::get_year(){
			return m_year;
		}
		float Car::get_baseprice(){
			return m_baseprice;
		}
		bool Car::get_available(){
			return m_available;
		}
		char Car::get_owner(){
			return *m_owner;
		}
		//OTHERS
		void Car::estimateCost(int days){
			m_finalprice = m_baseprice*days;
		}
		
		//CONSTRUCTORS
		Agency::Agency(){
			*m_name = '\0';
			m_zipcode = 0;
			*m_inventory = '\0';
		}
		
		//SETTERS
		void Agency::set_name(char *name){
			StringCopy(m_name, name);
		}
		void Agency::set_zipcode(int zipcode){
			m_zipcode = zipcode;
		}
		
		//GETTERS
		char Agency::get_name(){
			return *m_name;
		}
		int Agency::get_zipcode(){
			return m_zipcode;
		}







