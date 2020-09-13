#include"ColumnFilter.h"
#include<vector>
#include<string>
using namespace std;
void ColumnFilter::getColumnReview(vector<vector<string>> csvFileArray,  int colNum)
{
		vector<string> ColumnReview;
		ColumnFilter colFilter(csvFileArray, colNum);
		ColumnReview = colFilter.getColumn();
		colFilter.printColumnReview();
	
}
