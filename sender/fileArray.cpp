#include<vector>
#include<string>
#include<fstream>
#include"fileArray.h"
using namespace std;
bool FileArray::isFileNotOpen(ifstream&fin, string fileName)
{
	fin.open(fileName,ios::in);
	return(!fin.is_open());
}
bool FileArray::checkIfFileArrayIsEmpty(vector<vector<string>> csvFileArray)
{
	return (csvFileArray.size() == 0);
}
bool FileArray::checkIfArgumentCountLessThanOne(int argc)
{
	return (argc <= 1);

}
void FileArray::printReview(vector<vector<string>> csvFileArray) 
{
	
		for (unsigned int i_row = 1; i_row < csvFileArray.size(); i_row++)
		{
			for (unsigned int i_col = 0; i_col < csvFileArray[i_col].size(); i_col++)
			{
				cout << csvFileArray[i_row][i_col] << " ";
			}
			cout << endl;
		}
		
	
}
