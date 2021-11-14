#include <iostream>
#include "Note.h"
#include "List.h"
#include "UI_facade.h"
using namespace std;
int main()
{
    List *lst = new List;
    UI_facade* UI = new UI_facade(lst);

    UI->main_menu();
    
    
    delete UI;
    delete lst;
    return 0;
}

