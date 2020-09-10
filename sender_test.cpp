#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include"fileArray.h"
#include"mapFile.h"
#include"ColumnFilter.h"
#include<map>
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
	fout.open("test.csv", ios::out, ios::trunc);
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
	mapFile::vectorToMap vtm;
	vector<string> expectedColumn = { "good", "modify", "readme","" };
	REQUIRE(vtm.pushColumnToVector(1,csv_vector) == expectedColumn);
}

TEST_CASE("when  2D vector of strings"
	"is given then report map with corresponding column of vector strings")
{
	vector<vector<string>> csv_vector = { {"what","good","how"},{"a","modify","nice"},{"great","readme","this"},{"session","","is"} };
	mapFile::vectorToMap vtm;
	map<int, vector<string>> expected_map_vector,returned_map_vector;
	expected_map_vector[1] = { "what","a","great","session" };
	expected_map_vector[2] = { "good","modify","readme","" };
	expected_map_vector[3] = { "how","nice","this","is" };
	returned_map_vector = vtm.mapFileToColumnWise(csv_vector);
	map<int, vector<string>>::iterator expected_map_vector_itr = expected_map_vector.begin();
	map<int, vector<string>>::iterator returned_map_vector_itr = returned_map_vector.begin();
	while (expected_map_vector_itr != expected_map_vector.end())
	{
		REQUIRE(expected_map_vector_itr->first == returned_map_vector_itr->first);
		REQUIRE(expected_map_vector_itr->second == returned_map_vector_itr->second);
		expected_map_vector_itr++;
		returned_map_vector_itr++;

	}
}
TEST_CASE("When map of vector strings and column number"
	"is given as Input then Report the corresponding column vector of strings ")
{
	map<int, vector<string>> sample_map;
	sample_map[1] = { "what","a","great","session" };
	sample_map[2] = { "good","modify","readme","" };
	sample_map[3] = { "how","nice","this","is" };
	columnFilter::columnFilter CF;
	vector<string> expected_column= { "good","modify","readme","" }; 
	REQUIRE(CF.getColumn(sample_map, 2) == expected_column);
}
