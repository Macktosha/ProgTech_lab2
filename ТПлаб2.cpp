#include <iostream>
#include "Part2.h"
#include "Note.h"
#include "List.h"
using namespace std;
int main()
{
    List lst;
    ++lst;
    ++lst;
    ++lst;
    lst.Print_list();
    
    return 0;
}

