#pragma once
#include "connection.cpp"

class people
{
private:
	vector<employer> student;
public:
	string filename = "students.txt";
	void add_new();
	void show();

};

