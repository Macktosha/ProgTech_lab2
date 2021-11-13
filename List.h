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

	// (��������� �������� �������)
	void Del_head();
	// �������� ����� ������
	void DelAll();

	List& operator++();//���������� � ����� �������

	friend List& operator--(List& L1);//������� �������� �� ����� 

	friend List& operator++(List& L2, int);//���������� � ������ ��������

	List& operator--(int);//�������� �� ������ ��������

	void Print_list();//������ ������
	void unordered_print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();


	List& delete_elem(int n);
	List& edit_elem(int n);

	void find_person();





};





