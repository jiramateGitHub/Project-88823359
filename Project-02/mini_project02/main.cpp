#include "LinkedList.h"
using namespace std;
void enter() {
	cout << "Please Enter...";
	while(getchar()!='\n');
	getchar();
}
int main() {
	int choice=0;
	int id=0,d=0,m=0,y=0;
	string pre,fn,ln,fc;
	LinkedList lk;
	do {
		system("clean");
		cout << "\n ===================================" << endl;
		cout << "\t\tMENU" << endl;
		cout << "\t1.Add Student Info" << endl;
		cout << "\t2.Search & Edit Student Info"<<endl;
		cout << "\t3.Remove Student Info"<<endl;
		cout << "\t4.Show All Student Info" << endl;
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
			lk.add(id,pre,fn,ln,fc,d,m,y);
			cout << " -> ID:" << id << " ADD Complete." << endl;
			enter();
		}
		if(choice == 2) {
			cout << " Enter Student ID : ";
			cin >> id;
			lk.find(id);
			if(lk.get_status() != -1) {
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
				lk.edit(pre,fn,ln,fc);
			}
			enter();
		}
		if(choice == 3) {
			cout << " Enter Student ID : ";
			cin >> id;
			lk.remove(id);
			enter();
		}
		if(choice == 4) {
			lk.show();
			enter();
		}
	} while(choice != 0);
	return 0;
}
