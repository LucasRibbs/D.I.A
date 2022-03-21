#include <iostream>
#include <string>

#define MOD 1000000007

using namespace std;

int count_M, count_F;
int count;

int PotenciaMod(int a, int p) {

    if(p==0) return 1;
    if(p%2==1) {
        long long int P = a * PotenciaMod(a,p-1);
        P = P % MOD;
        return P;
    }
    else {
        long long int P = PotenciaMod(a,p/2);
        P = P * P;
        P = P % MOD;
        return P;
    }
}

int NumeroDeCategorias(string HM) {

    count = -1;
    count_M = 0; count_F = 0;

    for(int i=0; i<HM.length(); ++i) {
        if(HM[i] == 'M') ++count_M;
        else if(HM[i] == 'F') ++count_F;

        if(count_M == count_F) {
            ++count;
            count_M = 0; count_F = 0;
        }
    }

    int qtdDeCategorias = PotenciaMod(2,count);

    return qtdDeCategorias;
}

int main() {

    string HM;
    cin >> HM;

    cout << NumeroDeCategorias(HM) << endl;

    return 0;
}