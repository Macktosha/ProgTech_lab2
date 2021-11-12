#include "List.h"



List::List()
{
    // ���������� ������ ����
    Head = Tail = NULL;
    count = 0;
    
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
   unsigned int x1, x2, x3;
  
    cout << "Adding to the end\n" << endl;
 
    Element* temp = new Element;
    
    
    // �������� ������ ��������
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
    return *this;
}

List& operator++(List& L2, int)//���������� � ������ �������� �����
{
    string buffer;
    unsigned int x1, x2, x3;
  
    cout << "Adding to the head\n" << endl;
    
    Element* temp = new Element;


    // �������� ������ ��������
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


    int i = 0;
    
    Note* to_array = new Note[count];

    while (temp != 0)//������ ���������� � ������
    {
        to_array[i] = temp->my_data;
        // ��������� �� ��������� �������
        temp = temp->pNext;
        i++;
    }
  
    for (i = 0; i < count; i++) {//���������� ��������� �� ������ ��������
        for (int j = 0; j < count - 1; j++) {
            if (to_array[j].get_3digits() > to_array[j + 1].get_3digits())
                swap(to_array[j], to_array[j + 1]);
        }
    }
    for (i = 0; i < count; i++)//������ ���������������� ������
        to_array[i].print_info();

    delete[] to_array;
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
        cout << "you've deleted " << temp->my_data.get_Surname() << endl;
        delete temp;
       
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
            temp->my_data.edit_info();

            break;
       }
        temp = temp->pNext;
        i++;
    }
    return *this;
   
}