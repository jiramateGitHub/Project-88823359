#include "StackLinked.h"
int main() {
	int choice = 0;
	string infix;
	StackLinked obj;
	do {
		cout << "=========== MENU ===========" << endl;
		cout << "\t1.Infix To Postfix" <<endl;
		cout << "\t0.Exit" <<endl;
		cout << "============================" << endl;
		cout << " Please choose menu: " ;
		cin >> choice;
		if(choice == 1) {
			cout << "Input number : ";
			cin >> infix;
			obj.infixtoPostfix(infix);
		}
	} while(choice!=0);
	return 0;
}
