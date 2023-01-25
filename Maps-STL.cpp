#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, int> sheet;
    int Q;
    string X;
    int type, Y;
    cin >> Q;
    while (Q--){
        cin >> type;
        switch (type){
        case 1:
            /* code */
            cin >> X >> Y;
            sheet[X] += Y;
            break;
        case 2:
            cin >> X;
            sheet.erase(X);
            break;
        case 3:
            cin >> X;
            cout << sheet[X] << "\n";
            break;
        default:
            break;
        }
    }
    return 0;
}