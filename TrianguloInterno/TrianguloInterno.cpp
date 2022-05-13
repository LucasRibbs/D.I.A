#include <iostream>
#include <cmath>

using namespace std;

int main() {

    long long int s, n, m;
    long long int c1, c2, c3;

    while(true) {

        cin >> s >> n >> m;
        if(s==0 and n==0 and m==0) break;

        cin >> c1 >> c2 >> c3;

        long long int b = abs(c3 - c2);
        long long int res = (s * b * c1) / ((n+1)*(m+1));

        cout << res << endl;
    }

    return 0;
}