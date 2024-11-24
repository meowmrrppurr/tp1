#include "Sched.h"

void Sched::set_Date(string date) {
	this->date = date;
}

void Sched::set_Ttable(string ttable) {
	this->time_table = ttable;
}

string Sched::get_Date() {
	return this->date;
}

string Sched::get_Ttable() {
	return this->time_table;
}

string Sched::entire_info() {

	string str = this->date + ","
		+ this->time_table;

	return str;
}
void Sched::edit_info() {
	cout << "Choose param to edit:\n1 - Date\n2 - Time Table\n\t3 - Exit" << endl;
	int choice = 0;
	string tmp;
	cin >> choice;
	while (choice < 0 || choice>3) {
		cout << "Incorrect input, enter again" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		cout << "Set new name:" << endl;
		cin >> tmp;
		this->set_Date(tmp);
		break;
	case 2:
		cout << "Set new position:" << endl;
		cin >> tmp;
		this->set_Ttable(tmp);
		break;
	

	case 3:
		return;
	default:
		break;
	}
}