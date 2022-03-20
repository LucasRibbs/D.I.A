#include <iostream>

using namespace std;

const int mod = 1000007;
int N;

int Inverso(int B) {

    int A=mod, Q, R, T1=0, T2=1, T;

    while(B!=0) {
        Q = A/B; R = A%B; T=T1-T2*Q;

        A = B; B = R; T1 = T2; T2 = T;
    }

    return (T1<0)?T1+mod:T1;
}

int Combinacao(int N, int P) {

    if(P==0) return 1;
    else {
        long long int C = Combinacao(N-1,P-1); /*cout<<"C("<<N-1<<","<<P-1<<") = "<<C<<endl;*/
        C = C * N; C = C % mod;
        C = C * Inverso(P); C = C % mod;
        return C;
    }
}

int Resultado(int N) {

    int result = N;
    result += 3*Combinacao(N,2); result %= mod;
    result += 3*Combinacao(N,3); result %= mod;
    result += 2*Combinacao(N,4); result %= mod;

    return result;
}

int main() {

    while(true) {

        cin >> N;
        if(N==0) return 0;

        cout << Resultado(N) << endl;
        // cout << (Combinacao(N,4) * 36 % mod) << endl;
    }

    return 0;
}