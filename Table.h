#pragma once
#include <iostream>
using namespace std;
class Table
{
public:
	Table(int n = 0, int m = 0);
	~Table();
	void const print();
	void setTable();
	char** matrix;
private:
	int redove;
	int koloni;
};
