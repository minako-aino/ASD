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

int Queue::size_get(){
	return size;
}

void Queue::size_set(int x){
	size = x;
}

Queue::~Queue() {
     while (first) {
         last = first->next;             
         delete first;                   
         first = last;                   
     }
 }

bool Queue::is_empty() {
	if (size==0) return true;
    else return false;
}

int Queue::show_first() {
    return first->data;
}

void Queue::add_el() {
    int value;
    if(is_empty() == true){
    	cout << "\nValue > "; 
    	first = new Node;
    	cin >> value;
    	first->data = value;
    	first->next = NULL;
    	last = first;
		cout << "\nIt was added\n\n";  
    	size = 1;
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
		}} while (number != '0');
    
	system("pause");
  return 0;
}
