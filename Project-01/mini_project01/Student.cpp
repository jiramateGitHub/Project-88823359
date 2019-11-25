#include "Student.h"

Student::Student() {
	id = -1;
}
void Student::set_id(int id) {
	this->id = id;
}
void Student::set_prefix(string pre) {
	this->prefix = pre;
}
void Student::set_firstname(string firstname) {
	this->firstname = firstname;
}
void Student::set_lastname(string lastname) {
	this->lastname = lastname;
}
void Student::set_faculty(string faculty) {
	this->faculty = faculty;
}
int Student::get_id() {
	return id;
}
string Student::get_prefix() {
	return prefix;
}
string Student::get_firstname() {
	return firstname;
}
string Student::get_lastname() {
	return lastname;
}
string Student::get_faculty() {
	return faculty;
}
