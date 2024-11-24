#include "Speaker.h"

void Speaker::set_Company(string comp) {
	this->company = comp;
}

void Speaker::set_Annot(string annot) {
	this->annotation = annot;
}

string Speaker::get_Annot() {
	return this->annotation;
}

string Speaker::get_Company() {
	return this->company;
}

string Speaker::entire_info() {
	string str = this->get_Name() + ","
		+ this->get_Topic() + ","
		+ this->company + ","
		+ this->annotation;

	return str;
}

void Speaker::edit_info() {
	cout << "Choose param to edit:\n1 - Name\n2 - Topic\n3 - Company\n4 - Annotation\n\t5 - Exit" << endl;
	int choice = 0;
	string tmp;
	cin >> choice;
	while (choice < 0 || choice>5) {
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
		cout << "Set new topic:" << endl;
		cin >> tmp;
		this->set_Topic(tmp);
		break;
	case 3:
		cout << "Set new company:" << endl;
		cin >> tmp;
		this->set_Company(tmp);
		break;
	case 4:
		cout << "Set new annotation:" << endl;
		cin >> tmp;
		this->set_Annot(tmp);
		break;
	case 5:
		return;
	default: 
		break;
	}
}
