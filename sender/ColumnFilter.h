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
		int zeroBasedColumnNumber;
	public:
		ColumnFilter(vector<vector<string>>& CFA,int col_num):csvFileArray(CFA),col_number(col_num){}
		bool isStringNotEmpty(string str)
		{
			return(!str.empty());
		}
		vector<string> getColumn()
		{
			zeroBasedColumnNumber = col_number-1;
			string reviewContent;
			for(unsigned int i_row = 0; i_row < csvFileArray.size(); i_row++)
			{
				vector<string> sub(csvFileArray[i_row]);
				sub.push_back("");
				reviewContent = sub.at(zeroBasedColumnNumber);
				if(isStringNotEmpty(reviewContent))
					ColumnReview.push_back(reviewContent);
			}
			
			return ColumnReview;
		}
		
	};
	bool IsColumnNumberWithinLimit(vector <vector<string>> csvFileArray, int col);
	void printColumnReview(vector<string> ColumnReview);
}