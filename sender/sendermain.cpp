//#define CATCH_CONFIG_RUNNER
//#include"catch.hpp"
#include<iostream>
#include<vector>
#include<fstream>
#include"fileArray.h"
#include"ColumnFilter.h"
using namespace std;
bool checkIfArgumentCountLessThanOne(int argc)
{
	return (argc <= 1);
	
}
bool checkIfFileIsEmpty(vector<vector<string>> csvFileArray)
{
	return (csvFileArray.size() == 0);
}
	
int main(int argc,char*argv[])
{
	ifstream fin;
	
	if (checkIfArgumentCountLessThanOne(argc))
	{
		cout << "File name not passsed" << endl;
		exit(0);
	}
	if (FileArray::isFileNotOpen(fin, argv[1]))
	{
		cout << "File cannot be opened" << endl;
		exit(0);
	}
	
	FileArray::FileArrayCreator filearraycreator(fin);
	vector<vector<string>> csvFileArray = filearraycreator.getFileArray();
	if (checkIfFileIsEmpty(csvFileArray))
	{
		cout << "File is Empty" << endl;
	};
	fin.close();
	if (argc>2)
		ColumnFilter::getColumnReview(csvFileArray,stoi(argv[2]));
	else 
		FileArray::printReview(csvFileArray);
	return 0;
	
	
}
