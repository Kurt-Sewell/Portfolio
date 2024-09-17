#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Problem 1.cpp"
#include "Problem 2.cpp"
#include "Problem 3.cpp"
#include "Problem 4.cpp"
using namespace std;

typedef int(*FnPtr)();

int main() {

	string filename = "Problem ";
	int num;
	map<string, FnPtr> myMap;
	myMap["Problem 1"] = Problem1;
	myMap["Problem 2"] = Problem2;
	myMap["Problem 3"] = Problem3;
	myMap["Problem 4"] = Problem4;

	cout << "Which problem do you want to run? ";
	cin >> num;
	filename.append(to_string(num));
	cout <<"\n" << filename << ": ";
	int res = myMap[filename]();
	
	return 0;
}