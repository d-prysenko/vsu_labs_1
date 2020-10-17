#include <iostream>
#include "misc.h"

int main1()
{
	setlocale(LC_ALL, "ru");

	const char CIPHER_FILENAME[] = "inp1.txt";
	const char DECODE_FILENAME[] = "inp2.txt";

	const size_t mSize = getMatrixSizeFromFile(CIPHER_FILENAME);

	wchar_t** cyphertext = new wchar_t* [mSize];
	wchar_t** decodegrid = new wchar_t* [mSize];

	initArray(cyphertext, mSize);
	initArray(decodegrid, mSize);

	fileToMatrix(CIPHER_FILENAME, cyphertext, mSize);
	fileToMatrix(DECODE_FILENAME, decodegrid, mSize);

	printMatrix(cyphertext, mSize); cout << endl;
	printMatrix(decodegrid, mSize); cout << endl;

	for (int l = 0; l < 4; l++)
	{
		for (int i = 0; i < mSize; i++)
			for (int j = 0; j < mSize; j++)
			{
				size_t row = 0, col = 0;
				getIndex(i, j, row, col, mSize);
				if (decodegrid[row][col] == '0')
					wcout << cyphertext[i][j];
			}

		rotateIndex();
	}

	deleteArray(cyphertext, mSize);
	deleteArray(decodegrid, mSize);

	delete[] cyphertext;
	delete[] decodegrid;

	cout << "\n\n";

	system("pause");
 	return 0;
}
