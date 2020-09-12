#define CATCH_CONFIG_MAIN
#include"catch.hpp"
#include"fileArray.h"
#include"ColumnFilter.h"

#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

TEST_CASE("when stringstream is given then report it in vector form of string")
{
	string sentence = "hello how are you";
	vector<string>row = { "hello how are you" };
	stringstream s(sentence);
	ifstream fin;
	FileArray::FileArrayCreator ftac(fin);
	REQUIRE(ftac.pushWordsToRowVector(s)== row);

}
TEST_CASE("when an empty csv File is given  then report the file in empty vector")
{
	vector<vector<string>> csv_vector = {};
	ofstream fout;
	fout.open("test1.csv", ios::out | ios::trunc);
	fout.close();
	ifstream fin;
	fin.open("test1.csv", ios::in);
	FileArray::FileArrayCreator ftac(fin);
	REQUIRE(ftac.getFileArray() == csv_vector);


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
	FileArray::FileArrayCreator ftac(fin);
	REQUIRE(ftac.getFileArray() == csv_vector);


}
TEST_CASE("when the column number and 2D vector of strings"
	"are given then report vector with corresponding column of strings")
{
	vector<vector<string>> csv_vector = { {"what","good","how"},{"a","modify","nice"},{"great","readme","this"},{"session","","is"} };
	ColumnFilter::ColumnFilter CF(csv_vector, 2);
	vector<string> expectedColumn = { "good", "modify", "readme","" };
	REQUIRE(CF.getColumn() == expectedColumn);
}


