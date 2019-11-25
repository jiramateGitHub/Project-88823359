#include "LinkedList.h"
LinkedList::LinkedList() {
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
	readFile();
}
LinkedList::~LinkedList() {
	saveFile();
	for(int i = 1; i < this->count; i++) {
		node * tmp = this->head;
		this->head = this->head->link;
		delete tmp;
		tmp = NULL;
	}
	this->head = NULL;
	this->tail = NULL;
}
void LinkedList::add(int id,string pre,string fn,string ln,string fc,int d,int m,int y) {
	node * newNode = new node(id,pre,fn,ln,fc,d,m,y);
	if(isEmpty()) {
		head = newNode;
		tail = newNode;
	} else {
		newNode->plink = tail;
		tail->link = newNode;
		tail = newNode;
	}
	count++;
}
void LinkedList::show() {
	cout<<"\n                               Show Student                       "<<endl;
	cout<<"====================================================================================================================="<<endl;
	cout<<"NO.\tID\t\tPrefix \tFirstname\tLastname\tFaculty\t\tDate Issue\tDate Expiration  "<<endl;
	cout<<"====================================================================================================================="<<endl;
	if(isEmpty()) {
		cout << "No Data...";
	} else {
		int i = 1;
		for(node * temp = head; temp != NULL; temp = temp->link) {
			cout << setw(8) <<left << i;
			cout << setw(16) <<left << temp->stu.get_id() ;
			cout << setw(8) <<left << temp->stu.get_prefix() ;
			cout << setw(16) <<left << temp->stu.get_firstname();
			cout << setw(16) <<left << temp->stu.get_lastname();
			cout << setw(16) <<left << temp->stu.get_faculty();
			cout << setw(0) <<left << temp->stu.get_day() << "/" << temp->stu.get_month() << "/" << temp->stu.get_year();
			cout << "\t" <<left << temp->stu.get_day() << "/" << temp->stu.get_month() << "/" << temp->stu.get_year()+4;
			cout<<endl;
			i++;
		}
	}
	cout << endl;
	cout<<"====================================================================================================================="<<endl<<endl;

}
void LinkedList::find(int id) {
	status = -1;
	int check = -1;
	int i = 1;
	for(node * temp = head; temp != NULL; temp = temp->link,i++) {
		if(temp->stu.get_id() == id) {
			check = i;
			cout <<"\n                           Search Student Info                       "<<endl;
			cout <<"====================================================================================================================="<<endl;
			cout <<"NO.\tID\t\tPrefix \tFirstname\tLastname\tFaculty\t\tDate Issue\tDate Expiration  "<<endl;
			cout <<"====================================================================================================================="<<endl;
			cout << setw(8) << left << "*";
			cout << setw(16) << left << temp->stu.get_id() ;
			cout << setw(8) << left << temp->stu.get_prefix() ;
			cout << setw(16) << left << temp->stu.get_firstname();
			cout << setw(16) << left << temp->stu.get_lastname();
			cout << setw(16) << left << temp->stu.get_faculty();
			cout << setw(0) << left << temp->stu.get_day() << "/" << temp->stu.get_month() << "/" << temp->stu.get_year();
			cout << "\t"  << left << temp->stu.get_day() << "/" << temp->stu.get_month() << "/" << temp->stu.get_year()+4;
			cout<<endl;
			break;
		}

	}
	if(check == -1) {
		cout << endl << endl << "-> No Data!!!" << endl;
	} else {
		cout <<"====================================================================================================================="<<endl<<endl;
		cout << "Do you want to edit the information? [Y|N]: ";
		string yes;
		cin >> yes;
		if(yes == "Y" || yes == "y") {
			status = check;
		} else {
			status = -1;
		}
	}
}
void LinkedList::edit(string pre,string fn,string ln,string fc) {
	node * temp = head;
	for(int i=1; i<status; i++) {
		temp = temp->link;
	}
	temp->stu.set_prefix(pre);
	temp->stu.set_firstname(fn);
	temp->stu.set_lastname(ln);
	temp->stu.set_faculty(fc);
	status = -1;
	cout << endl << endl<< "-> Edit Complete!!!" << endl;
}
int LinkedList::get_status() {
	return status;
}
bool LinkedList::isEmpty() {
	if(count == 0) {
		return true;
	} else {
		return false;
	}
}
void LinkedList::readFile() {
	int id,d,m,y;
	string pre,fn,ln,fc;
	ifstream readfile("student.dat");
	while(readfile >> id >> pre >> fn >> ln >> fc >> d >> m >> y) {
		add(id,pre,fn,ln,fc,d,m,y);
	}
	readfile.close();
//	cout << "Read file Complete..." << endl;
}
void LinkedList::saveFile() {
	ofstream file("student.dat");
	for(node * temp = head; temp!=NULL; temp=temp->link) {
		file << temp->stu.get_id() << "\t";
		file << temp->stu.get_prefix() << "\t";
		file << temp->stu.get_firstname() << "\t";
		file << temp->stu.get_lastname() << "\t";
		file << temp->stu.get_faculty() << "\t";
		file << temp->stu.get_day() << "\t";
		file << temp->stu.get_month() << "\t";
		file << temp->stu.get_year() << endl;
	}
	file.close();
//	cout << "Save file Complete..." << endl;
}

void LinkedList::remove(int id) {
	int round = 0;
	int check = 0;
	for(node * temp = head; temp != NULL; temp = temp->link) {
		if(round == 0) {
			if(temp->stu.get_id() == id) {
				if(temp == head && temp == tail) {
					head = NULL;
					tail = NULL;
				} else if(temp == head) {
					head = head->link;
					head->plink = NULL;
				}
				delete temp;
				count--;
				check = 2;
				break;
			}
		} else {
			if(temp->stu.get_id() == id) {
				if(temp == tail) {
					tail = tail->plink;
					tail->link = NULL;
				} else {
					temp->plink->link = temp->link;
					temp->link->plink = temp->plink;
				}
				delete temp;
				count--;
				check = 2;
				break;
			} else {
				check = 1;
			}
		}
		round++;
	}
	if(check == 1){
		cout << endl << "-> No Data!!!" << endl;
	}else{
		cout << endl << "-> Remove ID " << id << " Complete..." << endl;
	}
}
