#include <iostream>
#include <string.h>
#include "lab4-p1.cpp"
#include "lab4-p2.cpp"

using namespace std;

int main(){
	int answ;
	cout << "Choose your method:\n1 - array (ring queue)\n2 - list\n\n" << "ENTER > ";
	cin >> answ;
	switch(answ){
		case 1: {
			main_1();
			break; }
		case 2: {
			main_2();
			break; }
		default:
			cout << "Wrong command";
	}
	
	return 0;
}
