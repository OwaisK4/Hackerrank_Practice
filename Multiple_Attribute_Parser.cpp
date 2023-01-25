#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
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
            stringstream ss(line);
            string word;
            char delimiter = ' ';
            while (getline(ss, word, delimiter)){
                if (word[0] == '<'){
                    string tag = word.substr(1, word.npos);
                    if (tag[tag.size()-1] == '>')
                        tag.erase(tag.size() - 1);
                    tagStack.push_back(tag);
                }
                else if (word == "="){
                    continue;
                }
                else if (word[0] == '"'){
                    continue;                    
                }
                else{
                    string query;
                    string value;
                    for (auto it : tagStack){
                        query += it;
                        query.append(".");
                    }
                    query.erase(query.size()-1);
                    query.append("~");
                    query += word;
                    getline(ss, value, delimiter);
                    getline(ss, value, delimiter);
                    if (word == value){         // If tag does not contain an attribute
                        continue;
                    }
                    if (value[value.size() - 1] == '>'){
                        value.erase(value.size() - 1);
                    }
                    value.erase(0, 1);
                    value.erase(value.size() - 1);
                    // cout << "Query = " << query << "\n";
                    listing.insert({query, value});
                }
            }
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