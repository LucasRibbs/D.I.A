#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

long long int N;
int fatores[3];

void Fatorar2(long long int N, int fator) {

    int i = fator + 2;

    while(true) {
        
        if(N%i==0) {
            fatores[1] = i;
            fatores[2] = N/i;
            return;
        }
        
        i += 2;
    }
}

void Fatorar1(long long int N) {

    int i = 3;

    while(true) {

        if(N%i==0) {
            fatores[0] = i;
            Fatorar2(N/i, i);
            return;
        }

        i += 2;
    }
}



int main() {

    while(true) {

        cin >> N;

        if(N==0) break;

        Fatorar1(N);

        cout<<N<<" = "<<fatores[0]<<" x "<<fatores[1]<<" x "<<fatores[2]<<endl;
    }

    return 0;
}