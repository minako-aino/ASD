#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

char answ;

// chain link
struct Word {
     string text;
	 int size;                        
     Word *Next, *Prev;                 
 };

// creating our list
class List {
     Word *Head, *Tail;
 public:
     List():Head(NULL),Tail(NULL){};    
     ~List();
	 int size = 0;                           
     void Show();                       
     void Add_c(string x);
     void Add_h(string x);
	 void Insert(int position); 
     void Del(int x);
	 void Lab_task(List* lst);
	 int List_size(List* lst);                  
 };

// destructor
List::~List() {
     while (Head)                       
     {
         Tail = Head->Next;             
         delete Head;                   
         Head = Tail;                   
     }
 }

// adding new element to the end
void List::Add_c(string x) {
	// create new el.
	Word * temp = new Word;
	// no next
	temp->Next = 0;
	temp->text = x;
	// previous - ex-tail
	temp->Prev = Tail;
 	
	// if list is not empty
    if (Head != NULL) {
    	// indicate the adress to the previous el.
		temp->Prev = Tail;
		// specify the address of the element following the tail           
    	Tail->Next = temp;
		// change tail adress               
    	Tail = temp;
	// if list is empty                     
   } else {
    	temp->Prev = NULL;               
    	Head = Tail = temp;            
   }				
 
	size++;
}

// adding the first el.
void List::Add_h(string x){
   Word * temp = new Word;
   // no prev
   temp->Prev = 0;
   temp->text = x;
   // next - ex-head
   temp->Next = Head;
	
	//just like it was with Add_c()
	if (Head != NULL) {
		temp->Next = Head;           
    	Head->Prev = temp;     
    	Head = temp;
	// if list is empty                     
    } else {
    	temp->Next = NULL;               
    	Head = Tail = temp;            
    }				
 
    size++;
}

void List::Insert(int position) {
	string data;
	int i = 1;
	
	if (position < 1 || position > size+1) {
    	cout << "Incorrect position\n";
    	return;
	}
	
	cout << "Input new word: ";
    cin >> data;
    // add new tail
    if (position == size+1) {
		Add_c(data);
		return;
	// add new head
    } else if(position == 1) {
		Add_h(data);
		return;
	}
 
	Word * ins = Head;
	
	//count from head n-1 el.
	// reach the element before which the word should be inserted
	while(i < position) {
		ins = ins->Next;
		i++;
	}
	// Get to the element that precedes
	Word * PrevIns = ins->Prev;
	
	Word * temp = new Word;
	temp->text = data;
	
	// if previous el. exists - add address
	if(PrevIns != 0 && size != 1) PrevIns->Next = temp;
 
	temp->Next = ins;
	temp->Prev = PrevIns;
	ins->Prev = temp;
 
   size++;
}

// show elements
void List::Show() {
    // show from the end
    Word *temp=Tail;                   
 
    while (temp != NULL) {
        cout << temp-> text << " ";        
        temp = temp->Prev;             
    }
    cout << "\n";
 
    // show from the beginning
    temp = Head;                       
    while (temp != NULL) {
        cout << temp-> text << " ";        
        temp = temp->Next;            
    }
    cout << "\n"; 
}

// delete element with the needed index
void List::Del(int x){
	// case 1 - we need to delete the first element, but there are a few more
    if ((x == 1) and (Head->Next)){
    	// show that we need the very beginning
        Word *temp = Head;
		// shift the beginning to the next element	                     
        Head = Head->Next;
        // make previous to the first el. empty
        Head->Prev = NULL;
        // remove link
        delete temp;
        size--;		                                
        return ;
	// case 2 - we need to delete the only item in the list		                                
    } else if ((x == 1) and (Head == Tail)) {
    	// reset stuff to zero
        Head->Next = NULL;
        Head = NULL;
        // delete pointer to the first el.
        delete Head;		                           
        size = 0;		                                
        return;			                                
    }
 
	// case 3 - delete the last element
    if (x == size) {
        Word *temp = Tail;
        // push it a bit back
        Tail = Tail->Prev;
        // tell that there nothing further
        Tail->Next = NULL;
		// clean mem	                                
        delete temp;
        size--;		                                   
        return;		                                   
    }
 
 	// case 4 - it is located somewhere between
 	// temp - to be deleted, temp2 - not to lose the data
    Word *temp = Head, *temp2;                       
 
	// find the adress of the element
    for (int i=0; i<x-1; i++) temp = temp->Next;
	
	// temporariry remember the adress of the element
    temp2 = temp;
	// write out that the the next one after the currently deleted element is the next one from the deleted	                               
    temp2->Prev->Next = temp->Next;
    // and previous for next is previous for deleted
    temp2->Next->Prev = temp->Prev;
	// delete the address of the beginning of the deleted element               
    delete temp;      
	size--;                     
}

// just task from lab:)
void List::Lab_task(List* lst) {
	int res = 0;
	Word* first, * current;
	first = Head;
	current = Head;
	
	if (first->Next == nullptr) {
		cout << "Sorry, not enough objects((\n";
	} else {
		cout << "Here is the list of mismatches with the first word:" << endl;
		while (current != NULL) {
			int comp = first->text.compare(current->text);
			if (comp != 0) {
				cout << current->text << " -> ";
				res++;
				if (current->text.size() % 2 == 0) {
					current->text.insert(0, &current->text[0], 0, 1);
				} else {
					if (!current->text.empty()) {
        				current->text.erase(current->text.size() - 1);
    				}
				}
				cout << current->text << endl;	
			}
			current = current->Next;
		}
		if (res == 0 ) {
			cout << "empty" << endl;
		} else if (res < 2) {
			cout << "There are less than 2 mismatches\n";
		}
	}
}

void tasks(char answ, List lst){
	int quantity;
    int position;
    int x;
    char ans;
	string value;
	string str;
	
	switch (answ) {
    	case '1':{
    		cout << "Where your element should be added?\n";
    		cin >> position;
			lst.Insert(position);
			lst.Show();
			break; }
		case '2':{
			lst.Lab_task(&lst);
			break; }
		case '3':{
			lst.Show();
			break; }
		case '4':{
			cout << "Which element do you want to delete?";
			cin >> x;
			lst.Del(x);
			lst.Show();
			break;}
	}
}

// check the memory used
int List::List_size(List* lst) {
    Word* current = Head;
    int size = 0;
    while (current != NULL)
    {
        size = size + sizeof(current->text) + sizeof(current->Next) + sizeof(current->Prev);
        current = current->Next;
    }
    return size;
}

//main for the first method
void main_1(){
	int quantity;
    int position;
    int x;
	string value;
	string str;
	
	List lst; //creating new list
	
	unsigned int start_time =  clock();
	cout << "Do you want to create a list?\n";
	cin >> answ;
	if (answ == 'y' || answ == 'Y'){
		cout << "How many strings do you want to have?\n";
    	cin >> quantity;
    	cout << "Please enter your values:\n";
		for (int i = 0; i < quantity; i++){
			cin >> value;
			lst.Add_c(value);
		}
		cout << "List size: " << lst.size << endl;
    	cout << "What do you want to do with your list?\n";
    	cin >> answ;
		tasks(answ, lst);
		int final = lst.List_size(&lst);
		cout << "Used memory size is: " << final << endl;
		unsigned int end_time = clock(); 
    	unsigned int search_time = end_time - start_time;
    	cout << "Time: " << search_time/1000.0 << " s" << endl;
	} else {
		cout << "OK\n";
	}
}

string * create_array(int size){
	string x;
	
    cout << "Enter you strings:\n";
	// memory for the array
    string *arr = new string[size];
    for (int i = 0; i < size; i++) {
        cin >> x;
        arr[i] = x;
    }
    return arr;
}

void lab_task(string* arr, int size){
	int res = 0;
	
	cout << "\nResult:" << endl;
	for (int i = 1; i < size; i++) {
		if (int result = arr[i].compare(arr[0]) != 0 ){
			res++;
		
			if (arr[i].size() % 2 == 0){
				arr[i].insert(0, &arr[i][0], 0, 1);
			} else {
				if(!arr[i].empty()){
					arr[i].erase(arr[i].size() - 1);
				}
			}
		cout << arr[i] << endl;
		}
	}
	
	if(res == 0) {
		cout << "Empty\n";
	} else if (res < 2) {
		cout << "\nThere are less than 2 mismatches";
	}
}

//main for the second method
int main_2() {
	cout << "Do you want to create an array?\n";
	cin >> answ;
	if (answ == 'y' || answ == 'Y'){
		int size;
		
		cout << "Enter size of your array: ";
    	cin >> size;
		string * arr = create_array(size);
		
		lab_task(arr, size);
    	// print
    	cout << "\nArray:\n";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << endl;
		}
		
		int full = 0;
    	for (int i = 0; i < size ; i++){
			full = full + arr[i].size();
		}
    	cout << "\nThe size of memory used: " << full << endl; 
    	
		// clean memory
    	delete [] arr;
	} else {
		cout << "OK";
	}
    return 0;
}

int main () {
    system("CLS");
    
    cout << "Which method do you prefer?\n";
    cin >> answ;
    switch (answ){
    	case '1': {
    		unsigned int start_time =  clock(); 
   			main_1();
    		unsigned int end_time = clock(); 
    		unsigned int search_time = end_time - start_time;
    		cout << "Time: " << search_time/1000.0 << " s" << endl;
			break;
		}
		case '2': {
    		unsigned int start_time =  clock(); 
   			main_2();
    		unsigned int end_time = clock(); 
    		unsigned int search_time = end_time - start_time;
    		cout << "Time: " << search_time/1000.0 << " s" << endl;
			break;
		}
		default: cout << "Smth went wrong\n";	
	}
   
    system("PAUSE");
    return 0;
}
