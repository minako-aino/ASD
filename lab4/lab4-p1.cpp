// part 1 - array (ring queue)
#include <conio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;
 
string * add_el(string *arr, int size) {
	string value;
    int size_tmp = size + 1;
    
	string *tmp = new string[size_tmp];
    for (int i = 0; i < size; i++) {
    	// copy data from the old array
        tmp[i] = arr[i];
    }
    
	cout << "Enter the value\n";
    cin >> value;
    // add new element
    tmp[size] = value; 
    // clean memory
    
	delete[] arr;
	return tmp;
} 
 
int main() {
    int size;
    int answ;
	char ch;
    string s;
    
    cout << "How many elements do you want to have?\n";
    cin >> size;
    string *arr = new string[size];
	cout << "Please fill in your numbers\n";
    for (int i = 0; i < size; i++) {
    	cin >> arr[i];
	}
	do {
		cout << "1. CHECK THE STATUS\n2. DELETE ELEMENT\n3. ADD NEW\n0. QUIT\n" << "\nENTER > ";
		cin >> answ;
		switch(answ){
			case 1: {
				for (int i = 0 ; i < size; i++) cout << arr[i] << "\n";
				break; }
			case 2: {
				//rotate(&arr[0], &arr[1], &arr[size-1]);
				
 				const string temp = arr[0];
 				for(int i = 1; i < size; i++) arr[i-1] = arr[i];
 				arr[size-1] = temp;
				for (int i = 0 ; i < size ; i++) cout << arr[i] << "\n";
				break;
				
				/*int tmp;
				s = arr[0];
				tmp = size-1;               
        		for (int i=0; i < tmp; i++) arr[i]=arr[i+1];
        		arr[tmp] = s;
        		for (int i = 0 ; i < size ; i++) cout << arr[i] << "\n";
				break;*/
			}
			case 3:{
				arr = add_el(arr, size);
				cout << "Result: \n";
				size++;
				for (int i = 0 ; i < size ; i++) cout << arr[i] << "\n";
				break;
			}
		}
	} while (answ != 0);
	
	system("pause");
    return 0;
}
