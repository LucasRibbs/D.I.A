#include <iostream>
#include <string>

#define MOD 100000007

using namespace std;

int letras[26];

int Inverso(int B) {

    int A=MOD, Q, R, T1=0, T2=1, T;

    while(B!=0) {
        Q = A/B; R = A%B; T=T1-T2*Q;

        A = B; B = R; T1 = T2; T2 = T;
    }

    return (T1<0)?T1+MOD:T1;
}

int Permutacao(int N) {

    long long int P = 1;
    for(int i=2; i<=N; ++i) {
        P = P * i;
        P = P % MOD;
    }

    for(int i=0; i<26; ++i) {
        if(letras[i]>1) {
            
            for(int j=letras[i]; j>1; --j) {
                P = P * Inverso(j);
                P = P % MOD;
            }
        }
    }

    return P;
}

int Anagramas(string palavra) {

    for(int i=0; i<26; ++i) letras[i]=0;
    for(int i=0; i<palavra.length(); ++i) ++letras[palavra[i]-'a'];

    // cout << palavra.length() << endl;
    // for(int i=0; i<26; ++i) cout << letras[i] << ' ';
    // cout << endl;

    return Permutacao(palavra.length());
}

int main() {

    string palavra;

    while(true) {
        cin >> palavra;
        if(palavra.at(0)=='0') break;

        cout << Anagramas(palavra) << endl;
    }    

    return 0;
}