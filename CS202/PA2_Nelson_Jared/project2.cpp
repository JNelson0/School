//JARED NELSON
//CS202
//PROJECT 2
#include <iostream>
#include <fstream>

using namespace std;
	struct RentalCar {
		int year;
		char make[10];
		char model[10];
		float price;
		bool available;} RentalCar[25];
	
	size_t myStringLength (const char *str);
	int myStringCompare(const char *str1, const char *str2);
	char *myStringCopy(char *destination, char *source);
	char *StrSwap(char *str1, char *str2);
	char *myStringCat(char *destination, char *source);



int main(){
	ifstream car;
	ofstream carout;
	char file_name[20], output_file[20];
	int i = 0, menu, days, car_choice, days_rented;
	
	std::cout << std::boolalpha;
	while(menu != 7){
		cout << "User Menu: " << endl;
		cout << "1. Enter Input File" << endl;
		cout << "2. Print Car Data" << endl;
		cout << "3. Transfer Car Data To Desired File" << endl;
		cout << "4. Sort Car Data" << endl;
		cout << "5. Find An Available Car" << endl;
		cout << "6. Choose A Car To Rent" << endl;
		cout << "7. Exit Program" << endl;

		cout << "Please select an option: ";
		cin >> menu;
		cout << "=====================================================" << endl;

	//MENU OPTION ONE TAKES IN TEXT FILE GIVEN BY USER AND USES DATA THROUGHOUT PROGRAM
		if(menu == 1){
			cout << "Enter name of input file: ";
			cin >> file_name;
			cout << "=====================================================" << endl;
			car.open(file_name);
			while(!car.eof()){
			car >> RentalCar[i].year >> RentalCar[i].make >> RentalCar[i].model >> RentalCar[i].price >> RentalCar[i].available;
		i++;
		}
			car.close();
	}
		
	//MENU OPTION 2 PRINTS CAR DATA IN TERMINAL
		if(menu == 2){
			for(int i = 0; i < 5; i++){
				cout << RentalCar[i].year << " ";
				cout << RentalCar[i].make << " ";
				cout << RentalCar[i].model << ", ";
				cout << "$" << RentalCar[i].price << " per day, ";
				cout << "Available: " << RentalCar[i].available << endl;
			}
		cout << "=====================================================" << endl;
		}

	//MENU OPTION 3 WRITES CAR DATA INTO ANOTHER FILE THAT THE USER PROVIDES
		if(menu == 3){
			cout << "Please enter output file name: ";
			cin >> output_file;
			carout.open(output_file);
				for(int i = 0; i < 5; i++){				
					carout << RentalCar[i].year << " " << RentalCar[i].make << " " << RentalCar[i].model << " " << RentalCar[i].price << " " << RentalCar[i].available<< endl;
					}
			carout.close();
		cout << "=====================================================" << endl;
			}
		

	//MENU OPTION 4 SORTING CARS FROM LOWEST PRICE TO HIGHEST
		if(menu == 4){
			for(int i = 0; i < 5; i++){
				for(int j = 0; j < 5; j++){
					if(RentalCar[i].price < RentalCar[j].price){
						RentalCar[6] = RentalCar[i];
						RentalCar[i] = RentalCar[j];
						RentalCar[j] = RentalCar[6];
						}
					}
				}


			}



	//MENU OPTION 5 FINDING AVAILABLE CARS FOR USER

		if(menu == 5){
			cout << "How many will you be renting a car?\n" << "Enter number of days: ";
			cin >> days;
		cout << "=====================================================" << endl;
			cout << "Available Cars:" << endl;
			for(i = 0; i < 5; i++){
				if(RentalCar[i].available == 1){
					cout << RentalCar[i].year << " " << RentalCar[i].make << " " << RentalCar[i].model << ", " << "Total Cost: $" << days*RentalCar[i].price << endl;
					}
				}
		cout << "=====================================================" << endl;



		}

	//MENU OPTION 6 SELECTING RENTED CAR
		if(menu == 6){
			while(1){			
				cout << "Please select the car that you would like to rent (Enter 0 to return to menu): ";
				cin >> car_choice;
	
		cout << "=====================================================" << endl;
				if(car_choice == 0){
					break;}
				if(RentalCar[car_choice-1].available == 0){
					cout << "Car is unavailable to rent! Please choose another car to rent!" << endl;
				}
				if(RentalCar[car_choice-1].available == 1){
					cout << "How many days will you be renting this car for?\n" << "Enter number of days: ";
					cin >> days_rented;
		cout << "=====================================================" << endl;
					cout << RentalCar[car_choice-1].year << " " << RentalCar[car_choice-1].make << " " << RentalCar[car_choice-1].model << " has been successfully rented for " << days_rented << " days.\nTotal price: $" << days_rented*RentalCar[car_choice-1].price << endl;
					RentalCar[car_choice-1].available = 0;
		cout << "=====================================================" << endl;
					break;					
				}
			}
		}
	
}
		
	



return 0;
}

	//COPIES ONE STRING INTO PLACE OF THE OTHER STRING REPLACING IT
	char *myStringCopy(char *destination, char *source){
		int i = 0;

		while(destination[i] != '\0'){
			destination[i] = source[i];
			i++;
			}
		destination[i] = source[i];

		
	}

	

	
	//COMPARES STRINGS AND RETURNS VALUE BASED ON WHICH IS GREATER THAN THE OTHER
	int myStringCompare(const char *str1, const char *str2){
int k = 0;
	while(str1[k] != '\0' || str2[k] != '\0'){	
		if(str1[k] > str2[k]){
			return 1;}
		if(str1[k] < str2[1]){
			return -1;}
		k++;
		}
	return 0;
}


	//SWAPS TWO DIFFERENT STRINGS 
	char *StrSwap(char *str1, char *str2){
	int i, j;
	char temp[10];

		 
					myStringCopy(temp, str1);
					myStringCopy(str1, str2);
					myStringCopy(str2, temp); 
				


}

	//PUTS ONE STRING ONTO END OF ANOTHER
	char *myStringCat(char *destination, const char *source){
		int val1 = 0, val2 = 0;

		while(destination != '\0'){
			destination++;	
			val1++;
			}

		while(source != '\0'){
			destination[val1+1] = source[val2];
			val2++;
			destination++;
			}
		destination = '\0';
		return destination;
}

	//RETURNS VALUE FOR THE LENGTH OF STRING
	size_t myStringLenth(const char *str){
		size_t i = 0;

		while (str != '\0'){
			str++;
			i++;
			}

		return i;
}



