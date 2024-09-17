#pragma once
#include "connection.cpp"



class organization
{
	
private:
	vector<Bilding> universitys;
	vector<employer> students;
public:
	string bilding_filename = "univertys.txt";
	string employs_filename = "students.txt";
	void addNewBilding();
	void addNewEmploys();
	void showBildings();
	void showEmploys();
	int save_Bildings_to_file();
	int load_Bildings_from_file();
	int save_employes_to_file();
	int load_employes_from_file();
};