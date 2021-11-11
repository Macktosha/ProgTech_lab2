#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <sstream>
using namespace std;

void digit_to_word() {

    fstream file1;
    try
    {
        file1.open("file.txt", ios::in);
        if (!file1.is_open())
            throw "Unable to open file1";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
    }



    string str_l, word;


    size_t i = 0;
    while (getline(file1, str_l))
    {
        std::stringstream myString(str_l);
        while (myString >> word) {
            for (i = 0; i < word.size()+1; i++) {
                switch (word[i])
                {
                case '0':
                    cout << "zero ";
                    break;
                case '1':
                    cout << "one ";
                    break;
                case '2':
                    cout << "two ";
                case '3':
                    cout << "three ";
                    break;
                case '4':
                    cout << "four ";
                    break;
                case '5':
                    cout << "five ";
                    break;
                case '6':
                    cout << "six ";
                    break;
                case '7':
                    cout << "seven ";
                    break;
                case '8':
                    cout << "eight ";
                    break;
                case '9':
                    cout << "nine ";
                    break;
                case ' ':
                    cout << " ";
                    break;
                case'\n':
                    cout << "\n";
                    break;
                default:
                    cout << word[i];
                    break;
                }
            }
            myString.clear();
            cout << " ";
        }
        cout << "\n";
    }
    file1.close();
}