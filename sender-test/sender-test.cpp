 // This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include"catch.hpp"
#include"fileArray.h"
#include"ColumnFilter.h"

#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
TEST_CASE("Reports true when argument count equal to one")
{
	REQUIRE(FileArray::checkIfArgumentCountLessThanOne(1) == true);
}
TEST_CASE("Reports True when array is empty")
{

	REQUIRE(FileArray::checkIfFileArrayIsEmpty({}) == 1);
}
TEST_CASE("when ifstream object and correct file name is given then return false")
{
	ifstream fin;
	REQUIRE(FileArray::isFileNotOpen(fin, "sample-review-data.csv")==false);

}
TEST_CASE("when ifstream object and incorrect file name is given then return true")
{
	ifstream fin;
	REQUIRE(FileArray::isFileNotOpen(fin, "harish.csv") == true);

}
TEST_CASE("when stringstream is given then report it in vector form of string")
{
	string sentence = "01/03/2019,hello how are you";
	vector<string>row = { "01/03/2019","hello how are you" };
	stringstream s(sentence);
	ifstream fin;
	FileArray::CSVFileArrayCreator csvFile(fin);
	REQUIRE(csvFile.pushWordsToRowVector(s)== row);

}

TEST_CASE("when csv File is given  then report the file in vector form" )
{
	vector<vector<string>> csv_vector = { {"01/01/2018","good work"},{"03/08/2018","modify readme"},{"05/05/2019","No changes"}};
	ofstream fout;
	fout.open("test.csv", ios::out|ios::trunc);
	fout << "01/01/2018" << "," << "good work" << "\n";
	fout << "," << "\n";
	fout << "03/08/2018" << "," << "modify readme" << "\n";
	fout << "05/05/2019" << "," << "No changes" << "\n";
	fout.close();
	ifstream fin;
	fin.open("test.csv", ios::in);
	FileArray::FileArrayCreator *filecreator = new(nothrow)FileArray::CSVFileArrayCreator(fin);
	REQUIRE(filecreator->getFileArray() == csv_vector);


}
TEST_CASE("when the column number and 2D vector of strings"
	"are given then report vector with corresponding column of strings")
{
	vector<vector<string>> csv_vector = { {"01/01/2018","good work"},{"03/08/2018","modify readme"},{"05/05/2019","No changes"} };
	ColumnFilter::ColumnFilter CF(csv_vector, 2);
	vector<string> expectedColumn = { "good work","modify readme","No changes" };
	REQUIRE(CF.getColumn() == expectedColumn);
}


