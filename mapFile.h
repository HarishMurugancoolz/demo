#pragma once
#include<map>
#include<vector>
#include<string>
using namespace std;
namespace mapFile
{
	class vectorToMap
	{
	private:
		map<int, vector<string>> columnReview;
		vector<string> columnContent;
	public:

		vector<string>& pushColumnToVector(const int i_col, vector<vector<string>>& csv_file_array)
		{
			for (unsigned int i_row = 0; i_row < csv_file_array.size(); i_row++)
			{
				columnContent.push_back(csv_file_array[i_row][i_col]);
			}
			return columnContent;
		}
		map<int, vector<string>> mapFileToColumnWise(vector<vector<string>> csv_file_array)
		{
			int column_number = 1;
			for (unsigned int i_col = 0; i_col < csv_file_array[i_col].size(); i_col++)
			{
				columnReview[column_number] = pushColumnToVector(i_col, csv_file_array);
				columnContent.clear();
				column_number++;
			}
			return columnReview;
		}
	};
}
