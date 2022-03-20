#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int N;
string M;
int T, A, B;

int MDC(int A, int B) {

    int r;
    while(B!=0) {
        r = A%B;
        A = B;
        B = r;
    }

    return A;
}

int InversoModular(int a, int b) {
    
    vector<int> Pa, Pb;
    Pa.push_back(0); Pb.push_back(0);

    int f;
    int t = 0, x = 1, y = 0;
    int A = a, B = b;

    while(B!=0) {
        ++t;
        Pa.push_back(A); Pb.push_back(B);
        f = A%B; A = B; B = f;
    }
    for(int i=t; i>0; --i) {

        f = y;
        y = x - (Pa[i]/Pb[i])*y;
        x = f;
    }

    x = (x<0) ? x+b : x;
    return x;
}

int Decifrado(int Mi) {

    long long int MI = Mi;

    MI -= B;
    MI *= A;
    Mi = MI % T;

    return (Mi<0)?(Mi+T):Mi;
}

string Decifrar(string M) {

    if(MDC(A,T)!=1) return "DECIFRAGEM AMBIGUA";
    A = InversoModular(A,T);

    int Mi;
    stringstream ss (M);

    stringstream result;

    ss >> Mi;
    result << Decifrado(Mi);

    for(int i=1; i<N; ++i) {

        ss >> Mi;
        result << ' ' << Decifrado(Mi);
    }

    return result.str();
}

int main() {

    cin >> N;
    cin.ignore();

    getline(cin,M);

    cin >> T >> A >> B;

    A %= T; B %= T;

    cout<<Decifrar(M)<<endl;

    return 0;
}