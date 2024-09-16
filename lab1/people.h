#pragma once
#include "connection.cpp"

class people
{
private:
	vector<employer> students;
public:
	string filename = "students.txt";
	void add_new();
	void show();
	int save_to_file();
	int load_from_file();

};

