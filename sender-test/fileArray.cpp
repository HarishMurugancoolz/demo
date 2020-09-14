#include<vector>
#include<string>
#include<fstream>
#include"fileArray.h"
using namespace std;
bool FileArray::IsFileNotOpen(ifstream&fin, string fileName)
{
	fin.open(fileName,ios::in);
	return(!fin.is_open());
}
bool FileArray::IsFileArrayIsEmpty(vector<vector<string>> csvFileArray)
{
	return (csvFileArray.size() == 0);
}
bool FileArray::IsArgumentCountEqaulToOne(int argc)
{
	return (argc <= 1);

}
void  FileArray::printReview(vector<vector<string>> csvFileArray) 
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
