#pragma once
#include "connection.cpp"

class organization
{
private:
	vector<Bilding> universitys;
public:
	string filename = "univertys.txt";
	void add_new();
	void show();
	int save_to_file();
	int load_from_file();
};