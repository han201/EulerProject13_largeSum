// This problem involves reading a file as lines of strings and then convert back and forth between int and string


//Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
// Good enought to read the first 9 digits of each line and sum.

#include <string>
#include <fstream>
#include <typeinfo>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ifstream file("EulerProject13_largeSum.txt");
	long long int total=0;
	long long int totalp = 0;
	long long int totalsum = 0;
	string buffer;
	
	/* 
	//This is a typical way of reading a file for each line 

	while (getline(file, buffer)) {
		cout << buffer << endl;
	}
	*/

	while (getline(file, buffer)) {
		
		string buffer2 = buffer.substr(0, 8);    // long long int supports upto sum of 9 digit numbers
		long long int buffer3 = stoi(buffer2);
		total += buffer3;
		// cout << buffer3 << endl;
				
		string buffer2p = buffer.substr(8, 8);    // note that the second parameter of .substr is the length
		long long int buffer3p = stoi(buffer2p);
		totalp += buffer3p;
		// cout << buffer3p << endl;
		
	}
	totalsum = total * pow(10, 8) + totalp;          // add the two numbers
	// cout << total << endl;
	// cout << totalp << endl;
	// cout << totalsum << endl;
	
	while ((totalsum / 10) > pow(10, 9))             // Get the first 10 digits
		totalsum /= 10;
    cout << totalsum << endl;

	system("pause");
	return 0;
}


	/* 
////////////////////////////GARBAGE COLLECTION : failed attempts
	string a;
	ifstream file("EulerProject13_largeSum_ex.txt");

	string str((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());



	while (!file.eof()) {
	file >> a;
	cout << a << endl;
	}

	long long int maximum = 1;
	int	numOfMul = 13;

	for (int i = 0;i <(outputstring.length() - numOfMul);i++) {
		long long int product = 1;

		for (int j = i; j < i + numOfMul; j++) {
			// cout << typeid(outputstring[j]).name() << endl;
			int x = outputstring[j] - '0';
			product = product *x;
		}
		if (maximum < product) {
			maximum = product;
			for (int k = i;k < i + numOfMul; k++)
				cout << outputstring[k] << endl;
			cout << maximum << endl;
		}

	}
	
	system("pause");
	return 0;
}
*/
