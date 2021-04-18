// part 2 - list
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	int size;
	int answ;
	int data;
	int head;
	int tail;
	int current;
	
	cout << "How many elements do you want to have?\n";
    cin >> size;
	int *arr = new int[size];
    head = tail = 0;
    do {
    	cout << "1. CHECK THE STATUS\n2. DELETE ELEMENT\n3. ADD NEW\n0. QUIT\n" << "\nENTER > ";
    	cin >> answ;
    	switch(answ){
    		case 1: {
    			if (head == 0 & tail == 0 ) {
    				cout << "Queue is empty!\n";
				} else {
    				current = head;
      				cout << "Queue: ";
      				while (current != tail) {
      					// виведення даних
				        cout << arr[current++] << " ";
				        // обнулення лічильника
        				if (current > size) current = 0;
      				}
      				cout << endl;
			    	if (abs(tail - head) == size) cout << "Queue is full!" << endl;
				}
				break; }
			
			case 2 : {
				// перевірка на пустоту
				if (head != tail) {
					// виведення даних
      				cout << "Deleted " << arr[head++] << endl; 
      				// обнулення лічильника
      				if (head > size) head = 0; 
    			} else cout << "Queue is empty!" << endl;
				break; }
			
			case 3: {
				// перевірка на заповненість
				if (abs(tail - head) != size) {
					cout << "ENTER > ";
					cin >> data;
					// додавання в кінець
      				arr[tail++] = data; 
      				// обнуління лічильника
      				if (tail > size) tail = 0;
    			} else cout << "Queue is full!" << endl;
				break; }
		}
	} while (answ != 0);
	
	// очищення пам'яті
	delete[] arr;
	return 0;
}
