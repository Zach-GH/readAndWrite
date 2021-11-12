/*
Zachary Meisner
Reading and Writing Files
CS210
11/12/21
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace  std;

int main() {

	fstream oldFile;
	fstream newFile;
	oldFile.open("FahrenheitTemperature.txt", ios::in); // open file to read
	if (oldFile.is_open()) { // checks to make sure the file is open
		string line; // declares a variable to store text
		int Fahrenheit; // stores number
		newFile.open("CelsiusTemperature.txt", ios::out); // opens new file to write
		while (getline(oldFile, line, ' ')) { // reads from old file and stores in line end at ' ' character
			oldFile >> Fahrenheit; // gets number from line
			int Celsius = 5 * (Fahrenheit - 32) / 9; // Change Fahrenheit to Celsius
			if (newFile.is_open()) { // checks to make sure newFile is open
				newFile << line << " " << Celsius << endl; // writes changed Data to new file
			}
		}
		newFile.close(); // close new file
		}
		oldFile.close(); // closes old file

	newFile.open("CelsiusTemperature.txt", ios::in); // checking new File for program efficiency
	if (newFile.is_open()) {
		string newLine;
		while (getline(newFile, newLine)) {
			cout << newLine << endl;
		}
		newFile.close();
	}
		return 0;

	}