#include "organization.h"


void organization::show()
{
    system("cls");
    if (universitys.size()) {
        cout <<"Total universitys: "<< universitys.size() << "\n";
        VariadicTable<string, short> vt({ "Name", "founders name" }, 10);
        for (size_t i = 0; i < universitys.size(); ++i) {
            vt.addRow(universitys[i].name, universitys[i].fyear);
        }
        vt.print(std::cout);
    }
    else {
        cout << "NO UNIVERSITYES\n\n\n";
    }
    pressToMenu();
}


void organization::add_new()
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




int organization::save_to_file()
{
    ofstream file(filename);
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
        cout << "Nu se poate deschide fisierul " << filename << " pentru salvare.\n";
        return 0;
    }
}



int organization::load_from_file() {
    ifstream file(filename);
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
        cout << "Nu se poate deschide fisierul " << filename << " pentru incarcare.\n";
        return 0;
    }
}