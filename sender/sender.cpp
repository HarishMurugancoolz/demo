#include<iostream>
#include<vector>
#include<fstream>
#include"fileArray.h"
#include"ColumnFilter.h"
#include"catch.hpp"
using namespace std;



int main(int argc,char*argv[])
{
	ifstream fin;
	fin.open(argv[1], ios::in);
	if (!fin.is_open())
	{
		cout << "file cant be opened" << endl;
		exit(1);
	}
	FileArray::FileArrayCreator createArray(fin);
	
	vector<vector<string>> csvFileArray;
	csvFileArray =createArray.getFileArray();
	fin.close();
	
	if (argc>2&&argv[2] != NULL)
	{
		vector<string> ColumnReview;
		int col_number = stoi(argv[2]);
		ColumnFilter::ColumnFilter colFilter(csvFileArray,col_number);
		ColumnReview=colFilter.getColumn();
		colFilter.printColumnReview();
	}
	else 
	{
		createArray.printReview();
	}
	
}
