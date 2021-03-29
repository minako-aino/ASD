// part 2 - list
#include <iostream>
#include <string.h>

using namespace std;
 
struct Node {
    int data;
    Node *next;
};

class Queue {
	int size;
    Node *first;
    Node *last;
public:
	~Queue();
	int size_get();
	void size_set(int x);
	bool is_empty();
	int show_first();
	void add_el();
	void show_List();
	void creation();
	void delete_el();
};

// getter for size value
int Queue::size_get(){
	return size;
}

// and setter as well
void Queue::size_set(int x){
	size = x;
}

// destructor
Queue::~Queue() {
     while (first) {
         last = first->next;             
         delete first;                   
         first = last;                   
     }
 }

// check whether the list is empty
bool Queue::is_empty() {
	if (size==0) return true;
    else return false;
}

int Queue::show_first() {
    return first->data;
}

// add elements
void Queue::add_el() {
    int value;
    // case 1 - we need to create a new list
    if(is_empty() == true){
    	cout << "\nValue > "; 
    	first = new Node;
    	cin >> value;
    	first->data = value;
    	first->next = NULL;
    	last = first;
		cout << "\nIt was added\n\n";  
    	size = 1;
    // case 2 - we already have the first element
	} else {
		cout << "\nValue > "; 
		cin >> value;
    	last->next = new Node;
    	last = last->next;
    	last->data = value;
    	last->next = NULL; 
    	cout << "\nIt was added\n\n"; 
		size++;}
}
 
void Queue::show_List(){
	struct Node *h;
	if(is_empty() == true) {
    	printf("It is empty!\n");
    	return;
  	}
	for(h = first; h!= NULL; h=h->next)
    	cout << h->data << " ";
}

// delete first element
void Queue::delete_el(){
    Node *curNode = first;
	first = first->next;
    delete curNode;		                                   
}

int main_1() {
    Queue Q;
    Q.size_set(0);
    char number;
    do {
        cout << "\n1. ADD\n2. SHOW CURRENT STATE\n3. DELETE ELEMENT\n0. QUIT\n\n" << endl;
        cout << "Enter > "; 
		cin >> number;
        switch (number) {
		case '1': {
        	Q.add_el();
        	Q.show_List();
            break; }
        case '2': {
			Q.show_List();
            break; }
        case '3':{
        	Q.delete_el();
        	Q.show_List();
			break; }
		case '0': break;
        default: cout << endl << "Wrong command\n\n";
            break;
        }
    } while (number != '0');
    
	system("pause");
    return 0;
}
