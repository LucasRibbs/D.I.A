#include <iostream>
#include <algorithm>

using namespace std;

int receita[51] = {};

int LucroMaximo(int N, int x[51]) {

    int sm = 0, im = 0, fm = 0;
    int ss = 0, is = 0, fs = 0;

    for(int i=1; i<=N; ++i) {

        if(ss+x[i] >= 0) {

            ss = ss + x[i];
            fs = i;
            if(is == 0) is = i;
            if(ss > sm) sm = ss, im = is, fm = fs;
        }
        else {
            ss = 0, is = 0, fs = 0;
        }
    }

    return sm;
}

int main() {

    int N, custoPorDia;

    while(cin >> N) {

        cin >> custoPorDia;

        for(int i=1; i<=N; ++i) {

            cin >> receita[i];
            receita[i] -= custoPorDia;
        }

        cout << LucroMaximo(N, receita) << endl;
    }

    return 0;
}