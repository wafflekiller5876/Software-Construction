//Calvin Hirschler
//clh0118
//project3_Hirschler_clh0118.cpp
//
//g++ project3_Hirschler_clh0118.cpp -std=c++11 -o a.out
//./a.out
//
//Reads numbers from 2 input files specified by the user
//Sorts the numbers using vectors
//Returns the user an output file

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//attempts to open a file with a filename specified by the user
//returns true or false
bool check_file(string fname){
	ifstream stream;

	stream.open(fname.c_str());
	if (stream.fail()){
		return false;
	}
	stream.close();
	return true;
}

//Reads an input file with numbers in it
//formats the strings to ints and adds them to a vector<int>
//outputs the list of numbers
//returns a vector of ints
vector<int> read_file(string fname){
	ifstream stream;
	stream.open(fname.c_str());

	vector<int> v;
	string line;
	int num = 0, count = 0;

	while (getline(stream, line)){
		count++;
		stringstream(line) >> num; //format str into int
		v.push_back(num); //add num to vector
	}

	cout << "The list of " << count << " numbers in file " << fname << " is:" << endl;
	for (int i : v)
		cout << i << endl;
	cout << endl;
	stream.close();
	return v;
}

//merges two vectors<int> into a sorted vector<int>
//returns sorted vector<int>
vector<int> merge(vector<int> v1, vector<int> v2){
	vector<int> v3, v4;	
	int position, smallest;

	//combines v1 and v2 into a new v3
	for (int i : v1)
		v3.push_back(i);
	for (int i : v2)
		v3.push_back(i);

	//sorts v3 by finding the smallest value and adds it to a new v4
	//inefficient but it works
	int size = v3.size();
	for (int x = 0; x < size; x++){
		smallest = v3[0];
		position = 0;
		for (int i = 0; i < v3.size(); i++){
	
			if (v3[i] < smallest){
				smallest = v3[i];
				position = i;
			}
		}
		v4.push_back(smallest);
		v3.erase(v3.begin() + position);
	}
	//output
	cout << "The sorted list of " << v4.size() << " numbers is: ";
	for (int i : v4)
		cout << i << " ";
	cout << endl;
	return v4;
}

//writes a specified vector<int> into an output file
void write_file(string fname, vector<int> v){
	ofstream stream;
	stream.open(fname.c_str(), ios::out);

	if (!stream.is_open())
		cout << "problem opening file" << endl;
	else{
		for (int i : v) {
			stream << i << endl;
		}
		stream.close();
	}
}

int main() {
	//variables
	string file1 = "", file2 = "", file3 = "";
	vector<int> numbers1, numbers2, numbers3;
	
	//get name of file one
	do {
	cout << "Specify name of file one" << endl;
	cin >> file1; 

	} while (cin.fail() || !check_file(file1));
	
	//get and display numbers from file1
	numbers1 = read_file(file1);
	
	//get name of file two
	do {
	cout << "Specify name of file two" << endl;
	cin >> file2;

	} while (cin.fail() || !check_file(file2));

	//get and display numbers from file2
	numbers2 = read_file(file2);

	//combine vectors and display sorted result
	numbers3 = merge(numbers1, numbers2);

	//get name of output file
	do {
	cout << "Specify name of output file" << endl;
	cin >> file3;

	} while (cin.fail());	
	
	//write combined vector to output file
	write_file(file3, numbers3);
	
	//final goodbye
	cout << "*** Please check the new file - " << file3 << " ***\n";
	cout << "*** Goodbye. ***\n";
}
