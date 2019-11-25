#include "StackLinked.h"

StackLinked::StackLinked() {
	top = NULL;
	count = 0;
	postfix = "";
}
StackLinked::~StackLinked( ) {
	for(node * tmp = top; tmp != NULL; top = top->link) {
		delete tmp;
		tmp = NULL;
	}
	top = NULL;
}
void StackLinked::push(char value) {
	node *newNode = new node(value);
	if(isEmpty()) {
		top = newNode;
	} else {
		newNode->link = top;
		top = newNode;
	}
	count++;
}
char StackLinked::pop() {
	if(!isEmpty()) {
		char data = top->data;
		node *temp = top;
		top = temp->link;
		delete temp;
		count--;
		return data;
	}
}

bool StackLinked::isEmpty() {
	if(count == 0) {
		return true;
	} else {
		return false;
	}
}
bool StackLinked::checkOperation(char infix) {
	if(infix=='+'||infix=='-'||infix=='*'||infix=='/'||infix=='^'||infix=='('||infix==')') {
		return true;
	} else {
		return false;
	}
}
int StackLinked::checkImportance(char infix,string type) {
	if(type == "out") {
		if(infix=='-') {
			return 1;
		}
		if(infix=='+') {
			return 1;
		}
		if(infix=='/') {
			return 3;
		}
		if(infix=='*') {
			return 3;
		}
		if(infix=='^') {
			return 6;
		}
		if(infix=='(') {
			return 7;
		}
	}else if(type == "in"){
		if(infix=='-') {
			return 2;
		}
		if(infix=='+') {
			return 2;
		}
		if(infix=='/') {
			return 4;
		}
		if(infix=='*') {
			return 4;
		}
		if(infix=='^') {
			return 5;
		}
		if(infix=='(') {
			return 0;
		}
	}
}

bool StackLinked::checkStack(char infix1,char infix2) {
	if(checkImportance(infix1,"out") < checkImportance(infix2,"in")) {
		return true;
	} else {
		return false;
	}
}

void StackLinked::infixtoPostfix(string infix) {
	postfix = "";
	for(int i=0; i<infix.length(); i++) {
		if(checkOperation(infix[i])) {
			if(infix[i]=='(') {
				push(infix[i]);
			} else if(infix[i]==')') {
				while(!isEmpty() && top->data != '(') {
					postfix += pop();
				}
				pop();
			} else {
				while(!isEmpty() && checkStack(infix[i],top->data)) {
					postfix += pop();
				}
				push(infix[i]);
			}
		} else {
			postfix += infix[i];
		}
	}
	while(!isEmpty()) {
		postfix += pop();
	}
	cout << " Postfix : " << postfix << endl;
}

