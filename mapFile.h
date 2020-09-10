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
		/*vector<string> pushColumnToVector(vector<string> col_itr)
		{
			vector<string>::iterator word_itr = col_itr.begin();
			while (word_itr != col_itr.end())
			{
				specifiedColumnReview.push_back(*word_itr);
				word_itr++;
			}
			return specifiedColumnReview;

		}*/
		vector<string> getColumn(map<int, vector<string>> column_review, int given_col_number)
		{
			map<int, vector<string>>::iterator col_itr = column_review.begin();
			col_itr = column_review.find(given_col_number);
			if (col_itr != column_review.end())
			{
				specifiedColumnReview = col_itr->second;
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
