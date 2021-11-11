#include "Note.h"

void Note::set_Name(string t_name)
{
	this->name = t_name;
}

void Note::set_Surname(string t_surname)
{
	this->surname = t_surname;
}

void Note::set_Phone(string t_phone)
{
	this->phone_num = t_phone;
}

void Note::set_Birth(int day, int month, int year)
{
	this->birth_date[0] = day;
	this->birth_date[1] = month;
	this->birth_date[2] = year;
}

string Note::get_Name()
{
	return this->name;
}

string Note::get_Surname()
{
	return this->surname;
}


string Note::get_Phone()
{
	return this->phone_num;
}

int* Note::get_Date()
{
	return this->birth_date;
}

void Note::print_info()
{
	cout << "------info------" << endl;
	cout << "-Surname: " << this->surname << endl;
	cout << "-Name: " << this->name << endl;
	cout << "-Phone N: " << this->phone_num << endl;
	cout << "-Date of birth: " << this->birth_date[0] << "." << this->birth_date[1] << "." << this->birth_date[2] << endl;
}

