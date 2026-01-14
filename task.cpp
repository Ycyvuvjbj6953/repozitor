#include "task.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include "fileio.h"
#define NOMINMAX     //нужна, чтобы убрать красные подчеркивания max в коду (из-за библиотеки Windows)
#include <windows.h> //нужна, чтобы заработали встр функции правильного сохранения русских букв

using namespace std;

string rachet_day_nedelu(int day, int month, int year) {
    string DNU[] = { "Понедельник","Вторник","Среда", "Четверг","Пятница","Суббота","Воскресенье" };
    int kol_vo_V_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    int cnt = 0; //счетчик, который будет считать общее количество дней с 1 янв 1900 до указанной даты

    for (int y = 1500; y < year; y++) {
        cnt += 365;
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) { //проверка на високосный год
            cnt+=1;
        }
    }

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        kol_vo_V_month[1] = 29;
    }

    for (int m = 1; m < month; m++) {
        cnt += kol_vo_V_month[m - 1]; //добавляем кол-во дней каждого месяца, не включая текущий месяц
    }
    cnt += day - 1; //добавляем дни текущего месяца

    return DNU[cnt % 7]; //берем остаток от деления на 7, потому что неделя повторяется каждые 7 дней
}

void vivod_rachet_day_nedelu() {
    
    int day, month, year;
    setColor(14);
    cout << "\n----------Расчёт дня недели--------" << endl;
    
    while (true) {
        setColor(15);
        while (true) {
            cout << "День (1~31): ";
            cin >> day;
            if (cin.fail() || day < 1 || day > 31) {
                cout << "Ошибка! Введите число от 1 до 31!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        while (true) {
            cout << "Месяц (1-12): ";
            cin >> month;
            if (cin.fail() || month < 1 || month > 12) {
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
            cin >> year;
            if (cin.fail() || year < 1500 || year > 9999) {
                cout << "Ошибка! Введите число от 1500 до 9999 года\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        if (!NO_DAY(day, month, year)) {
            cout << "\nТакого дня в этом месяце и году" << endl;
            cout << "не существует! Попробуйте ввести" << endl;
            cout << "другую дату" << endl;
            setColor(14);
            cout << "-----------------------------------" << endl;
            continue;
        }
        break;
    } 
    setColor(2);
    cout << "\nДень недели: " << rachet_day_nedelu(day, month, year) << endl;
    setColor(14);
    cout << "-----------------------------------" << endl;
}


void dobavlenie(vector<Task>& tasks) {
    setColor(14);
    cout << "\n---------Добавление задачи---------" << endl;
    setColor(15);
    Task t;
    while (true) {
        while (true) {
            cout << "День (1~31): ";
            cin >> t.day;
            if (cin.fail() || t.day < 1 || t.day > 31) {
                cout << "Ошибка! Введите число от 1 до 31!\n";
                cout << "Но учитывайте, что есть другие ограничения в зависимости от года и месяца:\n";
                cout << "ввод может быть до 28, до 29, до 30, до 31" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        while (true) {
            cout << "Месяц (1-12): ";
            cin >> t.month;
            if (cin.fail() || t.month < 1 || t.month > 12) {
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
            cin >> t.year;
            if (cin.fail() || t.year < 1500 || t.year > 9999) {
                cout << "Ошибка! Введите число от 1500 до 9999 года\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        
        if (!NO_DAY(t.day, t.month, t.year)) {
            
            cout << "\nТакого дня в этом месяце и году" << endl;
            cout << "не существует! Попробуйте ввести" << endl;
            cout << "другую дату" << endl;
            setColor(14);
            cout << "-----------------------------------" << endl;
            setColor(15);
            continue;
        }
        break;
    }

    while (true) {
        cout << "Часы (0-23): ";
        cin >> t.hour;
        if (cin.fail() || t.hour < 0 || t.hour > 23) {
            cout << "Ошибка! Введите число от 0 до 23!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    while(true){
        cout << "Минуты (0-59): ";
        cin >> t.minute;
        if (cin.fail() || t.minute < 0 || t.minute > 59) {
            cout << "Ошибка! Введите число от 0 до 59!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Текст задачи: ";
    getline(cin, t.text);

    tasks.push_back(t);
    setColor(2);
    cout << "\nЗадача успешно добавлена!\n";
    setColor(14);
    cout << "-----------------------------------" << endl;
}

void pokazat(const vector<Task>& tasks) {
    setColor(14);
    cout << "\n-------------Показ задач-----------" << endl;
    setColor(15);
    if (tasks.empty()) {
        cout << "Список задач пуст!\n";
        setColor(14);
        cout << "-----------------------------------" << endl;
        return;
    }
    
    for (int i = 0; i < static_cast<int>(tasks.size()); i++) {
        const Task& t = tasks[i]; //теперь t - это текущая задача
        cout <<"Задача под номером " << i << ": " << t.day << "." << t.month << "." << t.year << " " << setw(2) << setfill('0') << t.hour << ":"
            << setw(2) << t.minute << setfill(' ')<< " (" << rachet_day_nedelu(t.day, t.month, t.year) << ") " << t.text << endl;
    }
    setColor(14);
    cout << "-----------------------------------" << endl;
    
}

void ydalenue(vector<Task>& tasks) {
    setColor(14);
    cout << "\n---------Удаление задачи-----------" << endl;
    
    pokazat(tasks);
    if (tasks.empty()) {
        setColor(15);
        cout << "Список задач пуст! Удалять нечего!" << endl;
        setColor(14);
        cout << "-----------------------------------" << endl;
        return;
    }
    int numb;
    while (true) {
        setColor(15);
        cout << "Введите номер задачи: ";
        cin >> numb;
        if (cin.fail() || numb < 0 || numb >= static_cast<int>(tasks.size())) {
            cout << "Ошибка! Введите номер с 0 до крайней задачи!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    tasks.erase(tasks.begin() + numb); //удалям интератор(т.е. первый элемент) с индексом numb
    setColor(2);
    cout << "Задача успешно удалена!\n";
    setColor(14);
    cout << "-----------------------------------" << endl;
}

void redaktor(vector<Task>& tasks) {
    setColor(14);
    cout << "\n--------Редактирование задачи------" << endl;
    setColor(15);
    pokazat(tasks);
    setColor(15);
    if (tasks.empty()) {
        setColor(15);
        cout << "Редактировать нечего!" << endl;
        setColor(14);
        cout << "-----------------------------------" << endl;
        return;
    }
    int numb;
    while (true) {
        cout << "Введите номер задачи: ";
        cin >> numb;
        if (cin.fail() || numb < 0 || numb >= static_cast<int>(tasks.size())) {
            cout << "Ошибка! Введите номер с 0 до крайней задачи\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
cout << "Напишите новый текст: ";
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
getline(cin, tasks[numb].text);
setColor(2);
cout << "\nЗадача успешно отредактирована!" << endl;
setColor(14);
cout << "-----------------------------------" << endl;

}

void pouck(const vector<Task>& tasks) {
    setColor(14);
    cout << "\n-----------Поиск по дате-----------" << endl;
    setColor(15);
    if (tasks.empty()) {
        cout << "Список задач пуст! Поэтому поиска по дате не будет" << endl;
        setColor(14);
        cout << "-----------------------------------" << endl;
        return;
    }
    int d, m, y;
    while (true) {
        while (true) {
            cout << "День (1~31): ";
            cin >> d;
            if (cin.fail() || d < 1 || d > 31) {
                cout << "Ошибка! Введите число от 1 до 31!\n";
                cout << "Но учитывайте, что есть другие ограничения в зависимости от года и месяца:\n";
                cout << "ввод может быть до 28, до 29, до 30, до 31" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

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
            if (cin.fail() || y < 1500 || y > 9999) {
                cout << "Ошибка! Введите число от 1500 до 9999 года\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        
        if (!NO_DAY(d, m, y)) {
           
            cout << "\nТакого дня в этом месяце и году" << endl;
            cout << "не существует! Попробуйте ввести" << endl;
            cout << "другую дату" << endl;
            setColor(14);
            cout << "-----------------------------------" << endl;
            setColor(15);
            continue;
        }
        break;
    }

    bool zadacha = false; //изначально считаем,что задач по этой дате нет
    for (size_t i = 0; i < tasks.size(); i++) {
        const Task& t = tasks[i];  // t — текущая задача
        if (t.day == d && t.month == m && t.year == y) {
            cout << t.hour << ":" << t.minute << " " << t.text << endl;
            zadacha = true;
        }
    }
    if (!zadacha) {
        cout << "\nНичего не найдено\n";
        setColor(14);
        cout << "-----------------------------------" << endl;
    }
  
}
bool posled(const Task& a, const Task& b) {//функция, которая означает что "a" < "b", если все правильно - оставляем на своих местах
    //если неправильно - меняем местами
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    if (a.day != b.day) {
        return a.day < b.day;
    }
    if (a.hour != b.hour) {
        return a.hour < b.hour;
    }
    return a.minute < b.minute;
}
void sorturovka(vector<Task>& tasks) {
    setColor(14);
    cout << "\n-------------Сортировка------------" << endl;
    setColor(15);
    if (tasks.empty()) {
        cout << "Задачи отсутствуют. Сортировать нечего!" << endl;
        setColor(14);
        cout << "-----------------------------------" << endl;
        return;
    }
    
    sort(tasks.begin(), tasks.end(), posled);
    setColor(2);
    cout << "Всё успешно отсортировано!\n";
    setColor(14);
    cout << "-----------------------------------" << endl;

}
bool NO_DAY(int day, int month, int year) {
    int kol_vo_day_v; //переменная, где будет хранится количество дней в указанном месяце и году

   
    bool vicokoc;
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) { //проверка на високосный год
        vicokoc = true;
    }
    else {
        vicokoc = false;
    }

    if (month == 2) {
        if (vicokoc) {
            kol_vo_day_v = 29;
        }
        else {
            kol_vo_day_v = 28;
        }
       
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        kol_vo_day_v = 30;
    }
    else if (month == 12) {
        kol_vo_day_v = 31;
    }

    if (day > kol_vo_day_v) { //проверка лежит ли день в пределах месяца
        return false;
    }

    return true;
}
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
