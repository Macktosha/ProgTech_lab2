#pragma once
#include <iostream>
#include <string>
#include "List.h"
#include"Note.h"
#include "Part2.h"
using namespace std;
class UI_facade
{
private:
	List* my_lst;

	
	void runADD_menu();
	void runDelete_menu();
	void editing_menu();
	void printing_menu();
	void part2_menu();
	void search_prs();
	
public:
	UI_facade(List* lst) {
		this->my_lst = lst;
	}
	~UI_facade() = default;
	void main_menu();
};

