//JARED NELSON
//CS202
//PROJECT1
#include <iostream>
#include <fstream>
using namespace std;
	
	
	void myStringCopy(char destination[], char source[]);
	
	int myStringCompare(char str1[], char str2[]);

	void myStringSort(char unsorted[][20]);

	void StrSwap(char str1[], char str2[]);
	 
	int myStringLength(char str[][20]);
	
	int StrCompareLength(char str1[][20], char str2[][20]);	

	void myStringSortLength(char unsorted[][20]);



int main(){
	char file_names[50], file_sort_length[50], file_sort_alphabetical[50];
	char unsorted_names[10][20];
	

for(int i = 0; i < 10; i++){
	for(int j = 0; j < 20; j++){
		unsorted_names[i][j] = 0;}}

	cout << "Enter name of file including list of unsorted names: ";
	cin >> file_names;
	
	ifstream names;
	ofstream namesOut;
	names.open(file_names); //OPEN FILE PROVIDED BY CONSOLE
					  
			for(int i = 0; i < 10; i++){				
				names >> unsorted_names[i];
				//cout << destination[i];
				}
			
	names.close(); //CLOSE FILE

	cout << "Names list from requested file: " << file_names << endl;
	cout << "=========================================" << endl;
	for(int i = 0; i < 10; i++){  
		cout << i << " " << unsorted_names[i] << endl;
		}
	cout << "=========================================" << endl;

	//cout << "Enter name of file for list of names sorted by length: ";
	//cin >> file_sort_length;
	
	//cout << "=========================================" << endl;


	
	


	cout << "Enter name of output file for list of names sorted alphabetically: ";
	cin >> file_sort_alphabetical;

	myStringSort(unsorted_names);
	
	cout << "Sorted Alphabetical List" << endl;
	cout << "=========================================" << endl;
	
	for(int i = 0; i < 10; i++){
		cout << i << " " << unsorted_names[i] << endl;}
	
	
	namesOut.open(file_sort_alphabetical); //OPEN OUTPUT FILE
	
	for(int i = 0; i < 10; i++){				
		namesOut << unsorted_names[i] << endl;
		}
	namesOut.close();  //CLOSE OUTPUT FILE

return 0;

}
//COPIES STRINGS INTO DEST ARRAY FROM SOURCE 
void myStringCopy(char destination[], char source[]){
int i = 0;

	while(source[i] != '\0'){
		destination[i] = source [i];
		i++;
		}
	destination[i] = source[i];
}



//COMPARES VALUE OF CHARACTERS
int myStringCompare(char str1[], char str2[]){
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


//SWAPS ARRAY VALUE
void StrSwap(char str1[], char str2[]){
	int i, j;
	char temp[10];

		 
					myStringCopy(temp, str1);
					myStringCopy(str1, str2);
					myStringCopy(str2, temp); 
				


}

//SORTS ALPHABETICALLY
void myStringSort(char unsorted[][20]) {

	bool SWAP = true;

	int k = 0;
	int result = 0;

	while(SWAP) {
		SWAP = false;
		for(int i = 0; i < 9; i++) {
			result = myStringCompare(unsorted[k], unsorted[k+1]);
			if(result == 1) {
				StrSwap(unsorted[k], unsorted[k+1]);
				SWAP = true;
			}
			k++;
		}
		k = 0;
	}
}

//COMPARED STRING LENGTHS
/*int StrCompareLength(char str1[][20], char str2[][20]){
	int val1 = 0, val2 = 0;

	int i = 0, k = 0;
	val1 = myStringLength(str1[k][20]);
	val2 = myStringLength(str2[k][20]);
	
		if(val1 > val2){
			return 1;
			}
		if(val1 < val2){
			return -1;
			}
		
		
	return 0;
}*/
	
	



//COUNTS CHARACTERS IN STRINGS

int myStringLength(char str[][20]){
	
	int k = 0;
	int value = 0, i = 0;
	
	for(i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(str[i][j] != '\0'){
		value += 1;

		i++;
		}}}
		

return value;

}

//SORTS FROM SHORTEST STRINGS TO LONGEST
/*void myStringSortLength(char unsorted[][20]) {

	bool SWAP = true;
	
	int k = 0;
	int result = 0;

	while(SWAP) {
		SWAP = false;
		for(int i = 0; i < 9; i++) {
				result = StrCompareLength(unsorted[k], unsorted[k+1]);
				if(result == 1) {
					StrSwap(unsorted[k], unsorted[k+1]);
					SWAP = true;
				}
				k++;
			}
			k = 0;
		}
}*/

