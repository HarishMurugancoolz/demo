  // This tells Catch to provide a main() - only do this in one cpp file

#include<iostream>
#include<vector>
#include<fstream>
#include"fileArray.h"
#include"ColumnFilter.h"
using namespace std;

int main(int argc,char*argv[])
{
	ifstream fin;
	fin.open(argv[1], ios::in);
	if (!fin.is_open())
	{
		cout << "file cant be opened" << endl;
	}
	FileArray::FileToArrayCreator csvFile;
	vector<vector<string>> csv_file_array;
	csv_file_array =csvFile.createFileArray(fin);
	vector<string> specifiedColumnReview;
	if (argv[2] != NULL)
	{
		int given_col_number = stoi(argv[2]);
		columnFilter::columnFilter colfilter;
		specifiedColumnReview = colfilter.getColumn( csv_file_array, given_col_number);
		colfilter.printColumnReview(specifiedColumnReview);
	}
	else
	{
		csvFile.printReview(csv_file_array);
	}
}
