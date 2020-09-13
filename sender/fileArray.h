

#include<vector>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
namespace FileArray
{
	class FileArrayCreator
	{
	private:
		string line, word;
		vector<string> row;
		vector<vector<string>> csvFileArray;
		istream& fin;
	public:
		FileArrayCreator(istream& f):fin(f){}
		bool isLineEmpty(string line)
		{
			return(line == ","||line=="");
		}
		vector<string> pushWordsToRowVector(stringstream& s)
		{
			while (s.good())
			{
				string substr;
				getline(s, substr, ',');
				row.push_back(substr);
			}
			return row;
		}
		vector<vector<string>> getFileArray()
		{
			while (getline(fin, line, '\n'))
			{
				stringstream s(line);
				if (!isLineEmpty(line))
				{
					row = pushWordsToRowVector(s);
					csvFileArray.push_back(row);
					row.clear();
				}

			}
			return csvFileArray;
		}
		
		
	};
	bool checkIfArgumentCountLessThanOne(int argc);
	bool checkIfFileArrayIsEmpty(vector<vector<string>> csvFileArray);
	bool isFileNotOpen(ifstream& fin,string fileName);
	void printReview(vector<vector<string>> csvFileArray);
}
