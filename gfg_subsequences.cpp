// C++ program to count common subsequence in two strings
#include <bits/stdc++.h>
using namespace std;
 
// return the number of common subsequence in
// two strings
int CommonSubsequencesCount(string s, string t){
    int n1 = s.length();
    int n2 = t.length();
    int dp[n1+1][n2+1];
 
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            dp[i][j] = 0;
        }
    }
 
    // for each character of S
    for (int i = 1; i <= n1; i++) {
 
        // for each character in T
        for (int j = 1; j <= n2; j++) {
 
            // if character are same in both
            // the string
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i][j - 1] + dp[i - 1][j];           
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] -
                                        dp[i - 1][j - 1];           
        }
    }
    return dp[n1][n2];
}

void check_subsequence(string original, string check){
    int pos = 0;
    string subsequence;
    for (auto it : original){
        for (int i=pos; i<check.size(); i++){
            // if (tolower(it) == tolower(check[i])){
            if (it == check[i]){
                subsequence += it;
                // pos = i;
                break;
            }
        }
    }
    // cout << subsequence << " " << subsequence.size() << endl;
    cout << subsequence << subsequence.size() << endl;
}
 
// Driver Program
int main(){
    // string s = "ajblqcpdz";
    // string t = "aefcnbtdi";
    string s = "faPkdmElxiyjROOhuFHbaKpmmVAXQcPTiwtCiJC";
    string t = "BVObzwbRESpqhpvjiDGmlVJ";
    // cout << CommonSubsequencesCount(s, t) << endl;
    check_subsequence(s, t);
    return 0;
}