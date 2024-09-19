#include "connection.cpp"
#include "organization.h"

int main() {

    organization universitys;

    int menuOption;
    system("cls");
    do {
        cout << "\nIntroduceti optiunea dorita:\n";
        cout << "1. Afisare universitati\n";
        cout << "2. Adauga o universitate\n";
        cout << "3. Editarea unei universitati\n";
        cout << "4. Afisati studentii\n";
        cout << "5. Adaugati un student\n";
        cout << "6. editarea unui student\n";
        cout << "7. Salvare datele\n";
        cout << "8. Incarcare datele\n";
        cout << "0. Iesire\n";
        cout << "Optiune: ";
        cin >> menuOption;

        switch (menuOption) {
        case 1:
            universitys.showBildings();
            break;
        case 2:
            universitys.addNewBilding();
            break;
        case 3:
            universitys.edditBilding();
            break;
        case 4:
            universitys.showEmploys();
            break;
        case 5:
            universitys.addNewEmploys();
            break;
        case 6:
            universitys.edditEmploer();
            break;
        case 7:
            if (universitys.save_Bildings_to_file() && universitys.save_employes_to_file()) {
                cout << "Date au fost salvate cu succes!\n\n";
            }
            break;
        case 8:
            if (universitys.load_Bildings_from_file() && universitys.load_employes_from_file()) {
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
