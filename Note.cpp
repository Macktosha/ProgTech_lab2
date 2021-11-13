#include "Note.h"
using namespace std;
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

int Note::get_3digits()
{
	return stoi(this->phone_num.substr(0, 3));
}

void Note::print_info()
{
	cout << "------info------" << endl;
	cout << "-Surname: " << this->surname << endl;
	cout << "-Name: " << this->name << endl;
	cout << "-Phone N: " << this->phone_num << endl;
	cout << "-Date of birth: " << this->birth_date[0] << "." << this->birth_date[1] << "." << this->birth_date[2] << endl;
}

void Note::edit_info()
{
	cout << "Choose param to edit:\n1 - Name\n2 - Surname\n3 - Phone number\n4 - Birth date\n\t5 - Exit" << endl;
	int choice = 0;
	string tmp;
	int dd, mm, yy;
	cin >> choice;
	while (choice < 0 || choice>5) {
		cout << "Incorrect input, enter again" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		cout << "Set new name:" << endl;
		cin >> tmp;
		this->set_Name(tmp);
		break;
	case 2:
		cout << "Set new surname:" << endl;
		cin >> tmp;
		this->set_Surname(tmp);
		break;
	case 3:
		cout << "Set new phone number:" << endl;
		cin >> tmp;
		this->set_Phone(tmp);
		break;
	case 4:
		cout << "Set new birth date:" << endl;
		cin >> dd>>mm>>yy;
		this->set_Birth(dd,mm,yy);
		break;
	case 5:
		return;
	default:
		break;
	}
}

