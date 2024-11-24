#include "Conf.h"



string Conf::get_Name() {
	return this->naming;
}

string Conf::get_Topic() {
	return this->topic;
}

void Conf::set_Name(string naming) {
	this->naming = naming;
}

void Conf::set_Topic(string topic) {
	this->topic = topic;
}
