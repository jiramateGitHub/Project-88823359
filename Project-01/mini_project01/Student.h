#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
using namespace std;
class Student {
	private:
		int id;
		string prefix;
		string firstname;
		string lastname;
		string faculty;
	public:
		Student();
		void set_id(int id);
		void set_prefix(string pre);
		void set_firstname(string firstname);
		void set_lastname(string lastname);
		void set_faculty(string faculty);
		int get_id();
		string get_prefix();
		string get_firstname();
		string get_lastname();
		string get_faculty();
};

#endif
