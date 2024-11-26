#define _CRT_SECURE_NO_WARNINGS
#include "C_List.h"

List& List::file_Mngr::read_Speaker(List& L2) {

    fstream f_sp;
    try
    {
        f_sp.open("speakers.csv", ios::in);
        if (!f_sp.is_open())
            throw "Unable to open speakers.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return L2;
    }
    
    
    
    string line1;
   
    char* words;
    //считываем строку 
    while (getline(f_sp, line1)) {
        int line_size = line1.size();
        char* s_data = new char[line_size + 1];
        string* sp_info = new string[4];

        strcpy(s_data, line1.c_str());


        //поиск слов через запятую и заполняем массив для заполнения в поля объекта
        try {
            words = strtok(s_data, ",");
            if (!words)
                throw "check data in the file";
            int i = 0;
            while (words != NULL) {
                sp_info[i] = string(words);
                words = strtok(NULL, ",");
                i++;
            }
        }
        catch (const char* exp) {
            cerr << exp << endl;
            return L2;
        }
        Speaker* speak_f = new Speaker;
        speak_f->set_Name(sp_info[0]);
        speak_f->set_Topic(sp_info[1]);
        speak_f->set_Company(sp_info[2]);
        speak_f->set_Annot(sp_info[3]);

        speak_f->lines++;

        //добавление в список 
        Element* temp = new Element;

        temp->data = speak_f;
        temp->pNext = NULL;

        if (L2.count == 0)
        {
            temp->pNext = nullptr;
            L2.Head = L2.Tail = temp;
        }
        else {
            Element* p = L2.Head;

            while (p->pNext != NULL)
                p = p->pNext;

            p->pNext = temp;
        }
        L2.count++;
        L2.cnt_sp++;
        delete[] s_data;
        delete[] sp_info;
    }




    f_sp.close();
    return L2;
}

List& List::file_Mngr::read_Admin(List& L2) {
    fstream f_adm; 
    try
    {
        f_adm.open("admins.csv", ios::in);
        if (!f_adm.is_open())
            throw "Unable to open admins.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return L2;
    }
    string line1;

    char* words;
    //считываем строку 
    while (getline(f_adm, line1)) {
        int line_size = line1.size();
        char* s_data = new char[line_size + 1];
        string* sp_info = new string[3];

        strcpy(s_data, line1.c_str());


        //поиск слов через запятую и заполняем массив для заполнения в поля объекта
        try{
            words = strtok(s_data, ",");
            if (!words)
                throw "check data in the file";
        int i = 0;
        while (words != NULL) {
            sp_info[i] = string(words);
            words = strtok(NULL, ",");
            i++;
        }
    }
        catch(const char* exp){
            cerr << exp << endl;
            return L2;
        }
        Admin* adm_f = new Admin;
        adm_f->set_Name(sp_info[0]);
        adm_f->set_Position(sp_info[1]);
        adm_f->set_Respons(sp_info[2]);

        adm_f->lines++;

        //добавление в список 
        Element* temp = new Element;

        temp->data = adm_f;
        temp->pNext = NULL;

        if (L2.count == 0)
        {
            temp->pNext = nullptr;
            L2.Head = L2.Tail = temp;
        }
        else {
            Element* p = L2.Head;

            while (p->pNext != NULL)
                p = p->pNext;

            p->pNext = temp;
        }
        L2.count++;
        L2.cnt_sp++;
        delete[] s_data;
        delete[] sp_info;
    }




    f_adm.close();
    return L2;
}

List& List::file_Mngr::read_Schedule(List& L2) {
    fstream f_sched;
    try
    {
        f_sched.open("schedule.csv", ios::in);
        if (!f_sched.is_open())
            throw "Unable to open schedule.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return L2;
    }
    string line1;

    char* words;
    //считываем строку 
    while (getline(f_sched, line1)) {
        int line_size = line1.size();
        char* s_data = new char[line_size + 1];
        string* sp_info = new string[2];

        strcpy(s_data, line1.c_str());


        //поиск слов через запятую и заполняем массив для заполнения в поля объекта
        try {
            words = strtok(s_data, ",");
            if (!words)
                throw "check data in the file";
            int i = 0;
            while (words != NULL) {
                sp_info[i] = string(words);
                words = strtok(NULL, ",");
                i++;
            }
        }
        catch (const char* exp) {
            cerr << exp << endl;
            return L2;
        }
        Sched* sched_f = new Sched;
        sched_f->set_Date(sp_info[0]);
        sched_f->set_Ttable(sp_info[1]);
       

        sched_f->lines++;

        //добавление в список 
        Element* temp = new Element;

        temp->data = sched_f;
        temp->pNext = NULL;

        if (L2.count == 0)
        {
            temp->pNext = nullptr;
            L2.Head = L2.Tail = temp;
        }
        else {
            Element* p = L2.Head;

            while (p->pNext != NULL)
                p = p->pNext;

            p->pNext = temp;
        }
        L2.count++;
        L2.cnt_sp++;
        delete[] s_data;
        delete[] sp_info;
    }




    f_sched.close();
    return L2;
}

void List::file_Mngr::recovery(List& L) {
    read_Speaker(L);
    read_Admin(L);
    read_Schedule(L);
}

void List::file_Mngr::refresh(List& L) {
    fstream f_sp,f_adm,f_sched;
     //speaker refresh
    try
    {
        f_sp.open("speakers.csv", ios::trunc| ios::out);
        if (!f_sp.is_open())
            throw "Unable to open speakers.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return;
    }
    
    if (L.count == 0) {
        cout << "The list is empty" << endl;
        return;
    }
   
    Element* temp = L.Head;
    while (temp != 0)
    {
        if (temp->data->type == "class Speaker") {
            f_sp << temp->data->entire_info() << endl;
            
        }
        temp = temp->pNext;
    }
    f_sp.close();

    ///admin refresh
    try
    {
        f_adm.open("admins.csv", ios::trunc | ios::out);
        if (!f_adm.is_open())
            throw "Unable to open admins.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return;
    }

    if (L.count == 0) {
        cout << "The list is empty" << endl;
        return;
    }

     temp = L.Head;
    while (temp != 0)
    {
        if (temp->data->type == "class Admin") {
            f_adm << temp->data->entire_info() << endl;

        }
        temp = temp->pNext;
    }
    f_adm.close();

    //schedule refresh

    try
    {
        f_sched.open("schedule.csv", ios::trunc | ios::out);
        if (!f_sched.is_open())
            throw "Unable to open schedule.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return;
    }

    if (L.count == 0) {
        cout << "The list is empty" << endl;
        return;
    }

     temp = L.Head;
    while (temp != 0)
    {
        if (temp->data->type == "class Sched") {
            f_sched << temp->data->entire_info() << endl;

        }
        temp = temp->pNext;
    }
    f_sched.close();
}