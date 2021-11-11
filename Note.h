#pragma once
#include "List.h"
/*
* Определить класс с именем NОТЕ, содержащий следующие поля:
● фамилия, имя;
● номер телефона;
● день рождения (массив из трех чисел).
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа NОТЕ.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть упорядочены по трем первым цифрам номера
телефона;
● вывод на экран информации о человеке, чья фамилия введена с
клавиатуры;
● если такого нет, выдать на дисплей соответствующее сообщение.

*/
class Note
{
private:
	string name;
	string surname;
	string phone_num;
	int birth_date[3];
public:
	void set_Name(string tmp);
	void set_Surname(string tmp);
	void set_Phone(string tmp);
	void set_Birth(int, int, int);

	string get_Name();
	string get_Surname();
	string get_Phone();
	int* get_Date();

	void print_info();
	void edit_info();
	void find_person();


};

