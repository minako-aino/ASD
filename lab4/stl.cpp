#include <iostream>
#include <stack> 
#include <queue>  
                 
using namespace std;
 
int quantity;
int answ;
string value; 
 
void showstack(stack <string> st) {
    cout << "Your stack:\n";
	while (!st.empty()) {
        cout << st.top() << "\t" ;
        st.pop();
    }
    cout << "\n";
} 
 
void stack_stl() {
	stack <string> st;
 
	cout << "How many values do you want to have?\n";
	cin >> quantity;
	cout << "Please enter your values:\n"; 
	for (int i = 0; i < quantity; i++) {
		cin >> value; 
 		st.push(value);
  	}
  	showstack(st);
  	
  	do{
  		cout << "What do you want to do with your stack?" << endl << "1. DELETE ELEMENT\n2. ADD NEW ELEMENT\n3. SHOW CURRENT STATUS\n0. QUIT\n" << "ENTER > ";
  		cin >> answ;
		switch(answ) {
  			case 1:{
				if(!st.empty()) {
					cout << "First el: " << st.top() << endl;
					st.pop();
					cout << "Deleted\n";
					if(!st.empty()) cout << "New first: " << st.top() << endl; 
				} else cout << "Stack is empty!\n"; 
				break; }
			case 2: {
				cin >> value;
				st.push(value);
				showstack(st);
				break; }
			case 3: {
				showstack(st);
				break; }
			case 0: break;
			default: cout << "Wrong command";
		}
	} while (answ != 0);

	system("pause");
}

void queue_stl(){
   	queue<string> q; 
 	
	cout << "How many values do you want to have?\n";
	cin >> quantity;
	cout << "Please enter your values:\n"; 
	for (int i = 0; i < quantity; i++) {
		cin >> value; 
 		q.push(value);
  	}
	do{
  		cout << "What do you want to do with your stack?" << endl << "1. DELETE ELEMENT\n2. ADD NEW ELEMENT\n3. SHOW CURRENT STATUS\n0. QUIT\n" << "ENTER > ";
  		cin >> answ;
		switch(answ) {
  			case 1:{
				q.pop();
				cout << "New first: " << q.front() << endl; 
				break; }
			case 2: {
				cin >> value;
				q.push(value);
				cout << "New last: " << q.back() << endl;
				break; }
			case 3: {
				if (!q.empty()) {
        			cout << "First:  " << q.front() << endl;
        			cout << "Last:  " << q.back() << endl;
        			cout << "Size: " << q.size() << endl;
      			} else cout << "Queue is empty!\n";
      			break;}
			case 0: break;
			default: cout << "Wrong command";
		}
	} while (answ != 0);
}

int main(){
	cout << "Choose your option:\n1 - Stack\n2 - Queue\n\nENTER > ";
	cin >> answ;
	switch(answ) {
		case 1:{
			stack_stl();
			break; }
		case 2:{
			queue_stl();
			break; }
		default: cout << "Wrong command";}
	return 0;
}
