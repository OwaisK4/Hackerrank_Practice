#include <cstdio>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int a[1000000];
int x[1000000], y[1000000];
deque<int> dq2;

int main(){
	int T;
    cin >> T;
	while(T--){
		dq2.clear();
		int n, k;
		scanf("%d %d", &n, &k);
		
		for (int i = 0; i < n; i++)
            scanf("%d", a + i);
		
		for (int i = 0; i < k - 1; i++){
			
			while (dq2.size() && a[dq2[dq2.size() - 1]] <= a[i])
                dq2.pop_back();
			dq2.push_back(i);
		}
		
		for (int i = 0, j; (j = i + k - 1) < n; i++){
			while (dq2.size() && a[dq2[dq2.size() - 1]] <= a[j])
                dq2.pop_back();
			dq2.push_back(j);

			y[i] = a[dq2[0]];
			if (dq2[0] == i) dq2.pop_front();
		}
		
		for (int i = 0; i <= n - k; i++) printf("%d%c", y[i], i == n - k ? '\n' : ' ');
	}
	return (0);
}