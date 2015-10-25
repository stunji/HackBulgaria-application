// Words.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Table.h"

int br = 0;

void North(char** matrix, int red, int kolona, int length, char* word)
{
	int i = 0;
	for (i = 1;(red - i > 0 && i + 1 < length); i++)
	{
		if (word[1 + i] != matrix[red - i][kolona]) break;
	}
	if(red - i >= 0 && i + 1 == length) br++;
}

void NorthEast(char** matrix, int red, int kolona, int maxKol, int length, char* word)
{
	int i = 0;
	for (i = 1; (red - i > 0 && i + 1 < length && kolona + i < maxKol + 1); i++)
	{
		if (word[1 + i] != matrix[red - i][kolona + i]) break;
	}
	if (red - i >= 0 && i + 1 == length && kolona + i <= maxKol + 1) br++;
}

void East(char** matrix, int red, int kolona, int maxKol, int length, char* word)
{
	int i = 0;
	for (i = 1; (i + 1 < length && kolona + i < maxKol + 1); i++)
	{
		if (word[1 + i] != matrix[red][kolona + i]) break;
	}
	if (i + 1 == length && kolona + i <= maxKol + 1) br++;
}

void SouthEast(char** matrix, int red, int kolona, int maxKol,int maxRed, int length, char* word)
{
	int i = 0;
	for (i = 1; (red + i < maxRed && i + 1 < length && kolona + i < maxKol + 1); i++)
	{
		if (word[1 + i] != matrix[red + i][kolona + i]) break;
	}
	if (red + i <= maxRed + 1 && i + 1 == length && kolona + i <= maxKol + 1) br++;
}

void South(char** matrix, int red, int kolona, int maxRed, int length, char* word)
{
	int i = 0;
	for (i = 1; (red - i < maxRed + 1 && i + 1 < length); i++)
	{
		if (word[1 + i] != matrix[red + i][kolona]) break;
	}
	if (red + i <= maxRed + 1 && i + 1 == length) br++;
}

void SouthWest(char** matrix, int red, int kolona, int maxRed, int length, char* word)
{
	int i = 0;
	for (i = 1; (red + i < maxRed + 1 && i + 1 < length && kolona - i > 0); i++)
	{
		if (word[1 + i] != matrix[red + i][kolona - i]) break;
	}
	if (red + i <= maxRed + 1 && i + 1 == length && kolona - i >= 0) br++;
}

void West(char** matrix, int red, int kolona, int length, char* word)
{
	int i = 0;
	for (i = 1; ( i + 1 < length && kolona - i > 0); i++)
	{
		if (word[1 + i] != matrix[red][kolona - i]) break;
	}
	if (i + 1 == length && kolona - i >= 0) br++;
}

void NorthWest(char** matrix, int red, int kolona, int length, char* word)
{
	int i = 0;
	for (i = 1; (red - i > 0 && i + 1 < length && kolona - i > 0); i++)
	{
		if (word[1 + i] != matrix[red - i][kolona - i]) break;
	}
	if (red - i >= 0 && i + 1 == length && kolona - i >= 0) br++;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int duljina;
	int width, heigth;
	do{
		cout << "Vyvedi validen broi redove: ";
		cin >> heigth;
	} while (heigth < 1);
	do
	{
		cout << "Vyvedi validen broi koloni: ";
		cin >> width;
	} while (width < 1);
	Table masa(heigth, width);
	cout << "Zapulnete masata s " <<width*heigth<<" bukvichki po jelanie"<< endl;
	masa.setTable();
	masa.print();
	do{
		cout << "Vyvedi validna dyljina na dumata: ";
		cin >> duljina;
	} while (duljina < 1);
	char* word = new char[duljina];
	cout << "Sega vyvedete dumata, koqto jelaete: "; 
	cin >> word;
	for (int i = 1; i < heigth + 1; i++)
	{
		for (int j = 1; j < width + 1; j++)
		{
			if (word[0] == masa.matrix[i][j])
			{
				if (duljina > 1)
				{
					if (word[1] == masa.matrix[i - 1][j]) North(masa.matrix, i - 1, j, duljina, word);
					if (word[1] == masa.matrix[i - 1][j + 1]) NorthEast(masa.matrix, i - 1, j + 1, width, duljina, word);
					if (word[1] == masa.matrix[i][j + 1]) East(masa.matrix, i, j + 1, width, duljina, word);
					if (word[1] == masa.matrix[i + 1][j + 1]) SouthEast(masa.matrix, i + 1, j + 1, width, heigth, duljina, word);
					if (word[1] == masa.matrix[i + 1][j]) South(masa.matrix, i + 1, j, heigth, duljina, word);
					if (word[1] == masa.matrix[i + 1][j - 1]) SouthWest(masa.matrix, i + 1, j - 1, heigth, duljina, word);
					if (word[1] == masa.matrix[i][j - 1]) West(masa.matrix, i, j - 1, duljina, word);
					if (word[1] == masa.matrix[i - 1][j - 1]) NorthWest(masa.matrix, i - 1, j - 1, duljina, word);
				}
				else br++;
			}
		}
	}
	cout <<"Dumata '"<<word<<"' se sreshta "<< br << " pyti."<<  endl;
	system("pause");
	return 0;
}
