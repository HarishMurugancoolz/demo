
#include<iostream>
#include<vector>
#include<fstream>
#include"fileToArrayConverter.h"
#include"ColumnFilter.h"
using namespace std;


void MessageWhenFileNameNotEntered(int argc)
{
	if (FileToArrayConverter::IsArgumentCountEqaulToOne(argc))
	{
		cerr << "File name not passsed" << endl;
		exit(1);
	}
}
void MessageWhenFileIsNotOpen(ifstream& fin, char* argv[])
{
	if (FileToArrayConverter::IsFileNotOpen(fin, argv[1]))
	{
		cerr << "File cannot be opened" << endl;
		exit(1);
	}
}
void MessageWhenFileIsEmpty(vector<vector<string>> csvFileArray)
{
	if (FileToArrayConverter::IsFileArrayIsEmpty(csvFileArray))
	{
		cerr << "File is Empty" << endl;
		exit(1);
	}
}
void MessageWhenIncorrectColumnNumberIsEntered(vector<vector<string>> csvFileArray, string colNum)
{
	if (!(ColumnFilter::IsColumnNumberCorrect(csvFileArray, colNum)))
	{
		cerr << "Incorrect Column Number" << endl;
		exit(1);
	}
}

	
int main(int argc,char*argv[])
{
	ifstream fin;
	
	MessageWhenFileNameNotEntered(argc);
	MessageWhenFileIsNotOpen(fin,argv);
	FileToArrayConverter::FileToArrayConverter *filepointer;
	filepointer= new(nothrow)FileToArrayConverter::CSVFileToArrayConverter(fin);
	vector<vector<string>> csvFileArray;

	if(filepointer!=NULL)
		csvFileArray = filepointer->getFileArray();
	MessageWhenFileIsEmpty(csvFileArray);
	fin.close();

	vector<string> ColumnReview;
	
	if (argc > 2)
	{
		MessageWhenIncorrectColumnNumberIsEntered(csvFileArray, argv[2]);
		int colNum = stoi(argv[2]);
		ColumnFilter::ColumnFilter colFilter(csvFileArray,colNum);
		ColumnReview = colFilter.getColumn();
		ColumnFilter::printColumnReview(ColumnReview);
	}
	else 
		FileToArrayConverter::printReview(csvFileArray);
	return 0;
	
	
}