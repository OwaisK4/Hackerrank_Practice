#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
    while (T--){
    	double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        /* Enter your code here */
        int a = A;
        cout << left << resetiosflags(ios_base::dec | ios::uppercase) << setiosflags(ios_base::hex | ios_base::showbase) << a << "\n";
        cout << resetiosflags(ios_base::hex | ios_base::showbase) << setiosflags(ios_base::dec);
        // printf("0x%x\n", a);
        
        // cout << setfill('_') << setw(15) << B << "\n";
        cout << fixed;
        cout << setprecision(2) << right << setfill('_') << setw(15) << setiosflags(ios::showpos) << B << "\n";
        cout << resetiosflags(ios::showpos);

        // cout << setprecision(9) << scientific << C << "\n";
        cout << scientific;
        cout << setprecision(9) << left << setiosflags(ios_base::scientific | ios_base::uppercase) << C << "\n";
        cout << resetiosflags(ios_base::scientific);
        // printf("%9E\n", C);
    }
	return 0;
}