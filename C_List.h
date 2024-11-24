#pragma once
#include <iostream>
#include <fstream>
#include "Conf.h"
#include "Sched.h"
#include "Admin.h"
#include "Speaker.h"
#include <string>

using namespace std;




typedef struct Element
{
	Conf* data;
	Element* pNext;
}Element;

class List
{
private:
	Element* Head;
	Element* Tail;
	class file_Mngr {
	public:
		void recovery(List& L);
		void refresh(List& L);
	private:
		List& read_Speaker(List& L2);
		List& read_Admin(List& L2);
		List& read_Schedule(List& L2);
	};


	int count;
	int cnt_sp, cnt_sc, cnt_ad;

public:
	List();
	~List();

	// (Удаляется головной элемент)
	void Del_head();
	// Удаление всего списка
	void DelAll();

	List& operator++();//добавление в конец префикс

	friend List& operator--(List& L1);//префикс удаление из конца 

	friend List& operator++(List& L2, int);//добавление в начало постфикс

	List& operator--(int);//удаление из начала постфикс

	void Print_list();//Печать списка

	// Получение количества элементов, находящихся в списке
	int GetCount();

	file_Mngr file_Manager;//вспомогательный класс для работы с файлами 

	List& delete_elem(int n);
	List& edit_elem(int n);

	





};





