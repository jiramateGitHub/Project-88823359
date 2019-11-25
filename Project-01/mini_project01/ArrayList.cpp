#include "ArrayList.h"
ArrayList::ArrayList(int size) {
	stu = new Student[size];
	card = new Card[size];
	capacity = size;
	count = 0;
	status = -1;
}
ArrayList::~ArrayList() {
	delete []card;
	delete []stu;
}
void ArrayList::add(int id,string pre,string fn,string ln,string fc,int d,int m,int y) {
	if(!isFull()) {
		stu[count].set_id(id) ;
		stu[count].set_prefix(pre);
		stu[count].set_firstname(fn);
		stu[count].set_lastname(ln);
		stu[count].set_faculty(fc);
		card[count].set_date(d,m,y);
		cout << "->[" << count << "] ID:" << id << " ADD Complete." << endl;
		count++;
	} else {
		cout << "Is Full";
	}
}
void ArrayList::show() {
	cout<<"\n                               Show Student                       "<<endl;
	cout<<"====================================================================================================================="<<endl;
	cout<<"NO.\tID\t\tPrefix \tFirstname\tLastname\tFaculty\t\tDate Issue\tDate Expiration  "<<endl;
	cout<<"====================================================================================================================="<<endl;
	for(int i=0; i<capacity; i++) {
		if(stu[i].get_id() != -1) {
			cout << setw(8) <<left << i+1;
			cout << setw(16) <<left << stu[i].get_id() ;
			cout << setw(8) <<left << stu[i].get_prefix() ;
			cout << setw(16) <<left << stu[i].get_firstname();
			cout << setw(16) <<left << stu[i].get_lastname();
			cout << setw(8) <<left << stu[i].get_faculty();
			card[i].show_dateIs();
			card[i].show_dateExp();
			cout<<endl;
		}
	}
	cout<<"====================================================================================================================="<<endl<<endl;

}
void ArrayList::find(int id) {
	int check = -1;
	for(int i=0; i<capacity; i++) {
		if(stu[i].get_id() == id) {
			check = i;
		}
	}
	if(check != -1) {
		cout <<"\n                           Search Student Info                       "<<endl;
		cout <<"====================================================================================================================="<<endl;
		cout <<"NO.\tID\t\tPrefix \tFirstname\tLastname\tFaculty\tDate Issue\tDate Expiration"<<endl;
		cout <<"====================================================================================================================="<<endl;
		cout << setw(8) <<left << "*";
		cout << setw(16) <<left << stu[check].get_id() ;
		cout << setw(8) <<left << stu[check].get_prefix() ;
		cout << setw(16) <<left << stu[check].get_firstname();
		cout << setw(16) <<left << stu[check].get_lastname();
		cout << setw(8) <<left << stu[check].get_faculty()<<endl;
		cout <<"====================================================================================================================="<<endl<<endl;
		cout << "Do you want to edit the information? [Y|N]: ";
		string yes;
		cin >> yes;
		if(yes == "Y" || yes == "y") {
			status = check;
		} else {
			status = -1;
		}
	} else {
		cout << endl << "-> No Data!!!" << endl;
	}
}
void ArrayList::edit(string pre,string fn,string ln,string fc) {
	stu[status].set_prefix(pre);
	stu[status].set_firstname(fn);
	stu[status].set_lastname(ln);
	stu[status].set_faculty(fc);
	status = -1;
	cout << endl << "-> Edit Complete!!!" << endl;
}
int ArrayList::get_status() {
	return status;
}
bool ArrayList::isFull() {
	if(count == capacity) {
		return true;
	} else {
		return false;
	}
}
