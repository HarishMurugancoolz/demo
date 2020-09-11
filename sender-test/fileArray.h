#include<vector>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
namespace FileArray
{
	class FileToArrayCreator
	{
	private:
		string line, word,temp;
		vector<string> row;
		vector<vector<string>> csv_file_array;
	public:
		vector<string> pushWordsToRowVector(stringstream& s)
		{
			
			while (getline(s, word,','))
			{
				row.push_back(word);
				
			}
			return row;
		}
		vector<vector<string>> createFileArray(istream& fin)
		{
			while (getline(fin, line, '\n'))
			{
				stringstream s(line);
				row = pushWordsToRowVector(s);
				csv_file_array.push_back(row);
				row.clear();

			}
			return csv_file_array;
		}
		void printReview(vector<vector<string>>& csv_file_array) const
		{
			for (unsigned int i_col = 0; i_col < csv_file_array[i_col].size(); i_col++)
			{
				for (unsigned int i_row = 0; i_row < csv_file_array.size(); i_row++)
				{
					cout << csv_file_array[i_row][i_col] << " ";
				}
			}
		}


	};
}
