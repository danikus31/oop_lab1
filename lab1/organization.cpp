#include "organization.h"




void organization::showBildings()
{
    system("cls");
    if (universitys.size()) {
        cout << "Number of universitys: " << universitys.size() << "\n";
        VariadicTable<short, string, short, short, float> vt({ "ID", "Name", "founders date", "students", "avrage mark"}, 10);
        for (size_t i = 0; i < universitys.size(); ++i) {
            universitys[i].numberOfStudents = 0;
            universitys[i].avrageMark = 0;
            for (size_t j = 0; j < students.size(); ++j) {
                if (i == students[j].unversity_id) {
                    universitys[i].numberOfStudents++;
                    universitys[i].avrageMark += students[j].mark;
                }
            }
            if(universitys[i].numberOfStudents)universitys[i].avrageMark /= universitys[i].numberOfStudents;
            vt.addRow(i, universitys[i].name, universitys[i].fyear, universitys[i].numberOfStudents, universitys[i].avrageMark);
        }
        vt.print(cout);
    }
    else {
        cout << "NO UNIVERSITYES\n\n\n";
    }
    pressToMenu();
}

void organization::showEmploys()
{
    system("cls");
    if (students.size()) {
        cout << "Count of students = " << students.size() << "\n";
        VariadicTable<string, string, short, float, short, string> vt({ "Name", "Surname", "age", "mark", "uid", "university"}, 10);
        for (size_t i = 0; i < students.size(); ++i) {
            vt.addRow(students[i].name, students[i].surname, students[i].age, students[i].mark, students[i].unversity_id, universitys[students[i].unversity_id].name);
        }
        vt.print(std::cout);

    }
    else {
        cout << "no students\n\n\n";
    }
    pressToMenu();
}


void organization::addNewBilding()
{
    system("cls");
    Bilding new_Univercity;
    cout << "Introduceti Numele universitatii\n";
    cin >> new_Univercity.name;
    cout << "Introduceti anul fundatiei\n";
    cin >> new_Univercity.fyear;

    universitys.push_back(new_Univercity);
    system("cls");
}



void organization::addNewEmploys()
{
    system("cls");
    if (students.size()) {
        employer new_student;
        cout << "Introduceti Numele\n";
        cin >> new_student.name;
        cout << "Introduceti Prenomele\n";
        cin >> new_student.surname;
        cout << "Indtroduceti visrta\n";
        cin >> new_student.age;
        cout << "Introduceti nota media\n";
        cin >> new_student.mark;
        cout << "Introduceti ID la Universitate\n";
        cin >> new_student.unversity_id;

        students.push_back(new_student);
    }
    else {
        cout << "nu sunt universitati pentru a atribui studentii\n\n";
        pressToMenu();
    }
    system("cls");
}



int organization::save_Bildings_to_file(){
    ofstream file(bilding_filename);
    if (file.is_open()) {
        file << universitys.size() << "\n";
        for (const auto& univer : universitys) {
            file << univer.name << "\n";
            file << univer.fyear << "\n";
        }
        file.close();
        system("cls");
        return 1;
    }
    else {
        system("cls");
        cout << "Nu se poate deschide fisierul " << bilding_filename << " pentru salvare.\n";
        return 0;
    }
}



int organization::load_Bildings_from_file() {
    ifstream file(bilding_filename);
    if (file.is_open()) {
        universitys.clear();
        size_t size;
        file >> size;
        file.ignore();
        for (size_t i = 0; i < size; ++i) {
            Bilding loadBilinidg;
            getline(file, loadBilinidg.name);
            file >> loadBilinidg.fyear;
            file.ignore();
            universitys.push_back(loadBilinidg);
        }
        file.close();

        system("cls");
        return 1;
    }
    else {

        system("cls");
        cout << "Nu se poate deschide fisierul " << bilding_filename << " pentru incarcare.\n";
        return 0;
    }
}


int organization::save_employes_to_file()
{
    ofstream file(employs_filename);
    if (file.is_open()) {
        file << students.size() << "\n";
        for (const auto& fstudent : students) {
            file << fstudent.name << "\n";
            file << fstudent.surname << "\n";
            file << fstudent.age<< "\n";
            file << fstudent.mark << "\n";
            file << fstudent.unversity_id << "\n";
        }
        file.close();
        system("cls");
        return 1;
    }
    else {
        system("cls");
        cout << "Nu se poate deschide fisierul " << employs_filename << " pentru salvare.\n";
        return 0;
    }
}



int organization::load_employes_from_file() {
    ifstream file(employs_filename);
    if (file.is_open()) {
        students.clear();
        size_t size;
        file >> size;
        file.ignore();
        for (size_t i = 0; i < size; ++i) {
            employer loadstudent;
            getline(file, loadstudent.name);
            getline(file, loadstudent.surname);
            file >> loadstudent.age;
            file >> loadstudent.mark;
            file >> loadstudent.unversity_id;
            file.ignore();
            students.push_back(loadstudent);
        }
        file.close();

        system("cls");
        return 1;
    }
    else {
        system("cls");
        cout << "Nu se poate deschide fisierul " << employs_filename << " pentru incarcare.\n";
        return 0;
    }
}