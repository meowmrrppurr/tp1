#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Conf.h"
#include "Speaker.h"
#include "Admin.h"
#include "Sched.h"
#include "C_List.h"
using namespace std;

int main()
{
	List lst;
	lst.file_Manager.recovery(lst);
	int choice, x = 0;
	bool exit = true;

	while (exit)
	{
		system("cls");
		cout << "Choose the command to work with List\n1 - Add element from the head\n2 - Delete element from the head\n3 - Add element to the tail\n4 - Delete element from the tail" << endl;
		cout << "5 - Print list\n6 - Delete exact element\n7 - Edit exact elem\n\t8 - Exit" << endl;
		cin >> choice;

		while (choice < 0 || choice > 8 || cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n'); // очистка некорректного ввода
			cout << "Incorrect input, enter again" << endl;
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			lst++;
			system("pause");
			break;
		case 2:
			lst--;
			system("pause");
			break;

		case 3:
			++lst;
			system("pause");
			break;

		case 4:
			--lst;
			system("pause");
			break;
		case 5:
			cout << "Elements:" << lst.GetCount() << endl;
			lst.Print_list();
			system("pause");
			break;
		case 6:
			lst.Print_list();
			cout << "Choose the elem to delete" << endl;
			cin >> x;
			while (x < 1 || x > lst.GetCount() + 1)
			{
				cout << "Incorrect input, enter again" << endl;
				cin >> x;
			}
			lst.delete_elem(x - 1);
			system("cls");
			cout << "Check the result\n\n"
				 << endl;
			lst.Print_list();
			break;
		case 7:
			system("cls");
			lst.Print_list();
			cout << "Please choose elem to edit" << endl;
			cin >> x;
			while (x < 1 || x > lst.GetCount() + 1)
			{
				cout << "Incorrect input, enter again" << endl;
				cin >> x;
			}
			lst.edit_elem(x - 1);
			lst.file_Manager.refresh(lst);
			break;

		case 8:
			exit = false;
			break;

		default:
			cout << "undefined error" << endl;
			exit = false;
			system("pause");
			break;
		}
	}

	return 0;
}
