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
		vector<string> pushWordsToRowVector(stringstream& s)
		{
			
			while (getline(s, word,','))
			{
				row.push_back(word);
				
			}
			return row;
		}
		vector<vector<string>> getFileArray()
		{
			while (getline(fin, line, '\n'))
			{
				stringstream s(line);
				row = pushWordsToRowVector(s);
				csvFileArray.push_back(row);
				row.clear();

			}
			return csvFileArray;
		}
		void printReview() const
		{
			for (unsigned int i_col = 0; i_col < csvFileArray[i_col].size(); i_col++)
			{
				for (unsigned int i_row = 0; i_row < csvFileArray.size(); i_row++)
				{
					cout << csvFileArray[i_row][i_col] << " ";
				}
			}
		}


	};
}
