#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    int i, j, k;
    int **array = new int*[n];
    for (int i=0; i<n; i++){
        cin >> k;
        array[i] = new int[k];
        for (int j=0; j<k; j++){
            cin >> array[i][j];
        }
    }
    for (int a=0; a<q; a++){
        cin >> i >> j;
        printf("%d\n", array[i][j]);
    }
    return 0;
}