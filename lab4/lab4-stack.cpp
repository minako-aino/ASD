#include <iostream>
#include <cstring>

using namespace std;

void push(char *_stack, int &_ptr, char data);
char pop(char *_stack, int &_ptr);

void PostfixNotation(const char *_infix, char *_postfix) {
	// stack for operators
	char stack[100];	
	int st_ptr = 0;
	
	// index in output string
	int out_index = 0;
	// index in input string
	int in_index = 0;

	do {
		// the current symbol in oue string
		char current = _infix[in_index];

		switch (current) {
			case '+':
			case '-': {
				// pop all operators with greater or equal precedence from the stack into the output line
				while (st_ptr != 0) {
					// the first op in stack
					char op = stack[st_ptr-1];
					// all of the ops given (except for '(' ) have equal or greater precedence
					if (op != '(') {
						cout << "Add + or - to the output\n";
						_postfix[out_index++] = op;
						cout << "Delete + or - from stack\n";
						pop(stack, st_ptr);
					}
					else
						break;
				}
				cout << "Add op to stack(+ or -)\n";
				push(stack, st_ptr, c);
				break; }
			case '*':
			case '/': {
				// pop all operators with greater or equal precedence from the stack into the output line
				while (st_ptr != 0) {
					char op = stack[st_ptr-1];
					if ((op == '^') || (op == '*') || (op == '/'))
					{
						cout << "Add * or / to the output\n";
						_postfix[out_index++] = op;	
						cout << "Delete * or / from stack\n";
						pop(stack, st_ptr);			// ??????? ???????? ?? ?????
					}
					else
						break;
				}
				cout << "Add * or / to the stack\n";
				push(stack, st_ptr, c);
				break; }
			case '(': {
				cout << "Put ( to a stack\n";
				push(stack, st_ptr, c);
				break; }
			case ')':
			// pop all the elements before '(' and just drop it
				while (st_ptr != 0) {
					cout << "Take ops from stack\n";
					char op = pop(stack, st_ptr);	
					if (op == '('){
						cout << "Finish popping\n";					
						break;						
					} else {
						cout << "Add op before ( to the output\n";
						_postfix[out_index++] = op;	
					}
				}
				break;
			// if there is a letter/number
			default:
				cout << "Add a letter to the output\n";
				_postfix[out_index] = c;
				out_index++;
				break;
		}
		// move to the next el
		in_index++;	
	} while (_infix[in_index] != 0);

	// pop all the elements to the original string
	while(st_ptr != 0)
		_postfix[out_index++] = pop(stack, st_ptr);

	// end with 0
	_postfix[out_index] = 0;
}


void push(char *_stack, int &_ptr, char data) {
	_stack[_ptr++] = data;
}

char pop(char *_stack, int &_ptr) {
	return _stack[--_ptr];
}


int main() {
	char str_infix[] = "D/(A-B-C)-E*F";
	char str_postfix[100];

	cout << str_infix << endl;

	PostfixNotation(str_infix, str_postfix);
	cout << str_postfix << endl;

	return 0;
}
