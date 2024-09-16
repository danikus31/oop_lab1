#include "people.h"



void people::show()
{
    system("cls");
    if (student.size()) {
        cout << student.size();

        cout << "Count of students = " << student.size() << "\n";
        VariadicTable<string, string,short, short, short> vt({ "Name", "Surname", "age", "mark", "university"}, 10);
        for (size_t i = 0; i < student.size(); ++i) {
            vt.addRow(student[i].name, student[i].surname, student[i].mark, student[i].age, student[i].inversity_id);
        }
        vt.print(std::cout);

}
    else {
        cout << "no students\n\n\n";
    }
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
    cin >> new_student.inversity_id;
    



    student.push_back(new_student);
}