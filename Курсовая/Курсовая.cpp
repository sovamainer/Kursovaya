#include <iostream>
#include "Source1.cpp"
#include "Source2.cpp"
#include "Source3.cpp"
#include "Source4.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int c = -1;
    while (c != 0) {
        system("cls");
        cout << "Выберите команду\n"
            "{1} Практическая работа №1\n"
            "{2} Практическая работ а №2\n"
            "{3} Практическая работа №3\n"
            "{4} Практическая работа №4\n"
            "{0} Выход из программы\n"
            "Команда : ";
        cin >> c;
        system("cls");
        if (c == 1) {
            main1();
        }
        if (c == 2) {
            main2();
        }
        if (c == 3) {
            main3();
        }
        if (c == 4) {
            main4();
        }
    }
    return 0;
}
