#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "Card.h"
#include "ArrayList.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int size_student=0;
	int choice=0;
	int id=0,d=0,m=0,y=0;
	string pre,fn,ln,fc;
	cout << " Enter the number of students you want to store : ";
	cin >> size_student;
	ArrayList * ary = new ArrayList(size_student);
	do {
		cout << "\n ===================================" << endl;
		cout << "\t\tMENU" << endl;
		cout << "\t1.Add Student Info" << endl;
		cout << "\t2.Search & Edit Student Info"<<endl;
		cout << "\t3.Show All Student Info" << endl;
		cout << "\t0.EXIT" << endl;
		cout << " ===================================" << endl;
		cout << " Please choose menu: " ;
		cin >> choice;
		cout << endl;
		if(choice == 1) {
			cout << " ===================================" << endl;
			cout << "\t Add Student Info" << endl;
			cout << " id : ";
			cin >> id;
			cout << " prefix : ";
			cin >> pre;
			cout << " firstname : ";
			cin >> fn;
			cout << " lastname : ";
			cin >> ln;
			cout << " faculty : ";
			cin >> fc;
			cout << " date [for example] -> 20 14 2018 : ";
			cin >> d;
			
			cin >> m;
			cin >> y;
			ary->add(id,pre,fn,ln,fc,d,m,y);
		}
		if(choice == 2) {
			cout << " Enter Student ID : ";
			cin >> id;
			ary->find(id);
			if(ary->get_status() != -1) {
				cout << " ===================================" << endl;
				cout << "\t Edit Student Info" << endl;
				cout << " id : " << id << endl;
				cout << " prefix : ";
				cin >> pre;
				cout << " firstname : ";
				cin >> fn;
				cout << " lastname : ";
				cin >> ln;
				cout << " faculty : ";
				cin >> fc;
				ary->edit(pre,fn,ln,fc);
			}
		}
		if(choice == 3) {
			ary->show();
		}
	} while(choice != 0);
	return 0;
}
