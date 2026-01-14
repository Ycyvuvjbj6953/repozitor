#include "calendar.h"
#include "task.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include "fileio.h"

using namespace std;

void pechat_calendar() {
    setColor(14);
    cout << "\n------Печать календаря месяца------\n";
    setColor(15);
    int m, y;

    while (true) {
        cout << "Месяц (1-12): ";
        cin >> m;
        if (cin.fail() || m < 1 || m > 12) {
            cout << "Ошибка! Введите число от 1 до 12!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    while (true) {
        cout << "Год (1500-9999): ";
        cin >> y;
        if (cin.fail() || y <= 1500 || y > 9999) {
            cout << "Ошибка! Введите число от 1500 до 9999 года\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    setColor(6);
    cout << "\nПн Вт Ср Чт Пт Сб Вс\n";

    int Mesta = 0; //кол-во пустых мест перед первым числом месяца
    string day_nedelu_1 = rachet_day_nedelu(1, m, y); // день недели 1-го числа месяца

    if (day_nedelu_1 == "Вторник") {
        Mesta = 1;
    }
    else if (day_nedelu_1 == "Среда") {
        Mesta = 2;
    }
    else if (day_nedelu_1 == "Четверг") {
        Mesta = 3;
    }
    else if (day_nedelu_1 == "Пятница") {
        Mesta = 4;
    }
    else if (day_nedelu_1 == "Суббота") {
        Mesta = 5;
    }
    else if (day_nedelu_1 == "Воскресенье") {
        Mesta = 6;
    }
    else Mesta = 0; // Понедельник

    
    for (int i = 0; i < Mesta; i++) { // выводим пустые места до первого дня
        cout << "   ";
    }

    
    for (int d = 1; d <= days[m - 1]; d++) { // выводим числа месяца
        cout << setw(2) << d << " ";
        if ((d + Mesta) % 7 == 0) { //если равно нулю, то это значит достигнут конец недели(воскресенье)
            cout << endl; //поэтому переносим курсор на следующую строку(строчку недели)
        }
    }
    cout << endl;
    setColor(14);
    cout << "-----------------------------------" << endl;
}
