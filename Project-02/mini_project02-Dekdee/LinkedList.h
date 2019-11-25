#include<iomanip>
#include<fstream>
#include"Student.h"
class LinkedList {
	private:
		class node {
			public:
				Student stu;
				node(int id,string pre,string fn,string ln,string fc,int d,int m,int y) {
					stu.set_id(id) ;
					stu.set_prefix(pre);
					stu.set_firstname(fn);
					stu.set_lastname(ln);
					stu.set_faculty(fc);
					stu.set_date(d,m,y);
					link = NULL;
					plink = NULL;
				}
				node * link;
				node * plink;
		};
		node * head;
		node * tail;
		int count;
		int status;
	public:
		LinkedList();
		~LinkedList();
		void add(int id,string pre,string fn,string ln,string fc,int d,int ,int y);
		void find(int id);
		void edit(string pre,string fn,string ln,string f);
		void remove(int id);
		void show();
		void readFile();
		void saveFile();
		int get_status();
		bool isEmpty();
};
