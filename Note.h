#pragma once
#include <iostream>
#include <string>
using namespace std;
class Note
{
private:
	string name;
	string surname;
	string phone_num;
	int birth_date[3];
public:
	Note() {
		
		memset(birth_date, 0, 3);
	}
	~Note()=default;
	void set_Name(string tmp);
	void set_Surname(string tmp);
	void set_Phone(string tmp);
	void set_Birth(int x1, int x2, int x3);

	string get_Name();
	string get_Surname();
	string get_Phone();
	int* get_Date();
	int get_3digits();


	void print_info();
	void edit_info();
	//void find_person();


};

