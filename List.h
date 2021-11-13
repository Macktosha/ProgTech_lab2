#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include "Note.h"

using namespace std;

typedef struct Element
{
	Note my_data;
	Element* pNext;
}Element;

class List
{
private:
	Element* Head;
	Element* Tail;



	int count;
	

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
	void unordered_print();

	// Получение количества элементов, находящихся в списке
	int GetCount();


	List& delete_elem(int n);
	List& edit_elem(int n);

	void find_person();





};





