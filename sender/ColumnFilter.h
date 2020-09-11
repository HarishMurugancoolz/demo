#pragma once
#include<vector>
#include<string>
#include<map>
#include<iostream>
using namespace std;
namespace columnFilter
{
	class columnFilter
	{
	private:
		vector<string> specifiedColumnReview;
	public:
		
		vector<string> getColumn(vector<vector<string>> csv_file_array, int given_col_number)
		{
			for (unsigned int i_row = 0; i_row < csv_file_array.size(); i_row++)
			{
				specifiedColumnReview.push_back(csv_file_array[i_row][given_col_number-1]);
			}
			return specifiedColumnReview;
		}

		void printColumnReview(vector<string> columnReview) const
		{
			for (unsigned int i_word = 0; i_word < columnReview.size(); i_word++)
			{
				cout << columnReview[i_word] << " ";
			}
		}
	};
}
