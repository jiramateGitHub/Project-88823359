#ifndef CARD_H
#define CARD_H
#include <iomanip>
#include<iostream>
#include<string>
using namespace std;
class Card
{
	private:
		int day_Is;
		int month_Is;
		int year_Is;
		int day_Exp;
		int month_Exp;
		int year_Exp;
	public:
		Card();
		void set_date(int d,int m,int y);
		void set_dateExp();
		void show_dateIs();
		void show_dateExp();
};

#endif
