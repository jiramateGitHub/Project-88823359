#include "Card.h"

Card::Card() {
	day_Is = 0;
	month_Is = 0;
	year_Is = 0;
	day_Exp = 0;
	month_Exp = 0;
	year_Exp = 0;
}

void Card::set_date(int d,int m,int y) {
	day_Is = d;
	month_Is = m;
	year_Is = y;
	set_dateExp();
}
void Card::set_dateExp() {
	day_Exp = day_Is;
	month_Exp = month_Is;
	year_Exp = year_Is + 10;
}
void Card::show_dateIs() {
	cout  << "\t" << day_Is << "/" << month_Is << "/" << year_Is ;
}
void Card::show_dateExp() {
	cout  << "\t" << day_Exp << "/" << month_Exp << "/" << year_Exp;
}
