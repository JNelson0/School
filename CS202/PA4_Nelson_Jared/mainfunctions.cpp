#include<iostream>
#include "mainfunctions.h"
using namespace std;

	//COPIES STRING FROM SOURCE TO DESTINATION
	char *myStringCopy(char * destination, const char * source) {
    	while (*source != '\0'){
			*destination = *source;
			source++;
			destination++;
			}
    	return destination;
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

//COPIES STRING FROM SOURCE TO DESTINATION
	void StringCopy(char *destination, char *source){

	while (*source != '\0'){
	*destination = *source;
	source++;
	destination++;
	}
	}

