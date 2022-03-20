#include <iostream>

using namespace std;

int N;

int Permutacao(int N, int R) {

    if(N==R) return 1;
    else {
        long long int P = Permutacao(N-1,R);
        P = P * N;
        P = P % 1000000009; /*cout <<"P("<<N<<"): "<< P << endl;*/
        return P;
    }
}

int main() {

    while(true) {

        cin >> N;
        if(N==0) return 0;

        cout<<Permutacao(N,3)<<endl;
    }

    return 0;
}