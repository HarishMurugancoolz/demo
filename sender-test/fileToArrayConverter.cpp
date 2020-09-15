#include<vector>
#include<string>
#include<fstream>
#include"fileToArrayConverter.h"
using namespace std;
bool FileToArrayConverter::IsFileNotOpen(ifstream&fin, string fileName)
{
	fin.open(fileName,ios::in);
	return(!fin.is_open());
}
bool FileToArrayConverter::IsFileArrayIsEmpty(vector<vector<string>> csvFileArray)
{
	return (csvFileArray.size() == 0);
}
bool FileToArrayConverter::IsArgumentCountEqaulToOne(int argc)
{
	return (argc <= 1);

}
void  FileToArrayConverter::printReview(vector<vector<string>> csvFileArray)
{
	for (unsigned int i_row = 0; i_row < csvFileArray.size(); i_row++) 
	{
			vector<string>::iterator i_col_itr = csvFileArray[i_row].begin();
			while (i_col_itr != csvFileArray[i_row].end())
			{
				cout << *i_col_itr << " ";
				i_col_itr++;
			}
			cout << endl;
		
	}
	
}
