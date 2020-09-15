
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
namespace FileToArrayConverter
{
	class FileToArrayConverter
	{
	public:
		virtual vector<vector<string>> getFileArray() = 0;
	};
	class CSVFileToArrayConverter:public FileToArrayConverter
	{
	private:
		vector<string> row;
		vector<vector<string>> csvFileArray;
		istream& fin;
	public:
		CSVFileToArrayConverter(ifstream& f):fin(f){}
		bool isLineNotEmpty(string line)
		{
			return(!(line == ","||line.length()==0));
		}
		bool isLineNotContainComma(string line)
		{
			for (unsigned int i = 0; i < line.length(); i++)
			{
				if (line[i] == ',')
					return false;

			}
			return true;
		}
		
		void pushWordsToRowVector(vector<string>& row, string line)
		{
			if (isLineNotContainComma(line))
			{
				row.push_back("");
			}
			stringstream s(line);
			while (s.good())
			{
				string substr;
				getline(s, substr, ',');
				row.push_back(substr);
			}
		}
		vector<vector<string>> getFileArray()
		{
			string line;
			vector<string> row;
			while (getline(fin, line, '\n'))
			{
				if (isLineNotEmpty(line))
				{
					pushWordsToRowVector(row,line);
					csvFileArray.push_back(row);
					row.clear();
				}

			}
			return csvFileArray;
		}
		
		
	};
	bool IsArgumentCountEqaulToOne(int argc);
	bool IsFileArrayIsEmpty(vector<vector<string>> csvFileArray);
	bool IsFileNotOpen(ifstream& fin,string fileName);
	void printReview(vector<vector<string>> csvFileArray);
}

{
	class FileArrayCreator
	{
	public:
		virtual vector<vector<string>> getFileArray() = 0;
	};
	class CSVFileArrayCreator:public FileArrayCreator
	{
	private:
		vector<string> row;
		vector<vector<string>> csvFileArray;
		istream& fin;
	public:
		CSVFileArrayCreator(istream& f):fin(f){}
		bool isLineNotEmpty(string line)
		{
			return(!(line == ","||line==""));
		}
		bool isLineNotContainComma(string line)
		{
			for (unsigned int i = 0; i < line.length(); i++)
			{
				if (line[i] == ',')
					return false;

			}
			return true;
		}
		
		void pushWordsToRowVector(vector<string>& row, string line)
		{
			if (isLineNotContainComma(line))
				row.push_back("");
			stringstream s(line);
			while (s.good())
			{
				string substr;
				getline(s, substr, ',');
				row.push_back(substr);
			}
		}
		vector<vector<string>> getFileArray()
		{
			string line;
			vector<string> row;
			while (getline(fin, line, '\n'))
			{
				if (isLineNotEmpty(line))
				{
					pushWordsToRowVector(row,line);
					csvFileArray.push_back(row);
					row.clear();
				}

			}
			return csvFileArray;
		}
		
		
	};
	bool IsArgumentCountEqaulToOne(int argc);
	bool IsFileArrayIsEmpty(vector<vector<string>> csvFileArray);
	bool IsFileNotOpen(ifstream& fin,string fileName);
	void printReview(vector<vector<string>> csvFileArray);
}
