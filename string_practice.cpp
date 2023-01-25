#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    string word;
    char delimiter = ' ';
    // string name = "Owais Ali Khan";
    string name = "<b value = \"BadVal\" size = \"10\">";
    stringstream ss(name);
    while (getline(ss, word, delimiter)){
        // cout << word << "\n";
    }
    map<string, int> sheet;
    sheet.insert({"owais", 3298});
    cout << sheet["owais"] << "\n";
    cout << sheet["ashar"] << "\n";
    // getline(ss, word, delimiter);
    // cout << word << "\n";
    // getline(cin, name);
    // cout << name;
    // cout << name << "\n";
    // cout << name.substr(0, name.find(' ')) << "\n";
    // cout << name.substr(name.find(' ')+1, name.size()) << "\n";
    // cout << name.npos;
}