#pragma once

#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include <fstream>
#include "VariadicTable.h"

using namespace std;


static void pressToMenu() {
    cin.ignore();
    cout << "press enter to menu";
    cin.get();
    system("cls");
}

struct Bilding {
    string name;
    short fyear;
    short numberOfStudents;
    float avrageMark;
};


struct employer {
    string name;
    string surname;
    float mark;
    short age;
    short unversity_id;
};

