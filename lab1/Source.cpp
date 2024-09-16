#include "connection.cpp"
#include "organization.h"
#include "people.h"

int main() {

    organization universitys;
    people students;

    int menuOption;
    system("cls");
    do {
        cout << "\nIntroduceti optiunea dorita:\n";
        cout << "1. Afisare universitati\n";
        cout << "2. Adauga o universitate\n";
        cout << "3. Afisati studentii\n";
        cout << "4. Adaugati un student\n";
        cout << "5. Salvare tabel in fisier\n";
        cout << "6. Incarcare tabel din fisier\n";
        cout << "0. Iesire\n";
        cout << "Optiune: ";
        cin >> menuOption;

        switch (menuOption) {
        case 1:
            universitys.show();
            break;
        case 2:
            universitys.add_new();
            break;
        case 3:
            students.show();
            break;
        case 4:
            students.add_new();
        case 0:
            cout << "Iesire...\n";
            break;
        default:
            cout << "Optiune invalida. Incercati din nou.\n";
            break;
        }

    } while (menuOption != 0);

    return 0;

}



/*
	VariadicTable<std::string, double, int, std::string> vt({ "Name", "Weight", "Age", "Brother" }, 10);

	vt.addRow("Cody", 180.2, 40, "John");
	vt.addRow("David", 175.3, 38, "Andrew");
	vt.addRow("Robert", 140.3, 27, "Fande");

	vt.print(std::cout);
	
	
*/