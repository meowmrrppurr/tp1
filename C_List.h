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

	// (��������� �������� �������)
	void Del_head();
	// �������� ����� ������
	void DelAll();

	List& operator++();//���������� � ����� �������

	friend List& operator--(List& L1);//������� �������� �� ����� 

	friend List& operator++(List& L2, int);//���������� � ������ ��������

	List& operator--(int);//�������� �� ������ ��������

	void Print_list();//������ ������

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();

	file_Mngr file_Manager;//��������������� ����� ��� ������ � ������� 

	List& delete_elem(int n);
	List& edit_elem(int n);

	





};





