#define _CRT_SECURE_NO_WARNINGS
#include "C_List.h"
#include <iostream>


List::List()
{
    // ���������� ������ ����
    Head = Tail = NULL;
    count = 0;
    cnt_sp = cnt_ad = cnt_sc = 0;
}

List::~List()
{
    // ����� ������� ��������
    DelAll();
}

int List::GetCount()
{
    return count;
}

List& List::operator++()//���������� � ����� �������
{
    string buffer;
    int choice = 0;
    cout << "Adding to the end\nChoose type\n1 - Speaker\n2 - Admin\n3 - Schedule\n\t4-Exit" << endl;
    cin >> choice;
    Element* temp = new Element;
    
    if (choice == 1) {
        Speaker* my_data = new Speaker;
        fstream f_speak;
        f_speak.open("speakers.csv", ios::out | ( cnt_sp ? ios::app : ios::trunc));


//���������� ������ �������
       
        cout << "\nEnter the name: ";
        cin >> buffer;
        my_data->set_Name(buffer);

        cout << "\nEnter topic theme: ";
        cin >> buffer;
        my_data->set_Topic(buffer);

        cout << "\nEnter organization name: ";
        cin >> buffer;
        my_data->set_Company(buffer);

        cout << "\nEnter annotation: ";
        cin >> buffer;
        my_data->set_Annot(buffer);

        temp->data = my_data;

        f_speak << my_data->entire_info() << endl;
        f_speak.close();
        my_data->lines++;
        cnt_sp++;
    }
    else if (choice == 2) {
        Admin* my_data = new Admin;
        fstream f_adm;
        f_adm.open("admins.csv", ios::out | (cnt_ad ? ios::app : ios::trunc));
        cout << "\nEnter the name: ";
        cin >> buffer;
        my_data->set_Name(buffer);


        cout << "\nEnter position: ";
        cin >> buffer;
        my_data->set_Position(buffer);

        cout << "\nEnter responsibilities: ";
        cin >> buffer;
        my_data->set_Respons(buffer);

        temp->data = my_data;

        f_adm << my_data->entire_info() << endl;
        f_adm.close();
        my_data->lines++;
        cnt_ad++;
    }
    else if (choice == 3) {
        Sched* my_data = new Sched;
        fstream f_sched;
        f_sched.open("schedule.csv", ios::out | (cnt_sc ? ios::app : ios::trunc));
        cout << "\nEnter date: ";
        cin >> buffer;
        my_data->set_Date(buffer);

        cout << "\nEnter timetable: ";
        cin >> buffer;
        my_data->set_Ttable(buffer);

        temp->data = my_data;
        f_sched << my_data->entire_info() << endl;
        f_sched.close();
        my_data->lines++;
        cnt_sc++;
    }
    
    
    // �������� ������ ��������
    

    // ���������� �������
   // temp->data = my_data;
    // ��������� ������� �����������
    temp->pNext = NULL;

    if (count == 0)
    {
        temp->pNext = nullptr;
        Head = Tail = temp;
    }
    else {
        Element* p = Head;

        while (p->pNext != NULL)
            p = p->pNext;

        p->pNext = temp;
    }
    count++;
    return *this;
}

List& operator--(List& L1) {//�������� �� ����� ������� �����

    if (L1.count == 0) {
        cout << "List is empty" << endl;
        return L1;
    }

    else if (L1.count == 1)
    {
        Element* temp = L1.Head;
        delete temp;
        L1.Head = L1.Tail = NULL;
        cout << "Now this list is empty" << endl;
    }
    else {

        Element* one = L1.Head;
        Element* two = L1.Head->pNext;
        while (two->pNext != NULL) {
            two = two->pNext;
            one = one->pNext;
        }
        one->pNext = NULL;
        delete two;
    }
    L1.count--;
    L1.file_Manager.refresh(L1);
    return L1;
}

List& List::operator--(int) {//�������� �� ������ ��������

    if (count == 0) {
        cout << "List is empty" << endl;
        return *this;
    }
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->pNext;
    // ������� ������ �������� �������
    delete temp;
    if (count == 1)
        cout << "Now this list is empty" << endl;

    count--;
    this->file_Manager.refresh(*this);
    return *this;
}

List& operator++(List& L2, int)//���������� � ������ �������� �����
{
    string buffer;
    int choice = 0;
    cout << "Adding to the head\nChoose type\n1 - Speaker\n2 - Admin\n3 - Schedule\n\t4-Exit" << endl;
    cin >> choice;
    Element* temp = new Element;
    if (choice == 1) {
        Speaker* my_data = new Speaker;
        fstream f_speak;
        f_speak.open("speakers.csv", ios::out | (L2.cnt_sp ? ios::app : ios::trunc));
        //���������� ������ �������

        cout << "\nEnter the name: ";
        cin >> buffer;
        my_data->set_Name(buffer);

        cout << "\nEnter topic theme: ";
        cin >> buffer;
        my_data->set_Topic(buffer);

        cout << "\nEnter organization name: ";
        cin >> buffer;
        my_data->set_Company(buffer);

        cout << "\nEnter annotation: ";
        cin >> buffer;
        my_data->set_Annot(buffer);

        temp->data = my_data;

        f_speak << my_data->entire_info() << endl;
        f_speak.close();
        my_data->lines++;
        L2.cnt_sp++;
    }
    else if (choice == 2) {
        Admin* my_data = new Admin;
        fstream f_adm;
        f_adm.open("admins.csv", ios::out | (L2.cnt_ad ? ios::app : ios::trunc));
        cout << "\nEnter the name: ";
        cin >> buffer;
        my_data->set_Name(buffer);


        cout << "\nEnter position: ";
        cin >> buffer;
        my_data->set_Position(buffer);

        cout << "\nEnter responsibilities: ";
        cin >> buffer;
        my_data->set_Respons(buffer);

        temp->data = my_data;

        f_adm << my_data->entire_info() << endl;
        f_adm.close();
        my_data->lines++;
        L2.cnt_ad++;
    }
    else if (choice == 3) {
        Sched* my_data = new Sched;
        fstream f_sched;
        f_sched.open("schedule.csv", ios::out | (L2.cnt_sc ? ios::app : ios::trunc));
        cout << "\nEnter date: ";
        cin >> buffer;
        my_data->set_Date(buffer);

        cout << "\nEnter timetable: ";
        cin >> buffer;
        my_data->set_Ttable(buffer);

        temp->data = my_data;
        f_sched << my_data->entire_info() << endl;
        f_sched.close();
        my_data->lines++;
        L2.cnt_sc++;
    }
    


    if (L2.Head == NULL)
    {
        temp->pNext = NULL;
        L2.Head = L2.Tail = temp;
    }
    else  if (L2.Head != NULL)
    {
        temp->pNext = L2.Head;
        L2.Head = temp;
    }
    L2.count++;
    return L2;
}

void List::Del_head()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->pNext;
    // ������� ������ �������� �������
    delete temp;
}

void List::DelAll()
{
    // ���� ��� ���� ��������
    while (Head != 0)
        // ������� �������� �� ������
        Del_head();
}

void List::Print_list()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ���� ��� ���� ��������

    if (count == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "Head of the list" << endl;
    int i = 0;
    while (temp != 0)
    {
        // ������� ������
        cout <<i+1<<" - " << temp->data->entire_info() << " " << endl;;
        // ��������� �� ��������� �������
        temp = temp->pNext;
        i++;
    }

    cout << "Tail of the list\n\n" << endl;
}


List& List::delete_elem(int n) {
    if (count == 0) {
        cout << "List is empty" << endl;
        return *this;
    }

    if ((Head != NULL) && (n < count) && (n >= 0)) // ���� �� ����� ������ ���-�� ����� � ���� ������� ������ ������
    {
        // Mass - �������, ������� �������� � ������
        Element* temp = Head, * helping = Head;

        for (int i = 0; i < n; i++)
        {
            helping = temp; // ���������� �������� temp
            temp = temp->pNext;
        }

        if (temp == Head) // ���� ������� ������� ���� ������� ������
        {
            Head = temp->pNext;
        }
        else
        {
            helping->pNext = temp->pNext;
        }
        cout << "you've deleted " << temp->data->get_Name() << endl;
        delete temp;
        this->file_Manager.refresh(*this);
        count--; // ��������� ������ ������
        return *this;
    }
    else {
        cout << "An error occured, please check your data " << endl;
        return *this;
    }
}

List& List::edit_elem(int n) {
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ���� ��� ���� ��������

    if (count == 0) {
        cout << "The list is empty" << endl;
        return *this;
    }
    
    int i = 0;
    while (i<=n)
    {
        if (i == n) {
            temp->data->edit_info();

            break;
       }
        temp = temp->pNext;
        i++;
    }
    return *this;
   
}