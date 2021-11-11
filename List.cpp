#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include <iostream>


List::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    count = 0;
    
}

List::~List()
{
    // Вызов функции удаления
    DelAll();
}

int List::GetCount()
{
    return count;
}

List& List::operator++()//добавление в конец префикс
{
    string buffer;
   unsigned int x1, x2, x3;
    int choice = 0;
    cout << "Adding to the end\n" << endl;
    cin >> choice;
    Element* temp = new Element;
    
    
    // создание нового элемента
     cout << "Please, enter the name" << endl;
     cin >> buffer;
     temp->data->set_Name(buffer);
     cout << "Enter the surname" << endl;
     cin >> buffer;
     temp->data->set_Surname(buffer);
     cout << "Enter the phone number" << endl;
     cin >> buffer;
     temp->data->set_Phone(buffer);
     cout << "Enter birthdate(dd mm yyyy)" << endl;
     cin >> x1 >> x2 >> x3;
     temp->data->set_Birth(x1, x2, x3);
     

    // заполнение данными
   // temp->data = my_data;
    // следующий элемент отсутствует
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

List& operator--(List& L1) {//удаление из конца префикс френд

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
   
    return L1;
}

List& List::operator--(int) {//удаление из начала постфикс

    if (count == 0) {
        cout << "List is empty" << endl;
        return *this;
    }
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->pNext;
    // удаляем бывший головной элемент
    delete temp;
    if (count == 1)
        cout << "Now this list is empty" << endl;

    count--;
    return *this;
}

List& operator++(List& L2, int)//добавление в начало постфикс френд
{
    string buffer;
    unsigned int x1, x2, x3;
    int choice = 0;
    cout << "Adding to the end\n" << endl;
    cin >> choice;
    Element* temp = new Element;


    // создание нового элемента
    cout << "Please, enter the name" << endl;
    cin >> buffer;
    temp->data->set_Name(buffer);
    cout << "Enter the surname" << endl;
    cin >> buffer;
    temp->data->set_Surname(buffer);
    cout << "Enter the phone number" << endl;
    cin >> buffer;
    temp->data->set_Phone(buffer);
    cout << "Enter birthdate(dd mm yyyy)" << endl;
    cin >> x1 >> x2 >> x3;
    temp->data->set_Birth(x1, x2, x3);


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
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->pNext;
    // удаляем бывший головной элемент
    delete temp;
}

void List::DelAll()
{
    // Пока еще есть элементы
    while (Head != 0)
        // Удаляем элементы по одному
        Del_head();
}

void List::Print_list()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы

    if (count == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "Head of the list" << endl;
    int i = 0;
    while (temp != 0)
    {
        // Выводим данные
        temp->data->print_info();
        cout << "\n\n";
        // Переходим на следующий элемент
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

    if ((Head != NULL) && (n < count) && (n >= 0)) // если по этому номеру что-то лежит и этот элемент внутри списка
    {
        // Mass - объекты, которые хранятся в списке
        Element* temp = Head, * helping = Head;

        for (int i = 0; i < n; i++)
        {
            helping = temp; // предыдущее значение temp
            temp = temp->pNext;
        }

        if (temp == Head) // если элемент который надо удалить первый
        {
            Head = temp->pNext;
        }
        else
        {
            helping->pNext = temp->pNext;
        }
        cout << "you've deleted " << temp->data->get_Name() << endl;
        delete temp;
       
        count--; // уменьшаем размер списка
        return *this;
    }
    else {
        cout << "An error occured, please check your data " << endl;
        return *this;
    }
}

List& List::edit_elem(int n) {
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы

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