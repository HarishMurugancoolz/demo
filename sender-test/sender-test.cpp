#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include"fileArray.h"
#include"ColumnFilter.h"

#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

TEST_CASE("when stringstream is given then report it in vector")
{
	string sentence = "hello how are you";
	vector<string>row = { "hello how are you" };
	stringstream s(sentence);
	FileArray::FileToArrayCreator ftac;
	REQUIRE(ftac.pushWordsToRowVector(s)== row);

}
TEST_CASE("when csv File is given  then report the file in vector form" )
{
	vector<vector<string>> csv_vector = { {"what","good","how"},{"a","modify","nice"},{"great","readme","this"},{"session","","is"} };
	ofstream fout;
	fout.open("test.csv", ios::out|ios::trunc);
	fout << "what" << ",";
	fout << "good" <<"," ;
	fout << "how";
	fout << "\n";
	fout << "a" << ",";
	fout << "modify" << ",";
	fout << "nice";
	fout << "\n";
	fout << "great" << ",";
	fout << "readme" << ",";
	fout << "this";
	fout << "\n";
	fout << "session" << ",";
	fout << "" << ",";
	fout << "is";
	fout << "\n";
	fout.close();
	ifstream fin;
	fin.open("test.csv", ios::in);
	FileArray::FileToArrayCreator ftac;
	REQUIRE(ftac.createFileArray(fin) == csv_vector);


}
TEST_CASE("when the column number and 2D vector of strings"
	"are given then report vector with corresponding column of strings")
{
	vector<vector<string>> csv_vector = { {"what","good","how"},{"a","modify","nice"},{"great","readme","this"},{"session","","is"} };
	columnFilter::columnFilter CF;
	vector<string> expectedColumn = { "good", "modify", "readme","" };
	REQUIRE(CF.getColumn(csv_vector,2) == expectedColumn);
}


