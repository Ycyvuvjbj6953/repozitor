#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>
using namespace std;

struct Task {
    int day, month, year;
    int hour, minute;
    string text;
};

// Задачи
void dobavlenie(vector<Task>& tasks);
void pokazat(const vector<Task>& tasks);
void ydalenue(vector<Task>& tasks);
void redaktor(vector<Task>& tasks);
void pouck(const vector<Task>& tasks);
void sorturovka(vector<Task>& tasks);
void vivod_rachet_day_nedelu();

// Дата
string rachet_day_nedelu(int day, int month, int year);
bool NO_DAY(int day, int month, int year);

void setColor(int color);
#endif
