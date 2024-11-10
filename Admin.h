#pragma once
#include "Conf.h"
#include <iostream>

using namespace std; 

class Admin:public Conf {
private:
	string position;
	string respons;
public:
	
	int lines;
	Admin() { type = typeid(*this).name(); lines = 0; }

	Admin(string naming, string topic, string position, string respons) : Conf(naming, topic) {
		this->position = position;
		this->respons = respons;
	}

	~Admin(){}

	void set_Position(string pos);
	void set_Respons(string resp);

	string get_Position();
	string get_Respons();

	virtual string entire_info() override;
	virtual void edit_info() override;
};