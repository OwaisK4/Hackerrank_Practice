#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */

string int_to_string(int number){
    stringstream ss;
    ss << number;
    return ss.str();
}

int string_to_int(string word){
	int number;
    stringstream ss(word);
    ss >> number;
    return number;
}

int main(){
	// int num = 5123;
	// string word = int_to_string(num);
	// cout << word.c_str();
	string word = "5123";
	int number = string_to_int(word);
	cout << number;
	return 0;
}