#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iomanip>
#include"Student.h"
#include"Card.h"
class ArrayList
{
	private:
		int capacity;
		int count;
		int status;
		Student * stu;
		Card * card;
		
	public:
		ArrayList(int size);
		~ArrayList();
		void add(int id,string pre,string fn,string ln,string fc,int d,int m,int y);
		void find(int id);
		void edit(string pre,string fn,string ln,string f);
		void show();
		int get_status();
		bool isFull();
};

#endif
