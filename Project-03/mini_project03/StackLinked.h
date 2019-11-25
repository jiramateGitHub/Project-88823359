#ifndef STACKLINKED_H
#define STACKLINKED_H
#include <iostream>
#include <string>
using namespace std;
class StackLinked
{
	private:
		class node {
			public:
				char data;
				node *link;
				node(char data) {
					this->data = data;
					link = NULL;
				}
		};
		node *top;
		int count;
		string postfix;
	public:
		StackLinked();
		~StackLinked();
		void push(char value);
		char pop();
		bool isEmpty();
		void infixtoPostfix(string infix);
		int checkImportance(char infix,string type);
		bool checkStack(char infix1,char infix2);
		bool checkOperation(char infix);
};

#endif
