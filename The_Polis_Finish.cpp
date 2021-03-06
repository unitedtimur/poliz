/*
*
*Created by UnitedTimur (c)
*
*/

#define _crt_secure_no_warnings
#include <iostream>

using namespace std;

void error();
bool operation(char operation);
unsigned int priority(char priority);

struct iden {

	char key;

	iden * next;

};
struct stack {

	iden * head;

	stack() : head(0) {}

	void push(char k) {

		iden * p = new iden;

		p->key = k; 
		
		p->next = head;

		head = p;

	}

	char pop() {

		iden * p = head;

		char k = head->key;

		head = head->next;

		delete p;

		return k;

	}

	void print() {

		iden * p;

		for (p = head; p != nullptr; p = p->next) {

			cout << p->key << " ";

		}

	}

	void delete_s() {

		iden * p;

		while (head) {

			p = head;

			head = head->next;

			delete p;

		}
	}

	void delete_head() {

		iden * p = head;

		head = head->next;

		delete p;

	}

	char top() {

		char k;

		if (head) {

			k = head->key;

			return k;

		}

	}

	bool empty() {

		return head == 0 ? true : false;

	}

};
struct iden_double {

	double key;

	iden_double * next;

};
struct stack_double{

	iden_double * head;

	stack_double() : head(0) {}

	void push(double k) {

		iden_double *p = new iden_double;

		p->key = k; p->next = head;

		head = p;

	}

	double pop() {

		iden_double * p = head;

		double k;
		
		k = head->key;

		head = head->next;

		delete p;

		return k;

	}

	void print() {

		iden_double * p;

		for (p = head; p != nullptr; p = p->next) {

			cout << p->key << " ";

		}

	}

	void delete_s() {

		iden_double * p;

		while (head) {

			p = head;

			head = head->next;

			delete p;

		}
	}

	void delete_head() {

		iden_double * p = head;

		head = head->next;

		delete p;

	}

	double top() {

		double k;

		if (head) {

			k = head->key;

			return k;

		}

	}

	bool empty() {

		return head == 0 ? true : false;

	}


};

int main(void) {

	char string[100] = {};
	char polis[100] = {};

	stack *st = new stack;
	stack_double *st_db = new stack_double;

	unsigned int length = 0;
	unsigned int bracket = 0;
	unsigned int use = 0;

	unsigned int prior_first = 0;
	unsigned int prior_second = 0;

	cout << "You have to write a string, which I must to transform in polis." << endl;
	gets_s(string);

	for (int i = 0; string[i]; i++) {
	
		if (operation(string[i])) {
			//how many brackets in expression
			if (priority(string[i]) == 0) {

				st->push(string[i]);
				bracket++;

			}
			else {
				//check for correctness
				if (priority(string[i]) == 1) {
					if (bracket != 0) {

						bracket--;

						while (!st->empty() && (st->top() == '(')) {

							polis[length] = st->pop();
							length++;

						}

						st->pop();

					}
					else error();
				}
				else {

					if (use != 1) error();

					use = 2;

					prior_first = priority(string[i]);
					prior_second = priority(st->top());

					while (!st->empty() && prior_first <= prior_second) {

						polis[length] = st->pop();
						length++;
						
						prior_second = priority(st->top());

					}
					st->push(string[i]);

				}
			}
		}
		else {

			if (use == 1) error();
			
			use = 1;

			polis[length] = string[i];
			length++;


		}

	}

	while (!st->empty() && (st->top() != '(')) {

		polis[length] = st->pop();
		length++;

	}

	for (int i = 0; polis[i]; i++) cout << polis[i];

	use = 0;

	for (int i = 0; polis[i]; i++) {

		if (!operation(polis[i])) use++;
		else {

			if (use < 2) error();
			use--;

		}

	}

	cout << endl;

	double first = 0;
	double second = 0;
	double result = 0;

	for (int i = 0; polis[i]; i++) {

		if (!operation(polis[i])) {

			cout << "Enter the value " << polis[i] << " = ";
			cin >> first;
			st_db->push(first);
		}
		else {

			if (polis[i] == '+') {

				first = st_db->pop();
				second = st_db->pop();
				result = first + second;

			}

			if (polis[i] == '-') {

				first = st_db->pop();
				second = st_db->pop();
				result = second - first;

			}

			if (polis[i] == '*') {

				first = st_db->pop();
				second = st_db->pop();
				result = first * second;

			}

			if (polis[i] == '/') {

				first = st_db->pop();
				second = st_db->pop();

				result = second / first;

			}

			st_db->push(result);

		}


	}


	result = st_db->pop();

	cout << "Answer = " << result << endl;

	system("pause");
}

bool operation(char operation) {

	if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '(' || operation == ')')
		return true;
	return false;

}
unsigned int priority(char priority) {

	int value = 0;

	switch (priority) {
	case '+': {

		value = 2;
		break;

	}
	case '-': {

		value = 2;
		break;

	}
	case '*': {

		value = 3;
		break;

	}
	case '/': {

		value = 3;
		break;

	}
	case'(': {

		value = 0;
		break;

	}
	case ')': {

		value = 1;
		break;

	}
	}
	return value;

}
void error() {

	system("cls");
	cout << "Error. Try again ;(" << endl;
	system("pause");
	exit(-1);

}