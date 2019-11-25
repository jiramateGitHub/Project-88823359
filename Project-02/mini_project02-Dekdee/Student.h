#include<iostream>
#include<string>
using namespace std;
class Student {
	private:
		int id;
		int day;
		int month;
		int year;
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
		void set_date(int d,int m,int y);
		int get_id();
		string get_prefix();
		string get_firstname();
		string get_lastname();
		string get_faculty();
		int get_day();
		int get_month();
		int get_year();
};
