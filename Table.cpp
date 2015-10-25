#include "stdafx.h"
#include "Table.h"


Table::Table(int n , int m)
{
	redove = n + 2;
	koloni = m + 2;
	matrix = new char*[redove];
	for (int i = 0; i < redove; i++)
		matrix[i] = new char[koloni];
	for (int i = 0; i < redove; i++)
	for (int j = 0; j < koloni; j++)
		if(i == 0 || i == redove - 1 || j == 0 || j == koloni - 1 )
			matrix[i][j] = '7';
		else matrix[i][j] = 'a';
}


Table::~Table()
{
	for (int i = 0; i < redove; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void const Table::print()
{
	for (int i = 1; i < redove - 1; i++)
	{
		for (int j = 1; j < koloni - 1; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void Table::setTable()
{
	for (int i = 1; i < redove - 1; i++)
	for (int j = 1; j < koloni - 1; j++)
		cin >> matrix[i][j];
}
