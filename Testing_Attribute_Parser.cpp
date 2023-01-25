#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int main(){
    string line;
    vector<string> tagStack;
    map<string, string> listing;
    int N, Q;
    cin >> N >> Q;
    // cin.clear();
    cin.ignore();
    for (int i=0; i<N; i++){
        getline(cin, line);
        // if (line.find('/') != line.npos){
        if (line[1] != '/'){
            string tag = line.substr(1, line.find(' ') - 1);
            string name = line.substr(line.find(' ') + 1, line.find('=') - line.find(' ') - 2);
            string value = line.substr(line.find_first_of('"') + 1, line.find_last_of('"') - line.find_first_of('"') - 1);
            tagStack.push_back(tag);
            string query;
            for (auto it : tagStack){
                query += it;
                query.append(".");
            }
            query.erase(query.size()-1);
            query.append("~");
            query += name;
            // cout << "Query = " << query << "\n";
            listing.insert({query, value});
        }
        else{
            tagStack.pop_back();
        }
    }
    
    for (int i=0; i<Q; i++){
        getline(cin, line);
        // cout << line << " ";
        if (listing.find(line) != listing.end()){
            cout << listing[line] << "\n";
        }
        else{
            cout << "Not Found!" << "\n";
        }
    }
    /*
    for (auto it : listing){
        cout << it.first << " = " << it.second << "\n";
    }
    */
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}