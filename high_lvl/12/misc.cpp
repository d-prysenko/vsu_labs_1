#include "misc.h"


void initArray(wchar_t** array, size_t size)
{
	for (size_t i = 0; i < size; i++)
		array[i] = new wchar_t[size];
}

void deleteArray(wchar_t** array, size_t size)
{
	for (size_t i = 0; i < size; i++)
		delete[] array[i];
}

size_t getMatrixSizeFromFile(const char* filename)
{
	wifstream wif(filename);
	if (!wif.is_open())
		return 0;

	wif.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));

	size_t size = 0;
	wchar_t temp;

	while (!wif.eof() && !wif.bad() && (temp = wif.get()) != L'\n')
		if (temp != L' ')
			size++;

	wif.close();

	return size;
}

int fileToMatrix(const char* filename, wchar_t** out, size_t size)
{
	wifstream wif(filename);
	if (!wif.is_open())
		return -1;

	wif.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));

	size_t	i = 0,
			j = 0;

	while (!wif.eof() && !wif.bad())
	{
		wchar_t curChar = wif.get();
		if (curChar == L' ')
			continue;			// Не уверен в использовании continue при кодревью, но в The C Programming Language в подобных местах используется continue
		if (curChar == L'\n')
		{
			i++;
			j = 0;
			continue;
		}

		out[i][j++] = curChar;
	}

	wif.close();
	return 0;
}

void printMatrix(wchar_t** matrix, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			wcout << matrix[i][j] << " ";
		cout << endl;
	}
}

void getIndex(size_t row, size_t col, size_t& out_row, size_t& out_col, size_t size)
{
	switch (rotItr)
	{
	case 0:
		out_col = col;
		out_row = row;
		break;
	case 1:
		out_col = row;
		out_row = size - 1 - col;
		break;
	case 2:
		out_col = size - 1 - col;
		out_row = size - 1 - row;
		break;
	case 3:
		out_col = size - 1 - row;
		out_row = col;
		break;

	default:
		break;
	}
}

void rotateIndex()
{
	rotItr++;
	rotItr %= 4;
}
