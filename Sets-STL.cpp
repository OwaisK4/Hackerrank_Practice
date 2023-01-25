#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    set<int> s;
    int Q;
    int X, Y;
    // string line;
    cin >> Q;
    // cin.ignore();
    while (Q--){
        // getline(cin, line);
        cin >> Y >> X;
        switch (Y){
            case 1:
                s.insert(X);
                break;
            case 2:
                if (s.find(X) != s.end())
                    s.erase(X);
                break;
            case 3:
                if (s.find(X) != s.end())
                    cout << "Yes" << "\n";
                else
                    cout << "No" << "\n";
                break;
            default:
                break;
        }
    }
    return 0;
}