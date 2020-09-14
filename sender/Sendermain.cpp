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
	if (FileArray::IsArgumentCountEqaulToOne(argc))
	{
		cout << "File name not passsed" << endl;
		exit(0);
	}
}
void MessageWhenFileIsNotOpen(ifstream& fin, char* argv[])
{
	if (FileArray::IsFileNotOpen(fin, argv[1]))
	{
		cout << "File cannot be opened" << endl;
		exit(0);
	}
}
void MessageWhenFileIsEmpty(vector<vector<string>> csvFileArray)
{
	if (FileArray::IsFileArrayIsEmpty(csvFileArray))
	{
		cout << "File is Empty" << endl;
		exit(0);
	}
}
void MessageWhenIncorrectColumnNumberIsEntered(vector<vector<string>> csvFileArray, int colNum)
{
	if (!(ColumnFilter::IsColumnNumberWithinLimit(csvFileArray, colNum)))
	{
		cout << "Incorrect Column Number" << endl;
		exit(0);
	}
}

	
int main(int argc,char*argv[])
{
	ifstream fin;
	MessageWhenFileNameNotEntered(argc);
	MessageWhenFileIsNotOpen(fin,argv);
	FileArray::FileArrayCreator *filepointer;
	filepointer= new(nothrow)FileArray::CSVFileArrayCreator(fin);
	vector<vector<string>> csvFileArray;
	if(filepointer!=NULL)
		csvFileArray = filepointer->getFileArray();
	MessageWhenFileIsEmpty(csvFileArray);
	fin.close();
	vector<string> ColumnReview;
	
	if (argc > 2)
	{
		int colNum = stoi(argv[2]);
		MessageWhenIncorrectColumnNumberIsEntered(csvFileArray, colNum);
		ColumnFilter::ColumnFilter colFilter(csvFileArray,colNum);
		ColumnReview = colFilter.getColumn();
		ColumnFilter::printColumnReview(ColumnReview);
	}
	else 
		FileArray::printReview(csvFileArray);
	return 0;
	
	
}