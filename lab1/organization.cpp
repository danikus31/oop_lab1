#include "organization.h"


void organization::show()
{
    system("cls");

    if (universitys.size()) {
        cout << universitys.size();
        VariadicTable<string, short> vt({ "Name", "founders name" }, 10);
        for (size_t i = 0; i < universitys.size(); ++i) {
            vt.addRow(universitys[i].name, universitys[i].fyear);
        }
        vt.print(std::cout);



    }
    else {
        cout << "no universityes\n\n\n";
    }
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
}

