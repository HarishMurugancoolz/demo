#pragma once
#include<vector>
#include<string>
#include<map>
#include<iostream>
using namespace std;
namespace ColumnFilter
{
	class ColumnFilter
	{
	private:
		vector<string> ColumnReview;
		vector<vector<string>> csvFileArray;
		int col_number;
	public:
		ColumnFilter(vector<vector<string>> CFA,int col_num):csvFileArray(CFA),col_number(col_num){}

		vector<string> getColumn()
		{
			for (unsigned int i_row = 0; i_row < csvFileArray.size(); i_row++)
			{
				ColumnReview.push_back(csvFileArray[i_row][col_number-1]);
			}
			return ColumnReview;
		}
		void printColumnReview() const
		{
			for (unsigned int i_word = 0; i_word < ColumnReview.size(); i_word++)
			{
				cout << ColumnReview[i_word] << " ";
			}
		}

		
	};
}
