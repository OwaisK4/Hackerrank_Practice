#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str){
    vector<int> numbers;
    stringstream ss(str);
    int num;
    char placeholder;
    while (ss >> num){
        numbers.push_back(num);
        ss >> placeholder;
    }
    return numbers;
	// Complete this function
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}