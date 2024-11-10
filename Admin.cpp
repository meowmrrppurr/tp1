#include "Admin.h"

void Admin::set_Position(string pos) {
	this->position = pos;
}

void Admin::set_Respons(string resp) {
	this->respons = resp;
}

string Admin::get_Position() {
	return this->position;
} 

string Admin::get_Respons() {
	return this->respons;
}

string Admin::entire_info() {

	string str = this->get_Name() + ","
		+ this->position + ","
		+ this->respons;

	return str;
}
void Admin::edit_info() {
	cout << "Choose param to edit:\n1 - Name\n2 - Position\n3 - Responsibility\n\t4 - Exit" << endl;
	int choice = 0;
	string tmp;
	cin >> choice;
	while (choice < 0 || choice>4) {
		cout << "Incorrect input, enter again" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		cout << "Set new name:" << endl;
		cin >> tmp;
		this->set_Name(tmp);
		break;
	case 2:
		cout << "Set new position:" << endl;
		cin >> tmp;
		this->set_Position(tmp);
		break;
	case 3:
		cout << "Set new respons:" << endl;
		cin >> tmp;
		this->set_Respons(tmp);
		break;
	
	case 4:
		return;
	default:
		break;
	}
}