#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2;
int T[1001][1001] = {0};

int SMC(int i, int j) {

    // int T[i+1][j+1];
    // memset(T,0,sizeof(T));
    // for(int n=0; n<=i; ++n) T[n][0] = 0;
    // for(int m=0; m<=j; ++m) T[0][m] = 0;

    for(int n=1; n<=i; ++n) for(int m=1; m<=j; ++m) {

        if(s1[n-1]==s2[m-1]) T[n][m] = T[n-1][m-1] + 1;
        else T[n][m] = max(T[n-1][m], T[n][m-1]);
    }

    return T[i][j];
}

int main() {

    cin >> s1;
    cin >> s2;

    int smc = SMC(s1.length(),s2.length());
    cout << smc + (s1.length()-smc) + (s2.length()-smc) << endl;

    return 0;
}