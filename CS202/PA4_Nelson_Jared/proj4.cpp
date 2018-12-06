//JARED NELSON
//CS202
//PROJECT 4
#include<iostream>
#include<fstream>
#include "classes.h"
#include "mainfunctions.h"
using namespace std;

	int print_menu_options();
	


int main(){
int selection;
	std::cout << std::boolalpha;
	ifstream infile;
	ofstream outfile;
	Agency *agency;
	Car *car;
	Sensor *sensor;
char file_name[20], name[256], type[256], make[256], model[256], owner[256];
	
int zipcode = 0, year = 0;
float baseprice = 0, finalprice = 0;
bool available = false;
	
	while(selection != 5){
		selection = print_menu_options();
		switch(selection){
			case 1:
			cout << "Enter name of input file: ";
				cin >> file_name;
			cout << "=====================================================" << endl;
			infile.open(file_name);
		infile >> name >> zipcode;
		agency -> set_name(name);
		agency -> set_zipcode(zipcode);
		for(int i = 0; i < 5; i++){
			infile >> year >> make >> model >> baseprice >>/* type >>*/ available;
			car -> set_year(year);
			car -> set_make(make);
			car -> set_model(model);
			car -> set_baseprice(baseprice);
			car -> set_available(available);
		car++;
			
		//cout << name << " " << zipcode << " " << year << " " << make << " " << model << " " << baseprice << " " << type << " " << available << endl;
		}
			case 2:	//PRINT OUT AGENCY AND CORESPONDING CARS
				cout << agency -> get_name() << " " << agency -> get_zipcode() << endl;
				for(int i = 0; i < 5; i++){
					cout << car -> get_year() << " " << car -> get_make() << " " << car -> get_model() << " , $" << car -> get_baseprice() << " Per Day, Available: " << car -> get_available() << endl; 
				}
			
			case 3:	//PRINT TOTAL NUMBER OF SENSORS ON EACH CAR
				cout << "Total number of gps: " << sensor -> get_gps() << endl;
				cout << "Total number of camera: " << sensor -> get_camera() << endl;
				cout << "Total number of lidar: " << sensor -> get_lidar() << endl;
				cout << "Total number of radar: " << sensor -> get_radar() << endl;
				

			case 4:	//FIND CAR WITH THE LARGEST BASE PRICE
				int large;
				char rent_car;
				//bool rent_y = false;
				large = car -> get_baseprice(); 
				for(int i = 0; i<5; i++){
					if(large < car++ -> get_baseprice()){
						large = car++ -> get_baseprice();
						}}
				cout << "Most expensive car: " << large << endl;
				cout << "Would you like to rent this car? (yes or no): ";
				cin >> rent_car;
				/*if(rent_car == rent_car){
					car -> set_available(rent_y);
				}*/
			case 5:{
				break;
			}
	

		}
	}
return 0;
}


//PRINTS MENU INPUT AND STORES USER CHOICE
	int print_menu_options(){
		int choice;
		cout << "User Menu: " << endl;
		cout << "1. Enter Input File" << endl;
		cout << "2. Print Agency and Car Data" << endl;
		cout << "3. Print Sensor Total" << endl;
		cout << "4. Find Most Expensive Car" << endl;
		cout << "5. Exit Program" << endl;
		
		cout << "Please select an option: ";
		cin >> choice;
		cout << "=====================================================" << endl;
		return choice;		
		}

	
