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
	REQUIRE(FileArray::IsArgumentCountEqaulToOne(1) == true);
}
TEST_CASE("Reports True when array is empty")
{

	REQUIRE(FileArray::IsFileArrayIsEmpty({}) == true);
}
TEST_CASE("when ifstream object and correct file name is given then return false stating"
			"File can be Opened")
{
	ifstream fin;
	REQUIRE(FileArray::IsFileNotOpen(fin, "harishtext.csv")==false);

}
TEST_CASE("when ifstream object and incorrect file name is given then return true"
			"stating File Cant be opened")
{
	ifstream fin;
	REQUIRE(FileArray::IsFileNotOpen(fin, "harish.csv") == true);

}
TEST_CASE("When string with comma is given then report false stating line contains comma")
{
	ifstream fin;
	FileArray::CSVFileArrayCreator csvFile(fin);
	REQUIRE(csvFile.isLineNotContainComma("hello,come") == false);
}
TEST_CASE("When string without comma is given then report true stating line does not "
	"contains comma")
{
	ifstream fin;
	FileArray::CSVFileArrayCreator csvFile(fin);
	REQUIRE(csvFile.isLineNotContainComma("hello come") == true);
}
TEST_CASE("When Empty string or only comma is given then report false stating line is empty")
{
	ifstream fin;
	FileArray::CSVFileArrayCreator csvFile(fin);
	REQUIRE(csvFile.isLineNotEmpty("") == false);
	REQUIRE(csvFile.isLineNotEmpty(",") == false);
}
TEST_CASE("When  string   is given then report true stating line is not empty")
{
	ifstream fin;
	FileArray::CSVFileArrayCreator csvFile(fin);
	REQUIRE(csvFile.isLineNotEmpty("Be positive") == true);
	REQUIRE(csvFile.isLineNotEmpty("10/09/19,Confident") == true);
}
TEST_CASE("when string is given then report it in vector form of string")
{
	string sampleContent = "01/03/2019,hello how are you";
	vector<string> Row; 
	vector<string> expectedRow= { "01/03/2019","hello how are you" };
	ifstream fin;
	FileArray::CSVFileArrayCreator csvFile(fin);
	csvFile.pushWordsToRowVector(Row,sampleContent);
	REQUIRE(Row==expectedRow);

}
TEST_CASE("when string with No comma is given then report it in vector form of string")
{
	string givenString = "hello how are you";
	vector<string> Row;
	vector<string> expectedRow = { "","hello how are you" };
	ifstream fin;
	FileArray::CSVFileArrayCreator csvFile(fin);
	csvFile.pushWordsToRowVector(Row, givenString);
	REQUIRE(Row == expectedRow);

}

TEST_CASE("when csv File is given  then report the file in vector form" )
{
	vector<vector<string>> csv_vector = { {"01/01/2018","good work"},
										{"03/08/2018","modify readme"},
										{"05/05/2019","No changes"}};
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
TEST_CASE("when csv File with sentence continuation in next line"
	"is given  then report the file in vector form")
{
	vector<vector<string>> csv_vector = { {"01/01/2018","good work"},
										{"03/08/2018","modify readme"},
										{"","No changes"} };
	ofstream fout;
	fout.open("test.csv", ios::out | ios::trunc);
	fout << "01/01/2018" << "," << "good work" << "\n";
	fout << "," << "\n";
	fout << "03/08/2018" << "," << "modify readme" << "\n";
	fout << "No changes" << "\n";//previous comment continues in this line
	fout.close();
	ifstream fin;
	fin.open("test.csv", ios::in);
	FileArray::FileArrayCreator *filecreator = new(nothrow)FileArray::CSVFileArrayCreator(fin);
	REQUIRE(filecreator->getFileArray() == csv_vector);


}
TEST_CASE("When empty string is given then report false stating string is not empty")
{
	vector<vector<string>> csvFile;
	ColumnFilter::ColumnFilter colfilter(csvFile, 1);
	REQUIRE(colfilter.isStringNotEmpty("") == false);
}
TEST_CASE("When incorrect Column number is given then report false")
{
	vector<vector<string>> csvFile={{"hello","how"}};
	REQUIRE(ColumnFilter::IsColumnNumberWithinLimit(csvFile, 0) == false);
	
}
TEST_CASE("When correct Column number is given then report true")
{
	vector<vector<string>> csvFile = { {"hello","how"} };
	
	REQUIRE(ColumnFilter::IsColumnNumberWithinLimit(csvFile, 2) == true);
}
TEST_CASE("when the column number and 2D vector of strings"
	"are given then report vector with corresponding column of strings")
{
	vector<vector<string>> csv_vector = { {"01/01/2018","good work"},{"03/08/2018","modify readme"},{"05/05/2019","No changes"} };
	ColumnFilter::ColumnFilter CF(csv_vector, 2);
	vector<string> expectedColumn = { "good work","modify readme","No changes" };
	REQUIRE(CF.getColumn() == expectedColumn);
}


