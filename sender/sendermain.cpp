//#define CATCH_CONFIG_RUNNER
//#include"catch.hpp"
#include<iostream>
#include<vector>
#include<fstream>
#include"fileArray.h"
#include"ColumnFilter.h"
using namespace std;


void MessageWhenFileNameNotEntered(int argc)
{
	if (FileArray::checkIfArgumentCountLessThanOne(argc))
	{
		cout << "File name not passsed" << endl;
		exit(0);
	}
}
void MessageWhenFileIsNotOpen(ifstream& fin, char* argv[])
{
	if (FileArray::isFileNotOpen(fin, argv[1]))
	{
		cout << "File cannot be opened" << endl;
		exit(0);
	}
}
void MessageWhenFileIsEmpty(vector<vector<string>> csvFileArray)
{
	if (FileArray::checkIfFileArrayIsEmpty(csvFileArray))
	{
		cout << "File is Empty" << endl;
	}
}

	
int main(int argc,char*argv[])
{
	ifstream fin;
	MessageWhenFileNameNotEntered(argc);
	MessageWhenFileIsNotOpen(fin,argv);
	FileArray::FileArrayCreator *filepointer = new(nothrow)FileArray::CSVFileArrayCreator(fin);
	vector<vector<string>> csvFileArray = filepointer->getFileArray();
	MessageWhenFileIsEmpty(csvFileArray);
	cout << "No exception" << endl;
	fin.close();
	if (argc>2)
		ColumnFilter::getColumnReview(csvFileArray,stoi(argv[2]));
	else 
		FileArray::printReview(csvFileArray);
	return 0;
	
	
}
