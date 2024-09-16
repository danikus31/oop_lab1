


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
        cout << "5. Salvare datele\n";
        cout << "6. Incarcare datele\n";
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
            break;
        case 5:
            if (universitys.save_to_file() && students.save_to_file()) {
                cout << "Date au fost salvate cu succes!\n\n";
            }
            break;
        case 6:
            if (universitys.load_from_file() && students.load_from_file()) {
                cout << "Datele au fost incarcate cu succes!\n\n";
            }
            break;
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
