#include "UI_facade.h"


void UI_facade::runADD_menu()
{
	char choice = NULL;
	cout << "Please, choose where to add elements:\n1 - HEAD\n2 - TAIL\n  3-Exit" << endl;
	cin >> choice;
	try
	{
		
			if (choice < '0' || choice>'3' || cin.fail()) {
				cin.clear();
				cin.ignore(32767, '\n');
				choice = '3';
				throw "Incorrect input";
			}
	}
	catch (const char* exp)
	{
		cerr << exp << endl;
		choice = '3';
	}
	switch (choice)
	{
	case '1':
		my_lst->operator++(1);
		break;
	case '2':
		my_lst->operator++();
		break;
	case '3':
		break;
	default:
		break;
	}
}

void UI_facade::runDelete_menu()
{
	char choice = NULL;
	int to_del = 0;
	cout << "Please, choose where from to delete elements:\n1 - HEAD\n2 - TAIL\n3 - Exact elem\n  4-Exit" << endl;
	try
	{
		cin >> choice;
		if (choice < '1' || choice>'4' || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			choice = '4';
			throw "Incorrect input";
		}
	}
	catch (const char* exp)
	{
		cerr << exp << endl;
		choice = '4';
	}
	switch (choice)
	{
	case '1':
		my_lst->operator--(1);
		break;
	case '2':
		my_lst->operator--();
		break;
	case '3':
		my_lst->unordered_print();
		cout << "Choose the elem to delete" << endl;
		cin >> to_del;
		while (to_del < 1 || to_del>my_lst->GetCount() + 1) {
			cout << "Incorrect input, enter again" << endl;
			cin >> to_del;
		}
		my_lst->delete_elem(to_del - 1);
		system("cls");
		cout << "Check the result\n\n" << endl;
		my_lst->Print_list();
		break;
	case '4':
		break;
	default:
		break;
	}
}

void UI_facade::main_menu()
{
	char choice = NULL;
	

	while (choice!='7')
	{
		cout << "Choose the command \n1 - Add element \n2 - Delete element \n3 - Print list\n4 - Edit  elem" << endl;
		cout << "5 - Search\n6 - Part 2 task\n  7 - Exit" << endl;
		cin >> choice;
		while (choice < '1' || choice>'7' || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');//очистка некорректного ввода 
			cout << "Incorrect input, enter again" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case '1':
			this->runADD_menu();
			break;
		case '2':
			this->runDelete_menu();
			break;
		case '3': 
			this->printing_menu();
			break;
		case '4':
			this->editing_menu();
			break;
		case '5':
			this->search_prs();
			break;
		case '6':
			this->part2_menu();
			break;
		case '7':
			break;
		default:
			break;
		}
	}
}

void UI_facade::editing_menu()
{
	my_lst->unordered_print();
	int choice = 0;
	cout << "Please choose elem to edit" << endl;
	cin >> choice;
	while (choice < 1 || choice> my_lst->GetCount() + 1) {
		cout << "Incorrect input, enter again" << endl;
		cin >> choice;
	}
	my_lst->edit_elem(choice - 1);
}

void UI_facade::printing_menu()
{
	my_lst->Print_list();
}

void UI_facade::part2_menu()
{
	digit_to_word();
}

void UI_facade::search_prs()
{
	my_lst->find_person();

}
