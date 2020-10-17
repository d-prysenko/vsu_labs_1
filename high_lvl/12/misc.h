#pragma once
#include <iostream>
#include <fstream>
#include <codecvt>

using std::wifstream;
using std::locale;
using std::codecvt_utf8;
using std::cout;
using std::wcout;
using std::endl;

static char rotItr = 0;

void initArray(wchar_t** array, size_t size);
void deleteArray(wchar_t** array, size_t size);

size_t getMatrixSizeFromFile(const char* filename);
int fileToMatrix(const char* filename, wchar_t** out, size_t size);
void printMatrix(wchar_t** matrix, size_t size);

void getIndex(size_t row, size_t col, size_t& out_row, size_t& out_col, size_t size);
void rotateIndex();
