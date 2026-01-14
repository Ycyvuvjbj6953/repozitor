#include "fileio.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
using namespace std;

void coxranenie(const vector<Task>& tasks) {
    setColor(14);
    cout << "---------Сохранение в файл---------" << endl;
    setColor(15);
    char simfol;
    while (true) {
        setColor(15);
        cout << "Сохранить данные в файл?\n";
        cout << "('+' - да / '-' - нет): ";
        cin >> simfol;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (simfol == '+') {
            break; 
        }

        if (simfol == '-') {
            cout << "Сохранение отменено\n";
            setColor(14);
            cout << "-----------------------------------" << endl;
            return; 
        }

        cout << "Неправильный ввод! Напишите + или -!\n";
        continue; 
    }
    
    
    string filename;
    cout << "Введите имя файла для сохранения (в конце .txt): ";
    getline(cin, filename);

    ofstream FILE(filename);
    if (!FILE) {
        cout << "Не удалось открыть файл!\n";
        setColor(14);
        cout << "-----------------------------------" << endl;
        return;
    }
    
    FILE << tasks.size() << endl; //записываем первую строку с кол-вом задач

    for (int i = 0; i < static_cast<int>(tasks.size()); i++) {
        const Task& t = tasks[i];  
        
        FILE << t.day << " " << t.month << " " << t.year << endl; //записываем вторую строку с датой и т.д.
        FILE << t.hour << " " << t.minute << endl; 
        FILE << t.text << endl;
    }

    FILE.close();
    setColor(2);
    cout << "\nДанные успешно сохранены!\n";

    setColor(14);
    cout << "-----------------------------------" << endl;
}
void zagruzka_zadach_isfile(vector<Task>& tasks) {
    setColor(14);
    cout << "\n---------Загрузка из файла---------\n";
    setColor(15);
    string filename;
    cout << "Введите имя файла для загрузки: ";
    getline(cin, filename);

    ifstream fin(filename);
    if (!fin) {
        cout << "Не удалось открыть файл!\n";
        setColor(14);
        cout << "-----------------------------------" << endl;
        return;
    }

    size_t count;
    fin >> count;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    tasks.clear();

    for (size_t i = 0; i < count; i++) {
        Task t;
        fin >> t.day >> t.month >> t.year;
        fin >> t.hour >> t.minute;
        fin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(fin, t.text);
        tasks.push_back(t);
    }

    fin.close();

    cout << "\nЗагруженные задачи:\n";

    if (tasks.empty()) {
        cout << "Список пуст\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        Task t = tasks[i];
        cout << i + 1 << ") "
            << t.day << "." << t.month << "." << t.year << " "
            << t.hour << ":" << t.minute << " "
            << t.text << "\n";
    }

    setColor(14);
    cout << "-----------------------------------" << endl;
}
