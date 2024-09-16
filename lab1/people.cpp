#include "people.h"



void people::show()
{
    system("cls");
    if (students.size()) {
        cout << students.size();

        cout << "Count of students = " << students.size() << "\n";
        VariadicTable<string, string,short, short, short> vt({ "Name", "Surname", "age", "mark", "university"}, 10);
        for (size_t i = 0; i < students.size(); ++i) {
            vt.addRow(students[i].name, students[i].surname, students[i].mark, students[i].age, students[i].unversity_id);
        }
        vt.print(std::cout);

}
    else {
        cout << "no students\n\n\n";
    }
    pressToMenu();
}


void people::add_new()
{
    system("cls");
    employer new_student;
    cout << "Introduceti Numele\n";
    cin >> new_student.name;
    cout << "Introduceti Prenomele\n";
    cin >> new_student.surname;
    cout << "Indtroduceti visrta\n";
    cin >> new_student.age;
    cout << "Introduceti nota media\n";
    cin >> new_student.mark;

    cout << "Introduceti Universitatea\n";
    cin >> new_student.unversity_id;
    



    students.push_back(new_student);

    system("cls");
}




int people::save_to_file()
{
    ofstream file(filename);
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
        cout << "Nu se poate deschide fisierul " << filename << " pentru salvare.\n";
        return 0;
    }
}



int people::load_from_file() {
    ifstream file(filename);
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
        cout << "Nu se poate deschide fisierul " << filename << " pentru incarcare.\n";
        return 0;
    }
}