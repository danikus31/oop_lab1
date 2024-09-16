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

};