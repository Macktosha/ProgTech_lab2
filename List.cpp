#include "List.h"



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
  
    cout << "Adding to the end\n" << endl;
 
    Element* temp = new Element;
    
    
    // создание нового элемента
     cout << "Please, enter the name" << endl;
     cin >> buffer;
     temp->my_data.set_Name(buffer);
     cout << "Enter the surname" << endl;
     cin >> buffer;
     temp->my_data.set_Surname(buffer);
     cout << "Enter the phone number" << endl;
     cin >> buffer;
     temp->my_data.set_Phone(buffer);
     cout << "Enter birthdate(dd mm yyyy)" << endl;
     cin >> x1 >> x2 >> x3;
     temp->my_data.set_Birth(x1, x2, x3);
     

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

List& List::operator--() {//удаление из конца префикс 

    if (count == 0) {
        cout << "List is empty" << endl;
        return *this;
    }

    else if (count == 1)
    {
        Element* temp = Head;
        delete temp;
        Head = Tail = NULL;
        cout << "Now this list is empty" << endl;
    }
    else {

        Element* one = Head;
        Element* two = Head->pNext;
        while (two->pNext != NULL) {
            two = two->pNext;
            one = one->pNext;
        }
        one->pNext = NULL;
        delete two;
    }
    count--;
   
    return *this;
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

List& List::operator++(int)//добавление в начало постфикс френд
{
    string buffer;
    unsigned int x1, x2, x3;
  
    cout << "Adding to the head\n" << endl;
    
    Element* temp = new Element;


    // создание нового элемента
    cout << "Please, enter the name" << endl;
    cin >> buffer;
    temp->my_data.set_Name(buffer);
    cout << "Enter the surname" << endl;
    cin >> buffer;
    temp->my_data.set_Surname(buffer);
    cout << "Enter the phone number" << endl;
    cin >> buffer;
    temp->my_data.set_Phone(buffer);
    cout << "Enter birthdate(dd mm yyyy)" << endl;
    cin >> x1 >> x2 >> x3;
    temp->my_data.set_Birth(x1, x2, x3);


    if (Head == NULL)
    {
        temp->pNext = NULL;
        Head = Tail = temp;
    }
    else  if (Head != NULL)
    {
        temp->pNext = Head;
        Head = temp;
    }
    count++;
    return *this;
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

    int i = 0;
    
    Note* to_array = new Note[count];

    while (temp != 0)//список превращаем в массив
    {
        to_array[i] = temp->my_data;
        // Переходим на следующий элемент
        temp = temp->pNext;
        i++;
    }
  
    for (i = 0; i < count; i++) {//сортировка пузырьком по номеру телефона
        for (int j = 0; j < count - 1; j++) {
            if (to_array[j].get_3digits() > to_array[j + 1].get_3digits())
                swap(to_array[j], to_array[j + 1]);
        }
    }
    for (i = 0; i < count; i++) {//печать отсортированного списка
        cout << i+1 << "." << endl;
        to_array[i].print_info();
        cout << "\n";
    }
    delete[] to_array;
}

void List::unordered_print()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы

    if (count == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    
    int i = 0;
    while (temp != 0)
    {
        cout << i + 1<<endl;
        // Выводим данные
        temp->my_data.print_info();
        // Переходим на следующий элемент
        temp = temp->pNext;
        i++;
    }

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
        cout << "you've deleted " << temp->my_data.get_Surname() << endl;
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
            temp->my_data.edit_info();

            break;
       }
        temp = temp->pNext;
        i++;
    }
    return *this;
   
}

void List::find_person()
{
    string fsurname,tmp;
    Element* temp = Head;
    bool flag = true;
    cout << "Please, enter the surname to find it" << endl;
    cin >> fsurname;
    transform(fsurname.begin(), fsurname.end(), fsurname.begin(), ::tolower);

    while (temp!=0)
    {
        tmp = temp->my_data.get_Surname();
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        if (tmp == fsurname) {
            temp->my_data.print_info();
            flag = false;
        }
        temp = temp->pNext;
    }
    if (flag)
        cout << "There is no such person with surname" << fsurname << endl;
    
}
