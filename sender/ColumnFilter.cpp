#include"ColumnFilter.h"
#include<vector>
#include<string>
using namespace std;

void ColumnFilter::printColumnReview(vector<string> ColumnReview)
{
	vector<string>::iterator string_itr = ColumnReview.begin();
	while (string_itr != ColumnReview.end())
	{
		cout << *string_itr;
		cout << endl;
		string_itr++;
	}
}
bool ColumnFilter::IsColumnNumberWithinLimit(vector <vector<string>> csvFileArray,int colNum)
{
	
	return(colNum>0&&colNum<=(int)csvFileArray[0].size());
}


