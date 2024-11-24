#pragma once
#include "Conf.h"
#include <iostream>
using namespace std;
class Speaker : public Conf {
private:
	string company,
		annotation;
	
	public:
		
		int lines;
		Speaker() { type = typeid(*this).name(); lines = 0; }

		Speaker(string naming,string topic,string company,string annotation): Conf (naming,topic) {
			this->company = company;
			this->annotation = annotation;
		}

		~Speaker() {}

		void set_Company(string company);
		void set_Annot(string annot);

		string get_Company();
		string get_Annot();

		virtual string entire_info() override;
		virtual void edit_info() override;
		
};